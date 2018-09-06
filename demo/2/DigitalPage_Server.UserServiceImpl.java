package com.fasoo.note.member.service;


import java.io.File;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.ZoneOffset;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Random;
import java.util.UUID;

import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.client.RestTemplate;

import com.fasoo.note.Constant;
import com.fasoo.note.WebConfig;
import com.fasoo.note.api.mapper.EmailLogMapper;
import com.fasoo.note.api.mapper.GeoPlaceMapper;
import com.fasoo.note.api.mapper.InitNoteResourceMapper;
import com.fasoo.note.api.mapper.LocationInlineTagMapper;
import com.fasoo.note.api.mapper.LocationInlineTagRelationMapper;
import com.fasoo.note.api.mapper.NoteMapper;
import com.fasoo.note.api.mapper.ProductMapper;
import com.fasoo.note.api.mapper.ResourceMapper;
import com.fasoo.note.api.mapper.ScheduleMapper;
import com.fasoo.note.api.mapper.TagMapper;
import com.fasoo.note.api.mapper.TagRelationMapper;
import com.fasoo.note.api.mapper.TodoMapper;
import com.fasoo.note.bean.api.EmailLog;
import com.fasoo.note.bean.api.GeoPlace;
import com.fasoo.note.bean.api.InitNoteResource;
import com.fasoo.note.bean.api.LocationInlineTag;
import com.fasoo.note.bean.api.LocationInlineTagRelation;
import com.fasoo.note.bean.api.Note;
import com.fasoo.note.bean.api.NoteAttribute;
import com.fasoo.note.bean.api.NoteBody;
import com.fasoo.note.bean.api.Product;
import com.fasoo.note.bean.api.Resource;
import com.fasoo.note.bean.api.ResourceAttribute;
import com.fasoo.note.bean.api.Schedule;
import com.fasoo.note.bean.api.Tag;
import com.fasoo.note.bean.api.TagRelation;
import com.fasoo.note.bean.api.Todo;
import com.fasoo.note.bean.communication.JsonResult;
import com.fasoo.note.bean.member.AccountInfo;
import com.fasoo.note.bean.member.DeleteAccount;
import com.fasoo.note.bean.member.InitNote;
import com.fasoo.note.bean.member.Token;
import com.fasoo.note.bean.member.User;
import com.fasoo.note.bean.search.NoteSearch;
import com.fasoo.note.bean.storage.AWSInfo;
import com.fasoo.note.bean.web.LocationInlineTagWeb;
import com.fasoo.note.bean.web.ResourceWeb;
import com.fasoo.note.bean.web.TagWeb;
import com.fasoo.note.bean.web.TodoWeb;
import com.fasoo.note.common.aws.AmazonS3FileService;
import com.fasoo.note.common.enumtype.AccessToken;
import com.fasoo.note.common.enumtype.EntryType;
import com.fasoo.note.common.enumtype.EventLogId;
import com.fasoo.note.common.enumtype.GuestType;
import com.fasoo.note.common.enumtype.InitNoteResourceObjectType;
import com.fasoo.note.common.enumtype.InitNoteType;
import com.fasoo.note.common.enumtype.LinkStatus;
import com.fasoo.note.common.enumtype.NoteSearchBatchType;
import com.fasoo.note.common.enumtype.NoteType;
import com.fasoo.note.common.enumtype.OfferLocationInfoStatus;
import com.fasoo.note.common.enumtype.Privilege;
import com.fasoo.note.common.enumtype.ProductType;
import com.fasoo.note.common.enumtype.PushEvent;
import com.fasoo.note.common.enumtype.SnsType;
import com.fasoo.note.common.exception.AuthorizedFailException;
import com.fasoo.note.common.exception.DBInsertException;
import com.fasoo.note.common.exception.InvalidPasswordException;
import com.fasoo.note.common.exception.RequiredParameterException;
import com.fasoo.note.common.exception.ResourceNotFoundException;
import com.fasoo.note.common.exception.ResourceUnmodifiableException;
import com.fasoo.note.common.log.Rogger;
import com.fasoo.note.common.log.RoggerFactory;
import com.fasoo.note.common.util.CryptoUtil;
import com.fasoo.note.common.util.ProfileImageUtil;
import com.fasoo.note.common.util.TimeUtil;
import com.fasoo.note.eventlog.service.EventLogService;
import com.fasoo.note.member.bean.communication.UserData;
import com.fasoo.note.member.mapper.AccountInfoMapper;
import com.fasoo.note.member.mapper.DeleteAccountMapper;
import com.fasoo.note.member.mapper.InitNoteMapper;
import com.fasoo.note.member.mapper.TokenMapper;
import com.fasoo.note.member.mapper.UserMapper;
import com.fasoo.note.push.manager.PushManager;
import com.fasoo.note.search.mapper.NoteSearchBatchMapper;
import com.fasoo.note.storage.mapper.BucketMapper;
import com.fasoo.note.storage.util.BucketUtil;


@Service
public class UserServiceImpl implements UserService {

    @Autowired
    private UserMapper userMapper;

    @Autowired
    private TokenMapper tokenMapper;

    @Autowired
    private ProductMapper productMapper;

    @Autowired
    private AccountInfoMapper accountInfoMapper;

    @Autowired
    private EmailLogMapper emailLogMapper;

    @Autowired
    private DeleteAccountMapper deleteAccountMapper;

    @Autowired
    private InitNoteMapper initNoteMapper;

    @Autowired
    private InitNoteResourceMapper initNoteResourceMapper;

    @Autowired
    private NoteMapper noteMapper;

    @Autowired
    private BucketUtil allocateBucketUtil;

    @Autowired
    private SynoIndexService synoIndexService;

    @Autowired
    private NoteSearchBatchMapper noteSearchBatchMapper;

    @Autowired
    private ResourceMapper resourceMapper;

    @Autowired
    private TagRelationMapper tagRelationMapper;

    @Autowired
    private TagMapper tagMapper;

    @Autowired
    private TodoMapper todoMapper;

    @Autowired
    private ScheduleMapper scheduleMapper;

    @Autowired
    private BucketMapper bucketMapper;

    @Autowired
    private GeoPlaceMapper geoPlaceMapper;

    @Autowired
    private LocationInlineTagMapper locationInlineTagMapper;

    @Autowired
    private LocationInlineTagRelationMapper locationInlineTagRelationMapper;

    @Autowired
    private EventLogService eventLogService;

    private final Rogger rogger = RoggerFactory.getRogger(UserServiceImpl.class);

    private static final String DEF_FORMAT_BY_YYYYMM = "yyyyMM";

    @Autowired
    private RestTemplate restTemplate;

    private PushManager pushManager = PushManager.getInstance();


    @Override
    @Transactional
    @Deprecated
    public JsonResult createUser(User user, String clientIp, int browserType) throws Exception {

        if (user.getEmail().isEmpty() == true) {
            throw new RequiredParameterException("Email is empty.");
        }

        user.setPrivilege(Privilege.NORMAL.getValue());
        if (StringUtils.isEmpty(user.getLocale()) == true) {
            user.setLocale(Constant.DEFAULT_LOCALE);
        }
        if (StringUtils.isEmpty(user.getTimezone()) == true) {
            user.setTimezone(Constant.DEFAULT_TIME_ZONE);
        }

        rogger.debug("Call the insert user.");

        // 사용자 Locale에 따라서 버킷 ID 값 할당.
        long bucketId = allocateBucketUtil.getBucketId(user.getLocale());
        user.setBucketId(bucketId);
        if (user.getSnsType() == 0) {
            user.setEmailActivateState("N");
        } else {
            user.setEmailActivateState("Y");
        }
        int affectedRows = 0;
        try {
            affectedRows = userMapper.insertUser(user);
        } catch (Exception e) {
            throw new DBInsertException("DB Insert Error");
        }
        Product product = productMapper.selectProductById(ProductType.BASIC.getValue());
        AccountInfo accountInfo = new AccountInfo(user.getId(), product);

        affectedRows += accountInfoMapper.insertAccountInfo(accountInfo);

        // TODO : 정책 리비전 관련 사항 적용 필요 (kimty0)

        // 초기 노트 insert
        createInitNote(user);

        String accessTokenValue = null;

        /*
        if (user.getSnsType() != 0) {
            Token token = new Token();
            accessTokenValue = CryptoUtil.hashString(UUID.randomUUID().toString());
            token.setUserId(user.getId());
            token.setType(1);
            token.setValue(accessTokenValue);
            token.setStatus(AccessToken.STATUS_ACTIVE.getStatus());

            tokenMapper.insertToken(token);
        }
        */

        // 이메일 인증 절차가 사라졌기 때문에 SNS 타입과 무관하게 바로 토큰 생성
        Token token = new Token();
        accessTokenValue = CryptoUtil.hashString(UUID.randomUUID().toString());
        token.setUserId(user.getId());
        token.setType(1);
        token.setValue(accessTokenValue);
        token.setStatus(AccessToken.STATUS_ACTIVE.getStatus());

        tokenMapper.insertToken(token);

        insertEventLog(EventLogId.SIGN_IN, user.getId());

        return new JsonResult(user.getId(), 0, affectedRows, accessTokenValue);
    }


    @Override
    @Transactional
    public JsonResult newerCreateUser(User user, String clientIp, int browserType) throws Exception {
        if (user.getEmail().isEmpty() == true) {
            throw new RequiredParameterException("Email is empty.");
        }

        user.setPrivilege(Privilege.NORMAL.getValue());
        if (StringUtils.isEmpty(user.getLanguage()) == true) {
            user.setLanguage(Constant.DEFAULT_LANGUAGE);
        }
        if (StringUtils.isEmpty(user.getCountry()) == true) {
            user.setCountry(Constant.DEFAULT_COUNTRY);
        }
        if (StringUtils.isEmpty(user.getTimezone()) == true) {
            user.setTimezone(Constant.DEFAULT_TIME_ZONE);
        }

        user.setLocale(user.getCountry());

        rogger.debug("Call the insert user.");

        // 사용자 Locale에 따라서 버킷 ID 값 할당.
        long bucketId = allocateBucketUtil.getBucketId(user.getCountry());
        user.setBucketId(bucketId);
        if (user.getSnsType() == SnsType.WISEVINE.getValue()) {
            user.setEmailActivateState("N");
        } else {
            user.setEmailActivateState("Y");
        }
        int affectedRows = 0;
        try {
            affectedRows = userMapper.insertUser(user);
        } catch (Exception e) {
            throw new DBInsertException("DB Insert Error");
        }
        Product product = productMapper.selectProductById(ProductType.BASIC.getValue());
        AccountInfo accountInfo = new AccountInfo(user.getId(), product);

        // DigitalPage 회원 가입인 경우 약관동의 한 것으로 보고 SNS 가입인 경우는 추 후 동의 받기 위함
        if (user.getSnsType() == SnsType.WISEVINE.getValue()) {
            accountInfo.setOfferLocationInfoStatus(OfferLocationInfoStatus.ACCEPT.getStatus());
        } else {
            accountInfo.setOfferLocationInfoStatus(OfferLocationInfoStatus.DEFAULT.getStatus());
        }

        if (user.getSnsType() == SnsType.KAKAOTALK.getValue()) {
            accountInfo.setRepresentEmail(user.getRepresentEmail());
        }

        affectedRows += accountInfoMapper.insertAccountInfo(accountInfo);

        // TODO : 정책 리비전 관련 사항 적용 필요 (kimty0)

        // 초기 노트 insert (일반 회원 가입인 경우에만 초기노트 생성)
        if (user.getGuestType() == GuestType.NORMAL.getType()) {
            createInitNote(user);
        }

        String accessTokenValue = null;

        /*
        if (user.getSnsType() != SnsType.WISEVINE.getValue()) {
            Token token = new Token();
            accessTokenValue = CryptoUtil.hashString(UUID.randomUUID().toString());
            token.setUserId(user.getId());
            token.setType(1);
            token.setValue(accessTokenValue);
            token.setStatus(AccessToken.STATUS_ACTIVE.getStatus());

            tokenMapper.insertToken(token);
            rogger.info("test0");
        }
        */

        // 이메일 인증 절차가 사라졌기 때문에 SNS 타입과 무관하게 바로 토큰 생성
        Token token = new Token();
        accessTokenValue = CryptoUtil.hashString(UUID.randomUUID().toString());
        token.setUserId(user.getId());
        token.setType(1);
        token.setValue(accessTokenValue);
        token.setStatus(AccessToken.STATUS_ACTIVE.getStatus());

        tokenMapper.insertToken(token);

        insertEventLog(EventLogId.SIGN_IN, user.getId());

        return new JsonResult(user.getId(), 0, affectedRows, accessTokenValue);
    }


    @Override
    public UserData getUserByUserId(long userId) throws Exception {

        User user = userMapper.selectUserByUserId(userId);
        AccountInfo accountInfo = accountInfoMapper.selectAccountInfo(userId);

        if (StringUtils.isEmpty(accountInfo.getRepresentEmail()) && user.getSnsType() != SnsType.KAKAOTALK.getValue()) {
            accountInfo.setRepresentEmail(user.getEmail());
        }

        if (user == null || accountInfo == null) {
            return null;
        }

        AWSInfo awsInfo = allocateBucketUtil.getAWSInfo(user.getBucketId());

        return new UserData(user, accountInfo, awsInfo);
    }


    @Override
    public UserData getUserByEmail(String email) throws Exception {
        User user = userMapper.selectUserByEmail(email);

        if (user == null) {
            return null;
        }

        AccountInfo accountInfo = accountInfoMapper.selectAccountInfo(user.getId());

        if (accountInfo == null) {
            throw new ResourceNotFoundException("AccountInfo resource not found");
        }

        AWSInfo awsInfo = allocateBucketUtil.getAWSInfo(user.getBucketId());

        return new UserData(user, accountInfo, awsInfo);
    }


    @Override
    public UserData getUserByEmail(String email, int snsType) throws Exception {
        User user = userMapper.selectUserByEmailAndSnsType(email, snsType);

        if (user == null) {
            return null;
        }

        AccountInfo accountInfo = accountInfoMapper.selectAccountInfo(user.getId());

        if (accountInfo == null) {
            throw new ResourceNotFoundException("AccountInfo resource not found");
        }

        AWSInfo awsInfo = allocateBucketUtil.getAWSInfo(user.getBucketId());

        return new UserData(user, accountInfo, awsInfo);

    }


    @Override
    @Transactional
    public JsonResult activateAccount(String email, String emailKey, String clientIp, int browserType) throws Exception {

        EmailLog emailLog = emailLogMapper.selectEmailLogByEmailKey(emailKey);
        if (emailLog == null || !emailLog.getReceiverEmail().equals(email)) {
            throw new ResourceNotFoundException("UserController - activeAccount : Email Data.");
        }
        User user = userMapper.selectUserByEmail(email);
        if (user == null || user.getId() != emailLog.getUserId()) {
            throw new ResourceNotFoundException("UserController - activeAccount : Email Data.");
        }
        if (user.getEmailActivateState().equals("Y")) {
            throw new RequiredParameterException("UserController - activeAccount : Already Activated Email Data.");
        }

        int affectedRows = userMapper.updateEmailActivateY(email);
        affectedRows += emailLogMapper.updateEmailLinkStatus(emailLog.getId(), LinkStatus.USED.getValue());

        return new JsonResult(user.getId(), 0, affectedRows);
    }


    @Override
    @Transactional
    public JsonResult modifyUser(User user, String clientIp, int browserType) throws Exception {

        String emailKey = user.getEmailKey();
        EmailLog emailLog = null;
        if (!StringUtils.isEmpty(emailKey)) {
            emailLog = emailLogMapper.selectEmailLogByEmailKey(emailKey);
            if (emailLog == null) {
                throw new ResourceNotFoundException("EmailLog Not Found");
            }
        }

        User userObj = userMapper.selectUserByEmail(user.getEmail());
        if (user.getId() != userObj.getId()) {
            user.setId(userObj.getId());
        }

        User oldUser = userMapper.selectUserByUserId(user.getId());
        if (oldUser == null) {
            throw new ResourceNotFoundException("Userdata Not Found");
        }
        if (!StringUtils.equals(oldUser.getEmail(), user.getEmail())) {
            throw new AuthorizedFailException("Not Equals AccessToken And Email");
        }

        String newPassword = user.getNewPassword();
        if (!StringUtils.isBlank(newPassword)) {
            User checkUser = userMapper.selectUserByEmailAndPassword(user.getEmail(), user.getPassword());
            if (checkUser == null || newPassword.compareTo(user.getConfirmPassword()) != 0) {
                throw new InvalidPasswordException("Modify User Password Invalidate");
            }
        }

        String newEmail = user.getNewEmail();
        if (!StringUtils.isBlank(newEmail)) {
            User checkUser = userMapper.selectUserByEmail(newEmail);
            if (checkUser != null) {
                throw new ResourceUnmodifiableException("Email Address Duplicated");
            }
            checkUser = userMapper.selectUserByUserIdAndPassword(user.getId(), user.getPassword());
            if (checkUser == null) {
                throw new InvalidPasswordException("Modify User Password Invalidate");
            }

            if (StringUtils.equalsIgnoreCase(checkUser.getEmailActivateState(), "N")) {
                // 이메일 변경에 따른 인증 시 Activate
                userMapper.updateEmailActivateY(checkUser.getEmail());
            }

        }

        int affectedRows = userMapper.updateUserByUser(user);
        if (affectedRows == 0) {
            throw new ResourceUnmodifiableException();
        }

        // 암호 또는 이메일을 변경 하면 기존 accessToken을 만료시키고 다시 생성
        String accessTokenValue = null;
        if (!StringUtils.isBlank(user.getNewPassword()) || !StringUtils.isBlank(user.getNewEmail())) {

            accessTokenValue = CryptoUtil.hashString(UUID.randomUUID().toString());

            tokenMapper.expireTokenByUserId(user.getId());

            Token token = new Token();
            token.setUserId(user.getId());
            token.setType(1);
            token.setValue(accessTokenValue);
            token.setStatus(AccessToken.STATUS_ACTIVE.getStatus());

            tokenMapper.insertToken(token);

            pushManager.pushEvent(PushEvent.CHANGE_PASSWORD.getEventId(), user.getId(), 1);
        }

        // TODO : 정책 리비전 관련 사항 적용 필요 (kimty0)

        if (emailLog != null) {
            emailLogMapper.updateEmailLinkStatus(emailLog.getId(), LinkStatus.USED.getValue());
        }

        rogger.error(accessTokenValue);

        return new JsonResult(user.getId(), 0, affectedRows, accessTokenValue);
    }


    @Override
    public JsonResult modifyProfileImageUrl(User user, String clientIp, int browserType) throws Exception {

        User userObj = userMapper.selectUserByUserId(user.getId());
        if (userObj == null) {
            throw new ResourceNotFoundException("Change Profile Image User didn't Search.");
        }

        AccountInfo targetAccontInfo = accountInfoMapper.selectAccountInfo(user.getId());
        String currentProfileImageUrl = targetAccontInfo.getProfileImageUrl();
        int affectedRows = 0;

        String newProfileImageUrl = user.getProfileImageUrl();
        if (StringUtils.isEmpty(newProfileImageUrl)) {
            newProfileImageUrl = null;
        }

        if (!StringUtils.equals(currentProfileImageUrl, newProfileImageUrl)) {
            AccountInfo updateAccountInfo = new AccountInfo();
            updateAccountInfo.setUserId(user.getId());
            updateAccountInfo.setProfileImageUrl(newProfileImageUrl);

            affectedRows = accountInfoMapper.updateProfileImage(updateAccountInfo);

            if (!StringUtils.isEmpty(currentProfileImageUrl)) {
                ProfileImageUtil.deleteCurrentProfileImage(currentProfileImageUrl);
            }
        }

        return new JsonResult(user.getId(), 0, affectedRows);
    }


    @Override
    @Transactional
    public JsonResult changePassword(User user, String clientIp, int browserType) throws Exception {

        User existUser = userMapper.selectUserByEmail(user.getEmail());
        if (existUser == null) {
            throw new ResourceNotFoundException("Change Password User didn't Search.");
        }

        EmailLog emailLog = emailLogMapper.selectEmailLogByEmailKey(user.getEmailKey());
        if (emailLog == null || !emailLog.getReceiverEmail().equals(user.getEmail())) {
            throw new ResourceNotFoundException("Didn't Search the EmailLog.");
        }

        int affectedRows = userMapper.updatePasswordByEmail(user);
        if (affectedRows == 0) {
            throw new ResourceUnmodifiableException("Change Password Fail.");
        }
        tokenMapper.expireTokenByUserId(user.getId());

        // TODO : 정책 리비전 관련 사항 적용 필요 (kimty0)

        emailLogMapper.updateEmailLinkStatus(emailLog.getId(), LinkStatus.USED.getValue());

        // 푸시 메시지 발송
        try {
            pushManager.pushEvent(PushEvent.CHANGE_PASSWORD.getEventId(), existUser.getId(), 1);
        } catch (Exception e) {
            rogger.error("change password reset push fail!!", e);
        }

        return new JsonResult(user.getId(), 0, affectedRows);
    }


    @Override
    public User getUser(String email) throws Exception {

        return userMapper.selectUserByEmail(email);
    }


    @Override
    @Transactional
    public int removeUser(long userId, String password, String reason) throws InvalidPasswordException {

        User myInfo = userMapper.selectUserByUserIdAndPassword(userId, password);
        if (myInfo == null) {
            throw new InvalidPasswordException();
        }

        DeleteAccount deleteAccount = new DeleteAccount();
        deleteAccount.setUserId(userId);
        deleteAccount.setEmail(myInfo.getEmail());
        deleteAccount.setReason(reason);
        deleteAccount.setDeleteStatus(false);

        int affectedRow = deleteAccountMapper.insertDeleteAccount(deleteAccount);

        if (affectedRow > 0) {
            tokenMapper.expireTokenByUserId(userId);
        }

        return affectedRow;
    }


    @Override
    public DeleteAccount getDeleteAccountByUserId(long userId) {
        return deleteAccountMapper.selectBeforeDeleteAccountByUserId(userId);
    }


    @Override
    @Transactional
    public int removeUser(long userId, int snsType, String reason) throws InvalidPasswordException {
        User myInfo = userMapper.selectUserByUserIdAndSnsType(userId, snsType);
        if (myInfo == null) {
            throw new InvalidPasswordException();
        }

        DeleteAccount deleteAccount = new DeleteAccount();
        deleteAccount.setUserId(userId);
        deleteAccount.setEmail(myInfo.getEmail());
        deleteAccount.setReason(reason);
        deleteAccount.setDeleteStatus(false);

        int affectedRow = deleteAccountMapper.insertDeleteAccount(deleteAccount);

        if (affectedRow > 0) {
            tokenMapper.expireTokenByUserId(userId);
            // 카카오톡 회원의 경우 탈퇴 시 앱 연결 해제 필요.
            if (myInfo.getSnsType() == SnsType.KAKAOTALK.getValue()) {
                HttpHeaders headers = new HttpHeaders();
                headers.set("Authorization", "KakaoAK " + WebConfig.getString("kakao.admin.key"));
                HttpEntity<String> requestEntity = new HttpEntity<String>(headers);
                ResponseEntity<JsonResult> responseEntity = restTemplate.exchange("https://kapi.kakao.com/v1/user/unlink?target_id_type=user_id&target_id=" + myInfo.getEmail(),
                                                                                  HttpMethod.POST, requestEntity, JsonResult.class);
                JsonResult jsonResult = responseEntity.getBody();
                rogger.info(String.valueOf(jsonResult.getId()));
            }
        }

        return affectedRow;
    }


    @Override
    public UserData getUserByPassword(long userId, String password) throws Exception {

        User user = userMapper.selectUserByUserIdAndPassword(userId, password);

        if (user == null) {
            return null;
        }

        AccountInfo accountInfo = accountInfoMapper.selectAccountInfo(user.getId());

        if (accountInfo == null) {
            throw new ResourceNotFoundException("AccountInfo resource not found");
        }

        AWSInfo awsInfo = allocateBucketUtil.getAWSInfo(user.getBucketId());

        return new UserData(user, accountInfo, awsInfo);
    }


    @Override
    public JsonResult acceptOfferLocationInfo(long userId) throws Exception {

        User user = userMapper.selectUserByUserId(userId);
        if (user == null) {
            throw new ResourceNotFoundException("Accept offerLocationInfo User didn't Search.");
        }

        int affectedRow = accountInfoMapper.updateOfferLocationInfoStatus(userId, OfferLocationInfoStatus.ACCEPT.getStatus());

        return new JsonResult(user.getId(), 0, affectedRow);
    }


    @Override
    public JsonResult modifySnsUserName(User user, String clientIp, int browserType) throws Exception {

        int affectedRows = userMapper.updateUserNameByIdAndName(user.getId(), user.getName());

        return new JsonResult(user.getId(), affectedRows);
    }


    @Override
    public JsonResult modifySnsUserEmail(User user, String clientIp, int browserType) throws Exception {

        int affectedRows = accountInfoMapper.updateRepresentEmailByUserId(user.getId(), user.getNewEmail());

        return new JsonResult(user.getId(), affectedRows);
    }


    @Override
    public List<GeoPlace> createGeoPlace(long userId, GeoPlace[] geoPlaces) {

        List<GeoPlace> returnList = new ArrayList<GeoPlace>();

        List<GeoPlace> geoPlaceList = Arrays.asList(geoPlaces);

        for (GeoPlace geoPlace : geoPlaceList) {

            geoPlace.setUserId(userId);
            GeoPlace insertedGeoPlace = geoPlaceMapper.selectGeoPlaceByUserIdAndAddress(geoPlace.getUserId(), geoPlace.getAddress());
            if (insertedGeoPlace != null) {
                continue;
            }

            int affectedRow = geoPlaceMapper.insertGeoPlace(geoPlace);

            if (affectedRow > 0) {
                returnList.add(geoPlace);
            }
        }

        return returnList;
    }


    @Override
    public List<GeoPlace> getGeoPlaceList(long userId) {
        return geoPlaceMapper.selectGeoPlaceByUserId(userId);
    }


    private final String getAmazonResourcePath(String noteGuid, long userId) {

        int seed = new Random().nextInt(Constant.MAX_SEED_NUM); // range [0, n) 이므로 65536;
        String pathPrefix = String.format("%04x", seed);
        StringBuilder sb = new StringBuilder();

        sb.append(pathPrefix);
        sb.append("/");
        sb.append(CryptoUtil.hashStringToHexString(Long.toString(userId)));
        sb.append("/");
        sb.append(noteGuid);
        sb.append("/");

        return sb.toString();
    }


    private void insertEventLog(EventLogId eventLogId, long userId) {
        eventLogService.createEventLog(eventLogId, userId);
    }


    private void createInitNote(User user) throws ResourceNotFoundException {

    	// 이전 방식의 회원 가입을 통해 Language 값이 아닌 Locale의 Country 값으로 사용자의 언어를 판단.
        if (StringUtils.isEmpty(user.getLanguage()) == true) {

            if (user.getLocale().equalsIgnoreCase(Locale.KOREA.getCountry())) {
            	makeNewIntroductionKorInitNote(user);
            } else {
            	makeNewIntroductionEngInitNote(user);
            }

        } else { // 신규 방식의 회원 가입을 통해 Language 값으로 사용자의 언어를 판단.

            if (user.getLanguage().equalsIgnoreCase(Locale.KOREA.getLanguage())) {
            	makeNewIntroductionKorInitNote(user);
            } else {
            	makeNewIntroductionEngInitNote(user);
            }
        }
        
        makeTourSampleInitNote(user);
    }
    
    private void makeNewIntroductionKorInitNote(User user) throws ResourceNotFoundException {
    	
		String[] resourceHashValues = new String[] { "4f966289091f00667f68d2b2a8a676179d06ed77",
				"6d6f9b8b0fa664b92d368af85c9a08b8b05f661e", "971271aad01ded9cb244f0aa58d3448677f6530d",
				"d926d5ce461bc8c6174c1ded2497c8b88141a846", "025711b07d0af0b4ea1393b3d534314d4f338838" };
        long[] resourceSizeValues = new long[] { 20723, 18899, 174042, 112105, 27009 };
        String folderName = "new_init_note_image/";

        InitNote initNote = initNoteMapper.selectInitNoteByLocale(InitNoteType.INTRODUCTION.getValue(), "KR");

        if (initNote != null) {

            // 노트 guid 생성
            String noteGuid = UUID.randomUUID().toString();

            // 각 이미지 리소스 패스 생성
            String imgTumbName = "1p_thumb.jpg";
            String img1Name = "1p_1.jpg";
            String img2Name = "1p_2.jpg";
            String img3Name = "1p_3.jpg";
            String img4Name = "1p_4.jpg";

            StringBuilder imgThumbPath = new StringBuilder();
            imgThumbPath.append(getAmazonResourcePath(noteGuid, user.getId()));
            imgThumbPath.append(imgTumbName);

            StringBuilder img1Path = new StringBuilder();
            img1Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img1Path.append(img1Name);
            
            StringBuilder img2Path = new StringBuilder();
            img2Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img2Path.append(img2Name);
            
            StringBuilder img3Path = new StringBuilder();
            img3Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img3Path.append(img3Name);
            
            StringBuilder img4Path = new StringBuilder();
            img4Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img4Path.append(img4Name);

            // 노트 생성
            long afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.NOTE_UPDATE.getType());

            Note note = new Note();
            note.setGuid(noteGuid);
            note.setUserId(user.getId());
            note.setTitle(initNote.getTitle());
            note.setUpdateSequenceNumber(afterUSN);

            int affectedRow = noteMapper.insertNote(note);

            if (affectedRow > 0) {

                DateFormat sdf = new SimpleDateFormat(DEF_FORMAT_BY_YYYYMM);
                String dateGroup = sdf.format(new Date());

                NoteAttribute noteAttribute = new NoteAttribute();
                noteAttribute.setNoteId(note.getId());
                noteAttribute.setSummaryBody(initNote.getSummaryBody());
                noteAttribute.setAttachCount(4);
                noteAttribute.setInlineTagCount(0);
                noteAttribute.setTagCount(1);
                noteAttribute.setLatitude(0);
                noteAttribute.setLongitude(0);
                noteAttribute.setUpdateDevice(1);
                noteAttribute.setDateAlarm(null);
                noteAttribute.setAlarmComplete(false);
                noteAttribute.setDateGroup(dateGroup);
                noteAttribute.setType(NoteType.NORMAL.getValue());
                noteMapper.insertNoteAttribute(noteAttribute);

                // body 생성
                String bodyString = initNote.getBody();
                bodyString = bodyString.replace("${IMAGE_PATH1}", img1Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME1}", img1Name);
                
                bodyString = bodyString.replace("${IMAGE_PATH2}", img2Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME2}", img2Name);
                
                bodyString = bodyString.replace("${IMAGE_PATH3}", img3Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME3}", img3Name);
                
                bodyString = bodyString.replace("${IMAGE_PATH4}", img4Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME4}", img4Name);

                String bodyHash = CryptoUtil.hashStringToHexString(bodyString);
                long noteSize = bodyString.getBytes().length;

                NoteBody noteBody = new NoteBody();
                noteBody.setNoteId(note.getId());
                noteBody.setBodyHash(bodyHash);
                noteBody.setSize(noteSize);
                noteBody.setBody(bodyString);
                noteMapper.insertNoteBody(noteBody);

                NoteSearch noteSearch = new NoteSearch();
                noteSearch.setNoteGuid(noteGuid);
                noteSearch.setUserId(user.getId());
                noteSearch.setTitle(initNote.getTitle());
                noteSearch.setType(NoteSearchBatchType.ADD.getValue());
                noteSearch.setApply(false);
                noteSearchBatchMapper.insertNoteSearch(noteSearch);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), initNote.getSize());
            }

            // 썸네일
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource = new Resource();
            resource.setGuid(UUID.randomUUID().toString());
            resource.setNoteId(note.getId());
            resource.setHash(resourceHashValues[0]);
            resource.setSize(resourceSizeValues[0]);
            resource.setMime("image/jpeg");
            resource.setWidth(320);
            resource.setHeight(320);
            resource.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource.getId());
                resourceAttribute.setResourcePath(imgThumbPath.toString());
                resourceAttribute.setFileName(imgTumbName);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(true);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트 (썸네일은 추가 안함)
                // userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[0]);
            }

            // img 1
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource1 = new Resource();
            resource1.setGuid(UUID.randomUUID().toString());
            resource1.setNoteId(note.getId());
            resource1.setHash(resourceHashValues[1]);
            resource1.setSize(resourceSizeValues[1]);
            resource1.setMime("image/jpeg");
            resource1.setWidth(600);
            resource1.setHeight(300);
            resource1.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource1);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource1.getId());
                resourceAttribute.setResourcePath(img1Path.toString());
                resourceAttribute.setFileName(img1Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[1]);
            }
            
            // img 2
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource2 = new Resource();
            resource2.setGuid(UUID.randomUUID().toString());
            resource2.setNoteId(note.getId());
            resource2.setHash(resourceHashValues[2]);
            resource2.setSize(resourceSizeValues[2]);
            resource2.setMime("image/jpeg");
            resource2.setWidth(600);
            resource2.setHeight(500);
            resource2.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource2);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource2.getId());
                resourceAttribute.setResourcePath(img2Path.toString());
                resourceAttribute.setFileName(img2Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[2]);
            }
            
            // img 3
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource3 = new Resource();
            resource3.setGuid(UUID.randomUUID().toString());
            resource3.setNoteId(note.getId());
            resource3.setHash(resourceHashValues[3]);
            resource3.setSize(resourceSizeValues[3]);
            resource3.setMime("image/jpeg");
            resource3.setWidth(600);
            resource3.setHeight(420);
            resource3.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource3);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource3.getId());
                resourceAttribute.setResourcePath(img3Path.toString());
                resourceAttribute.setFileName(img3Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[3]);
            }
            
            // img 4
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource4 = new Resource();
            resource4.setGuid(UUID.randomUUID().toString());
            resource4.setNoteId(note.getId());
            resource4.setHash(resourceHashValues[4]);
            resource4.setSize(resourceSizeValues[4]);
            resource4.setMime("image/jpeg");
            resource4.setWidth(600);
            resource4.setHeight(330);
            resource4.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource4);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource4.getId());
                resourceAttribute.setResourcePath(img4Path.toString());
                resourceAttribute.setFileName(img4Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[4]);
            }

            // 리소스 업로드
            StringBuilder resourcePath = new StringBuilder();
            resourcePath.append(this.getClass().getResource("/").getPath());
            resourcePath.append("../");
            resourcePath.append("resources/images/");
            resourcePath.append(folderName);

            String bucketName = bucketMapper.selectBucketById(user.getBucketId()).getName();

            File thumbFile = new File(resourcePath.toString() + "1p_thumb.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, imgThumbPath.toString(), thumbFile);

            File img1File = new File(resourcePath.toString() + "1p_1.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img1Path.toString(), img1File);
            
            File img2File = new File(resourcePath.toString() + "1p_2.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img2Path.toString(), img2File);
            
            File img3File = new File(resourcePath.toString() + "1p_3.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img3Path.toString(), img3File);
            
            File img4File = new File(resourcePath.toString() + "1p_4.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img4Path.toString(), img4File);

        } else {
            throw new ResourceNotFoundException(null, "initNote");
        }
    }
    
    private void makeNewIntroductionEngInitNote(User user) throws ResourceNotFoundException {
    	
    	String[] resourceHashValues = new String[] { "c22bda26d3c2c361d2ba655a2872f746a9b17fae",
				"acb2e6b0b651cf26dcb9b5e15f5ce46f06dc74af", "5aeac7ac3745df76027adb2edb916999d1ea2215",
				"994140967316a71c55056d067c5e5134c150be85", "07ed4438feeee4eff7bb5de7032c12849690d8ba" };
        long[] resourceSizeValues = new long[] { 20723, 18899, 162236, 115622, 27009 };
        String folderName = "new_init_note_image/";

        InitNote initNote = initNoteMapper.selectInitNoteByLocale(InitNoteType.INTRODUCTION.getValue(), "US");

        if (initNote != null) {

            // 노트 guid 생성
            String noteGuid = UUID.randomUUID().toString();

            // 각 이미지 리소스 패스 생성
            String imgTumbName = "1p_thumb.jpg";
            String img1Name = "1p_1.jpg";
            String img2Name = "1p_eng_2.jpg";
            String img3Name = "1p_eng_3.jpg";
            String img4Name = "1p_4.jpg";

            StringBuilder imgThumbPath = new StringBuilder();
            imgThumbPath.append(getAmazonResourcePath(noteGuid, user.getId()));
            imgThumbPath.append(imgTumbName);

            StringBuilder img1Path = new StringBuilder();
            img1Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img1Path.append(img1Name);
            
            StringBuilder img2Path = new StringBuilder();
            img2Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img2Path.append(img2Name);
            
            StringBuilder img3Path = new StringBuilder();
            img3Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img3Path.append(img3Name);
            
            StringBuilder img4Path = new StringBuilder();
            img4Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img4Path.append(img4Name);

            // 노트 생성
            long afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.NOTE_UPDATE.getType());

            Note note = new Note();
            note.setGuid(noteGuid);
            note.setUserId(user.getId());
            note.setTitle(initNote.getTitle());
            note.setUpdateSequenceNumber(afterUSN);

            int affectedRow = noteMapper.insertNote(note);

            if (affectedRow > 0) {

                DateFormat sdf = new SimpleDateFormat(DEF_FORMAT_BY_YYYYMM);
                String dateGroup = sdf.format(new Date());

                NoteAttribute noteAttribute = new NoteAttribute();
                noteAttribute.setNoteId(note.getId());
                noteAttribute.setSummaryBody(initNote.getSummaryBody());
                noteAttribute.setAttachCount(4);
                noteAttribute.setInlineTagCount(0);
                noteAttribute.setTagCount(1);
                noteAttribute.setLatitude(0);
                noteAttribute.setLongitude(0);
                noteAttribute.setUpdateDevice(1);
                noteAttribute.setDateAlarm(null);
                noteAttribute.setAlarmComplete(false);
                noteAttribute.setDateGroup(dateGroup);
                noteAttribute.setType(NoteType.NORMAL.getValue());
                noteMapper.insertNoteAttribute(noteAttribute);

                // body 생성
                String bodyString = initNote.getBody();
                bodyString = bodyString.replace("${IMAGE_PATH1}", img1Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME1}", img1Name);
                
                bodyString = bodyString.replace("${IMAGE_PATH2}", img2Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME2}", img2Name);
                
                bodyString = bodyString.replace("${IMAGE_PATH3}", img3Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME3}", img3Name);
                
                bodyString = bodyString.replace("${IMAGE_PATH4}", img4Path.toString());
                bodyString = bodyString.replace("${IMAGE_NAME4}", img4Name);

                String bodyHash = CryptoUtil.hashStringToHexString(bodyString);
                long noteSize = bodyString.getBytes().length;

                NoteBody noteBody = new NoteBody();
                noteBody.setNoteId(note.getId());
                noteBody.setBodyHash(bodyHash);
                noteBody.setSize(noteSize);
                noteBody.setBody(bodyString);
                noteMapper.insertNoteBody(noteBody);

                NoteSearch noteSearch = new NoteSearch();
                noteSearch.setNoteGuid(noteGuid);
                noteSearch.setUserId(user.getId());
                noteSearch.setTitle(initNote.getTitle());
                noteSearch.setType(NoteSearchBatchType.ADD.getValue());
                noteSearch.setApply(false);
                noteSearchBatchMapper.insertNoteSearch(noteSearch);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), initNote.getSize());
            }

            // 썸네일
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource = new Resource();
            resource.setGuid(UUID.randomUUID().toString());
            resource.setNoteId(note.getId());
            resource.setHash(resourceHashValues[0]);
            resource.setSize(resourceSizeValues[0]);
            resource.setMime("image/jpeg");
            resource.setWidth(320);
            resource.setHeight(320);
            resource.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource.getId());
                resourceAttribute.setResourcePath(imgThumbPath.toString());
                resourceAttribute.setFileName(imgTumbName);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(true);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트 (썸네일은 추가 안함)
                // userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[0]);
            }

            // img 1
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource1 = new Resource();
            resource1.setGuid(UUID.randomUUID().toString());
            resource1.setNoteId(note.getId());
            resource1.setHash(resourceHashValues[1]);
            resource1.setSize(resourceSizeValues[1]);
            resource1.setMime("image/jpeg");
            resource1.setWidth(600);
            resource1.setHeight(300);
            resource1.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource1);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource1.getId());
                resourceAttribute.setResourcePath(img1Path.toString());
                resourceAttribute.setFileName(img1Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[1]);
            }
            
            // img 2
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource2 = new Resource();
            resource2.setGuid(UUID.randomUUID().toString());
            resource2.setNoteId(note.getId());
            resource2.setHash(resourceHashValues[2]);
            resource2.setSize(resourceSizeValues[2]);
            resource2.setMime("image/jpeg");
            resource2.setWidth(600);
            resource2.setHeight(500);
            resource2.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource2);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource2.getId());
                resourceAttribute.setResourcePath(img2Path.toString());
                resourceAttribute.setFileName(img2Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[2]);
            }
            
            // img 3
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource3 = new Resource();
            resource3.setGuid(UUID.randomUUID().toString());
            resource3.setNoteId(note.getId());
            resource3.setHash(resourceHashValues[3]);
            resource3.setSize(resourceSizeValues[3]);
            resource3.setMime("image/jpeg");
            resource3.setWidth(600);
            resource3.setHeight(420);
            resource3.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource3);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource3.getId());
                resourceAttribute.setResourcePath(img3Path.toString());
                resourceAttribute.setFileName(img3Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[3]);
            }
            
            // img 4
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource4 = new Resource();
            resource4.setGuid(UUID.randomUUID().toString());
            resource4.setNoteId(note.getId());
            resource4.setHash(resourceHashValues[4]);
            resource4.setSize(resourceSizeValues[4]);
            resource4.setMime("image/jpeg");
            resource4.setWidth(600);
            resource4.setHeight(330);
            resource4.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource4);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource4.getId());
                resourceAttribute.setResourcePath(img4Path.toString());
                resourceAttribute.setFileName(img4Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[4]);
            }

            // 리소스 업로드
            StringBuilder resourcePath = new StringBuilder();
            resourcePath.append(this.getClass().getResource("/").getPath());
            resourcePath.append("../");
            resourcePath.append("resources/images/");
            resourcePath.append(folderName);

            String bucketName = bucketMapper.selectBucketById(user.getBucketId()).getName();

            File thumbFile = new File(resourcePath.toString() + "1p_thumb.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, imgThumbPath.toString(), thumbFile);

            File img1File = new File(resourcePath.toString() + "1p_1.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img1Path.toString(), img1File);
            
            File img2File = new File(resourcePath.toString() + "1p_eng_2.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img2Path.toString(), img2File);
            
            File img3File = new File(resourcePath.toString() + "1p_eng_3.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img3Path.toString(), img3File);
            
            File img4File = new File(resourcePath.toString() + "1p_4.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img4Path.toString(), img4File);

        } else {
            throw new ResourceNotFoundException(null, "initNote");
        }
    }

    @SuppressWarnings("unused")
    private void makeNewPracticeInitNote(User user) throws ResourceNotFoundException {

        String[] resourceHashValues = new String[] { "453bc190685284763b6e7366ddf242b8888e2386", "a88235b5d651221eee6b3367c09f022f68534ebe" };
        long[] resourceSizeValues = new long[] { 13462, 166704 };
        String folderName = "new_init_note_image/";

        String initNoteLanguage = null;

        // 이전 방식의 회원 가입을 통해 Language 값이 아닌 Locale의 Country 값으로 사용자의 언어를 판단.
        if (StringUtils.isEmpty(user.getLanguage()) == true) {

            if (user.getLocale().equalsIgnoreCase(Locale.KOREA.getCountry())) {
                initNoteLanguage = Locale.KOREA.getCountry();
            } else {
                initNoteLanguage = Locale.US.getCountry();
            }

        } else { // 신규 방식의 회원 가입을 통해 Language 값으로 사용자의 언어를 판단.

            if (user.getLanguage().equalsIgnoreCase(Locale.KOREA.getLanguage())) {
                initNoteLanguage = Locale.KOREA.getCountry();
            } else {
                initNoteLanguage = Locale.US.getCountry();
            }
        }

        InitNote initNote = initNoteMapper.selectInitNoteByLocale(InitNoteType.PRACTICE.getValue(), initNoteLanguage);

        if (initNote != null) {

            // 태그 생성
            Tag tag = tagMapper.selectTagByUserIdAndName(user.getId(), "DigitalPage");

            // 노트 guid 생성
            String noteGuid = UUID.randomUUID().toString();

            // 각 이미지 리소스 패스 생성
            String imgTumbName = "2p_thumb.jpg";
            String img1Name = "2p.jpg";

            StringBuilder imgThumbPath = new StringBuilder();
            imgThumbPath.append(getAmazonResourcePath(noteGuid, user.getId()));
            imgThumbPath.append(imgTumbName);

            StringBuilder img1Path = new StringBuilder();
            img1Path.append(getAmazonResourcePath(noteGuid, user.getId()));
            img1Path.append(img1Name);

            // 노트 생성
            long afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.NOTE_UPDATE.getType());

            Note note = new Note();
            note.setGuid(noteGuid);
            note.setUserId(user.getId());
            note.setTitle(initNote.getTitle());
            note.setUpdateSequenceNumber(afterUSN);

            int affectedRow = noteMapper.insertNote(note);

            if (affectedRow > 0) {

                DateFormat sdf = new SimpleDateFormat(DEF_FORMAT_BY_YYYYMM);
                String dateGroup = sdf.format(new Date());

                NoteAttribute noteAttribute = new NoteAttribute();
                noteAttribute.setNoteId(note.getId());
                noteAttribute.setSummaryBody(initNote.getSummaryBody());
                noteAttribute.setAttachCount(8);
                noteAttribute.setInlineTagCount(0);
                noteAttribute.setTagCount(1);
                noteAttribute.setLatitude(0);
                noteAttribute.setLongitude(0);
                noteAttribute.setUpdateDevice(1);
                noteAttribute.setDateAlarm(null);
                noteAttribute.setAlarmComplete(false);
                noteAttribute.setDateGroup(dateGroup);
                noteAttribute.setType(NoteType.NORMAL.getValue());
                noteMapper.insertNoteAttribute(noteAttribute);

                // body 생성
                String bodyString = initNote.getBody();
                bodyString = bodyString.replace("${IMAGE_PATH1}", img1Path.toString());

                bodyString = bodyString.replace("${IMAGE_NAME1}", img1Name);

                String bodyHash = CryptoUtil.hashStringToHexString(bodyString);
                long noteSize = bodyString.getBytes().length;

                NoteBody noteBody = new NoteBody();
                noteBody.setNoteId(note.getId());
                noteBody.setBodyHash(bodyHash);
                noteBody.setSize(noteSize);
                noteBody.setBody(bodyString);
                noteMapper.insertNoteBody(noteBody);

                NoteSearch noteSearch = new NoteSearch();
                noteSearch.setNoteGuid(noteGuid);
                noteSearch.setUserId(user.getId());
                noteSearch.setTitle(initNote.getTitle());
                noteSearch.setType(NoteSearchBatchType.ADD.getValue());
                noteSearch.setApply(false);
                noteSearchBatchMapper.insertNoteSearch(noteSearch);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), initNote.getSize());
            }

            // 썸네일
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource = new Resource();
            resource.setGuid(UUID.randomUUID().toString());
            resource.setNoteId(note.getId());
            resource.setHash(resourceHashValues[0]);
            resource.setSize(resourceSizeValues[0]);
            resource.setMime("image/jpeg");
            resource.setWidth(320);
            resource.setHeight(311);
            resource.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource.getId());
                resourceAttribute.setResourcePath(imgThumbPath.toString());
                resourceAttribute.setFileName(imgTumbName);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(true);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트 (썸네일은 추가 안함)
                // userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[0]);
            }

            // img 1
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource1 = new Resource();
            resource1.setGuid(UUID.randomUUID().toString());
            resource1.setNoteId(note.getId());
            resource1.setHash(resourceHashValues[1]);
            resource1.setSize(resourceSizeValues[1]);
            resource1.setMime("image/jpeg");
            resource1.setWidth(1440);
            resource1.setHeight(1400);
            resource1.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource1);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource1.getId());
                resourceAttribute.setResourcePath(img1Path.toString());
                resourceAttribute.setFileName(img1Name);
                resourceAttribute.setAttachment(false);
                resourceAttribute.setThumbnail(false);

                resourceMapper.insertResourceAttribute(resourceAttribute);

                // 용량 업데이트
                userMapper.addUserUploadedByUserId(user.getId(), resourceSizeValues[1]);
            }

            // 태그 릴레이션 생성
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.TAG_RELATION_UPDATE.getType());

            TagRelation tagRelation = new TagRelation();
            tagRelation.setGuid(UUID.randomUUID().toString());
            tagRelation.setTagGuid(tag.getGuid());
            tagRelation.setNoteGuid(noteGuid);
            tagRelation.setUpdateSequenceNumber(afterUSN);
            affectedRow = tagRelationMapper.insertTagRelation(tagRelation);

            // 리소스 업로드
            StringBuilder resourcePath = new StringBuilder();
            resourcePath.append(this.getClass().getResource("/").getPath());
            resourcePath.append("../");
            resourcePath.append("resources/images/");
            resourcePath.append(folderName);

            String bucketName = bucketMapper.selectBucketById(user.getBucketId()).getName();

            File thumbFile = new File(resourcePath.toString() + "2p_thumb.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, imgThumbPath.toString(), thumbFile);

            File img1File = new File(resourcePath.toString() + "2p.jpg");
            AmazonS3FileService.saveAttachFileToAmazon(bucketName, img1Path.toString(), img1File);

        } else {
            throw new ResourceNotFoundException(null, "initNote");
        }
    }


    private void makeTourSampleInitNote(User user) {

        String[] resourceHashValues = new String[] { "000b0a8f6c290d772a2b05d2caa362e8746cc449", "96e99a2792ce0e776f21d620902008daccc354be" };
        long[] resourceSizeValues = new long[] { 23786, 758101 };
        String folderName = "sample_tour_page/";

        String thumbImgName = "img_stockholm_thumb.jpg";
        String imgName = "img_stockholm.jpg";
        Locale targetLocale = null;
        String initNoteLocale = null;

        // 이전 방식의 회원 가입을 통해 Language 값이 아닌 Locale의 Country 값으로 사용자의 언어를 판단.
        if (StringUtils.isEmpty(user.getLanguage()) == true) {

            if (user.getLocale().equalsIgnoreCase(Locale.KOREA.getCountry())) {
                targetLocale = Locale.KOREA;
                initNoteLocale = targetLocale.getCountry();
            } else {
                targetLocale = Locale.US;
                initNoteLocale = targetLocale.getCountry();
            }

        } else { // 신규 방식의 회원 가입을 통해 Language 값으로 사용자의 언어를 판단.

            if (user.getLanguage().equalsIgnoreCase(Locale.KOREA.getLanguage())) {
                targetLocale = Locale.KOREA;
                initNoteLocale = targetLocale.getCountry();
            } else {
                targetLocale = Locale.US;
                initNoteLocale = targetLocale.getCountry();
            }
        }

        InitNote initNote = initNoteMapper.selectInitNoteByLocale(InitNoteType.TOUR.getValue(), initNoteLocale);

        // 노트에 들어가있는 리소스 정리
        List<InitNoteResource> initNoteResourceList = initNoteResourceMapper.selectInitNoteResourceByTypeAndLanguage(InitNoteType.TOUR.getValue(), targetLocale.getLanguage());

        List<ResourceWeb> resourceList = new ArrayList<>();
        List<TagWeb> tagList = new ArrayList<>();
        List<LocationInlineTagWeb> locationInlineTagList = new ArrayList<>();
        List<TodoWeb> todoList = new ArrayList<>();
        List<Schedule> scheduleList = new ArrayList<>();

        for (InitNoteResource initNoteResource : initNoteResourceList) {

            int objectTypeValue = initNoteResource.getObjectType();
            InitNoteResourceObjectType objectType = InitNoteResourceObjectType.valueOf(objectTypeValue);

            switch (objectType) {
            case PHOTO: {

                // 사진 리소스는 속성을 하드코딩으로 삽입

                ResourceWeb thumbImgResourceWeb = new ResourceWeb();
                thumbImgResourceWeb.setGuid(UUID.randomUUID().toString());
                thumbImgResourceWeb.setHash(resourceHashValues[0]);
                thumbImgResourceWeb.setSize(resourceSizeValues[0]);
                thumbImgResourceWeb.setMime("image/jpeg");
                thumbImgResourceWeb.setWidth(320);
                thumbImgResourceWeb.setHeight(320);
                thumbImgResourceWeb.setFileName(thumbImgName);
                thumbImgResourceWeb.setAttachment(false);
                thumbImgResourceWeb.setThumbnail(true);

                ResourceWeb imgResourceWeb = new ResourceWeb();
                imgResourceWeb.setGuid(UUID.randomUUID().toString());
                imgResourceWeb.setHash(resourceHashValues[1]);
                imgResourceWeb.setSize(resourceSizeValues[1]);
                imgResourceWeb.setMime("image/jpeg");
                imgResourceWeb.setWidth(1920);
                imgResourceWeb.setHeight(1279);
                imgResourceWeb.setFileName(imgName);
                imgResourceWeb.setAttachment(true);
                imgResourceWeb.setThumbnail(false);

                resourceList.add(thumbImgResourceWeb);
                resourceList.add(imgResourceWeb);

                break;
            }
            case LOCATION: {

                LocationInlineTagWeb locationInlineTagWeb = new LocationInlineTagWeb();
                locationInlineTagWeb.setGuid(UUID.randomUUID().toString());
                locationInlineTagWeb.setName(initNoteResource.getResourceName());
                locationInlineTagWeb.setAddress(initNoteResource.getAddress());
                locationInlineTagWeb.setLatitude(initNoteResource.getLatitude());
                locationInlineTagWeb.setLongitude(initNoteResource.getLongitude());
                locationInlineTagWeb.setRelationGuid(UUID.randomUUID().toString());

                locationInlineTagList.add(locationInlineTagWeb);

                break;
            }
            case TAG: {

                TagWeb tagWeb = new TagWeb();
                tagWeb.setGuid(UUID.randomUUID().toString());
                tagWeb.setName(initNoteResource.getResourceName());
                tagWeb.setRelationGuid(UUID.randomUUID().toString());

                tagList.add(tagWeb);

                break;
            }
            case TODO: {

                TodoWeb todoWeb = new TodoWeb();
                todoWeb.setGuid(UUID.randomUUID().toString());
                todoWeb.setName(initNoteResource.getResourceName());
                todoWeb.setDateLimit(initNoteResource.getDateLimit());
                todoWeb.setComplete(initNoteResource.isComplete());

                todoList.add(todoWeb);

                break;
            }
            case SCHEDULE: {
                Schedule schedule = new Schedule();
                schedule.setGuid(UUID.randomUUID().toString());
                schedule.setTitle(initNoteResource.getResourceName());

                /*
                Calendar cal = Calendar.getInstance();
                cal.set(Calendar.DAY_OF_WEEK, Calendar.SUNDAY);
                cal.set(Calendar.HOUR_OF_DAY, 17);
                cal.set(Calendar.MINUTE, 0);

                Date targetStartDate = DateUtils.addMilliseconds(cal.getTime(), 0);
                String startDate = TimeUtil.format(targetStartDate);

                schedule.setDateStart(startDate);

                cal.add(Calendar.DAY_OF_MONTH, 21); // 3주
                cal.set(Calendar.HOUR_OF_DAY, 18);

                Date targetEndDate = DateUtils.addMilliseconds(cal.getTime(), 0);
                String endDate = TimeUtil.format(targetEndDate);

                schedule.setDateEnd(endDate);

                scheduleList.add(schedule);
                
                Date dateStart = TimeUtil.parse(initNoteResource.getDateStart(), "yyyy-MM-dd HH:mm:ss", TimeZone.getTimeZone(user.getTimezone()));
                Date dateEnd = TimeUtil.parse(initNoteResource.getDateEnd(), "yyyy-MM-dd HH:mm:ss", TimeZone.getTimeZone(user.getTimezone()));
                schedule.setDateStart(TimeUtil.format(dateStart));
                schedule.setDateEnd(TimeUtil.format(dateEnd));
                */
                schedule.setDateStart(initNoteResource.getDateStart());
                schedule.setDateEnd(initNoteResource.getDateEnd());

                scheduleList.add(schedule);
                
                break;
            }
            default: {
                break;
            }
            }
        }

        // 실제 페이지 생성
        // 노트 생성
        long afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.NOTE_UPDATE.getType());

        String noteGuid = UUID.randomUUID().toString();

        Note note = new Note();
        note.setGuid(noteGuid);
        note.setUserId(user.getId());
        note.setTitle(initNote.getTitle());
        note.setUpdateSequenceNumber(afterUSN);

        int affectedRow = noteMapper.insertNote(note);

        if (affectedRow > 0) {

            DateFormat sdf = new SimpleDateFormat(DEF_FORMAT_BY_YYYYMM);
            String dateGroup = sdf.format(new Date());

            StringBuilder thumbImgPath = new StringBuilder();
            thumbImgPath.append(getAmazonResourcePath(noteGuid, user.getId()));
            thumbImgPath.append(resourceList.get(0).getFileName());
            resourceList.get(0).setResourcePath(thumbImgPath.toString());

            StringBuilder imgPath = new StringBuilder();
            imgPath.append(getAmazonResourcePath(noteGuid, user.getId()));
            imgPath.append(resourceList.get(1).getFileName());
            resourceList.get(1).setResourcePath(imgPath.toString());

            // body 생성
            String bodyString = initNote.getBody();
            String summaryBody = initNote.getSummaryBody();

            // Image 처리
            bodyString = bodyString.replace("${IMAGE_PATH1}", imgPath.toString());
            bodyString = bodyString.replace("${IMAGE_NAME1}", imgName);

            // Location Inline Tag 처리
            int i = 0;
            for (LocationInlineTagWeb locationInlineTagWeb : locationInlineTagList) {
                ++i;
                String relationGuid = locationInlineTagWeb.getRelationGuid();
                bodyString = bodyString.replace("${PLACE_RELATION_GUID" + i + "}", relationGuid);
            }

            // Todo 처리
            i = 0;
            for (TodoWeb todoWeb : todoList) {
                ++i;
                String guid = todoWeb.getGuid();
                bodyString = bodyString.replace("${TODO_GUID" + i + "}", guid);
            }

            // Tag 처리
            i = 0;
            for (TagWeb tagWeb : tagList) {
                ++i;
                String relationGuid = tagWeb.getRelationGuid();
                bodyString = bodyString.replace("${TAG_RELATION_GUID" + i + "}", relationGuid);

            }

            // Schedule 처리
            i = 0;
            for (Schedule schedule : scheduleList) {
                ++i;
                String guid = schedule.getGuid();
                bodyString = bodyString.replace("${SCHEDULE_GUID" + i + "}", guid);

                String title = makeScheduleTitle(targetLocale.getLanguage(), schedule, user.getTimezone());
                bodyString = bodyString.replace("${SCHEDULE_TITLE" + i + "}", title);
                summaryBody = summaryBody.replace("${SCHEDULE_TITLE" + i + "}", title);
            }

            String bodyHash = CryptoUtil.hashStringToHexString(bodyString);
            long noteSize = bodyString.getBytes().length;

            NoteAttribute noteAttribute = new NoteAttribute();
            noteAttribute.setNoteId(note.getId());
            noteAttribute.setSummaryBody(summaryBody);
            noteAttribute.setAttachCount(resourceList.size());
            noteAttribute.setInlineTagCount(0);
            noteAttribute.setTagCount(tagList.size());
            noteAttribute.setLatitude(0);
            noteAttribute.setLongitude(0);
            noteAttribute.setUpdateDevice(1);
            noteAttribute.setDateAlarm(null);
            noteAttribute.setAlarmComplete(false);
            noteAttribute.setDateGroup(dateGroup);
            noteAttribute.setType(NoteType.NORMAL.getValue());
            noteMapper.insertNoteAttribute(noteAttribute);

            NoteBody noteBody = new NoteBody();
            noteBody.setNoteId(note.getId());
            noteBody.setBodyHash(bodyHash);
            noteBody.setSize(noteSize);
            noteBody.setBody(bodyString);
            noteMapper.insertNoteBody(noteBody);

            NoteSearch noteSearch = new NoteSearch();
            noteSearch.setNoteGuid(noteGuid);
            noteSearch.setUserId(user.getId());
            noteSearch.setTitle(initNote.getTitle());
            noteSearch.setType(NoteSearchBatchType.ADD.getValue());
            noteSearch.setApply(false);
            noteSearchBatchMapper.insertNoteSearch(noteSearch);

            // 용량 업데이트
            userMapper.addUserUploadedByUserId(user.getId(), initNote.getSize());
        }

        // 리소스 처리
        for (ResourceWeb resourceWeb : resourceList) {
            afterUSN = synoIndexService.getAfterUSN(user.getId(), EntryType.RESOURCE_UPDATE.getType());

            Resource resource = new Resource();
            resource.setGuid(resourceWeb.getGuid());
            resource.setNoteId(note.getId());
            resource.setHash(resourceWeb.getHash());
            resource.setSize(resourceWeb.getSize());
            resource.setMime(resourceWeb.getMime());
            resource.setWidth(resourceWeb.getWidth());
            resource.setHeight(resourceWeb.getHeight());
            resource.setUpdateSequenceNumber(afterUSN);

            affectedRow = resourceMapper.insertResource(resource);

            if (affectedRow == 1) {

                ResourceAttribute resourceAttribute = new ResourceAttribute();
                resourceAttribute.setResourceId(resource.getId());
                resourceAttribute.setResourcePath(resourceWeb.getResourcePath());
                resourceAttribute.setFileName(resourceWeb.getFileName());
                resourceAttribute.setAttachment(resourceWeb.isAttachment());
                resourceAttribute.setThumbnail(resourceWeb.isThumbnail());

                resourceMapper.insertResourceAttribute(resourceAttribute);

                if (!resourceWeb.isThumbnail()) {
                    userMapper.addUserUploadedByUserId(user.getId(), resourceWeb.getSize());
                }
            }
        }

        // 장소 인라인 태그 처리
        for (LocationInlineTagWeb locationInlineTagWeb : locationInlineTagList) {

            // 같은 장소 인라인 태그가 등록되어 있는지 확인
            LocationInlineTag insertedLocationInlineTag = locationInlineTagMapper.selectLocationInlineTagByUserIdAndNameAndAddress(note.getUserId(),
                                                                                                                                   locationInlineTagWeb.getName(),
                                                                                                                                   locationInlineTagWeb.getAddress());

            if (insertedLocationInlineTag != null) {
                locationInlineTagWeb.setGuid(insertedLocationInlineTag.getGuid());
            } else { // 인라인 태그 생성
                afterUSN = synoIndexService.getAfterUSN(note.getUserId(), EntryType.LOCATION_INLINE_TAG_UPDATE.getType());

                LocationInlineTag locationInlineTag = new LocationInlineTag();
                locationInlineTag.setGuid(locationInlineTagWeb.getGuid());
                locationInlineTag.setName(locationInlineTagWeb.getName());
                locationInlineTag.setAddress(locationInlineTagWeb.getAddress());
                locationInlineTag.setLatitude(locationInlineTagWeb.getLatitude());
                locationInlineTag.setLongitude(locationInlineTagWeb.getLongitude());
                locationInlineTag.setUserId(note.getUserId());
                locationInlineTag.setUpdateSequenceNumber(afterUSN);
                affectedRow = locationInlineTagMapper.insertLocationInlineTag(locationInlineTag);

                afterUSN = synoIndexService.getAfterUSN(note.getUserId(), EntryType.LOCATION_INLINE_TAG_RELATION_UPDATE.getType());

                LocationInlineTagRelation locationInlineTagRelation = new LocationInlineTagRelation();
                locationInlineTagRelation.setGuid(locationInlineTagWeb.getRelationGuid());
                locationInlineTagRelation.setLocationInlineTagGuid(locationInlineTagWeb.getGuid());
                locationInlineTagRelation.setNoteGuid(note.getGuid());
                locationInlineTagRelation.setUpdateSequenceNumber(afterUSN);
                locationInlineTagRelation.setCount(1);
                affectedRow = locationInlineTagRelationMapper.insertLocationInlineTagRelation(locationInlineTagRelation);
            }
        }

        // 태그 처리
        for (TagWeb tagWeb : tagList) {
            // 같은 이름의 태그가 등록되어 있는지 확인
            Tag insertedTag = tagMapper.selectTagByUserIdAndName(note.getUserId(), tagWeb.getName());

            if (insertedTag != null) { // 기존의 인라인 태그 존재하면 guid 변경
                tagWeb.setGuid(insertedTag.getGuid());
                tagWeb.setId(insertedTag.getId());
            } else { // 인라인 태그 생성
                afterUSN = synoIndexService.getAfterUSN(note.getUserId(), EntryType.TAG_UPDATE.getType());

                Tag tag = new Tag();
                tag.setGuid(tagWeb.getGuid());
                tag.setName(tagWeb.getName());
                tag.setUserId(note.getUserId());
                tag.setUpdateSequenceNumber(afterUSN);

                affectedRow = tagMapper.insertTag(tag);

                tagWeb.setId(tag.getId());

                afterUSN = synoIndexService.getAfterUSN(note.getUserId(), EntryType.TAG_RELATION_UPDATE.getType());

                TagRelation tagRelation = new TagRelation();
                tagRelation.setGuid(tagWeb.getRelationGuid());
                tagRelation.setTagGuid(tagWeb.getGuid());
                tagRelation.setNoteGuid(note.getGuid());
                tagRelation.setUpdateSequenceNumber(afterUSN);
                affectedRow = tagRelationMapper.insertTagRelation(tagRelation);

            }
        }

        // 할일 처리
        for (TodoWeb todoWeb : todoList) {

            afterUSN = synoIndexService.getAfterUSN(note.getUserId(), EntryType.TODO_UPDATE.getType());

            Todo todo = new Todo();
            todo.setNoteId(note.getId());
            todo.setUpdateSequenceNumber(afterUSN);
            todo.setGuid(todoWeb.getGuid());
            todo.setName(todoWeb.getName());
            todo.setDateLimit(todoWeb.getDateLimit());
            todo.setComplete(todoWeb.isComplete());

            if (todoWeb.isComplete()) {
                String dateComplete = TimeUtil.format(new Date());
                todo.setDateComplete(dateComplete);
            }

            affectedRow = todoMapper.insertTodoWithoutDate(todo);
        }

        // 일정 처리
        for (Schedule schedule : scheduleList) {
            afterUSN = synoIndexService.getAfterUSN(note.getUserId(), EntryType.SCHEDULE_UPDATE.getType());

            schedule.setNoteId(note.getId());
            schedule.setUpdateSequenceNumber(afterUSN);

            affectedRow = scheduleMapper.insertScheduleWithoutDate(schedule);
        }

        // 리소스 업로드
        StringBuilder resourcePath = new StringBuilder();
        resourcePath.append(this.getClass().getResource("/").getPath());
        resourcePath.append("../");
        resourcePath.append("resources/images/");
        resourcePath.append(folderName);

        String bucketName = bucketMapper.selectBucketById(user.getBucketId()).getName();

        File thumbFile = new File(resourcePath.toString() + thumbImgName);
        AmazonS3FileService.saveAttachFileToAmazon(bucketName, resourceList.get(0).getResourcePath().toString(), thumbFile);

        File img1File = new File(resourcePath.toString() + imgName);
        AmazonS3FileService.saveAttachFileToAmazon(bucketName, resourceList.get(1).getResourcePath().toString(), img1File);
    }


    private String makeScheduleTitle(String language, Schedule schedule, String timeZone) {

        StringBuffer sb = new StringBuffer();
        
        ZoneId zoneId = ZoneId.of("UTC");
        
        String timeZoneOffset = timeZone.replace("GMT", "");
        timeZoneOffset = timeZoneOffset.replace("UTC", "");
        
        ZoneOffset offset = ZoneOffset.UTC;
        
        // 하위 호환성을 위해 ios에서 넘기는 값을 체크
        if (StringUtils.contains(timeZoneOffset, ".")) {
        	timeZoneOffset = timeZoneOffset.replace("+", "");
        	timeZoneOffset = timeZoneOffset.replace("-", "");
        	String[] timeValue = timeZoneOffset.split("\\.");
        	offset = ZoneOffset.ofHoursMinutes(Integer.parseInt(timeValue[0]), Integer.parseInt(timeValue[1]));
        } else {
        	offset = ZoneOffset.of(timeZoneOffset);
        }
        
        ZonedDateTime startDate = LocalDateTime.parse(schedule.getDateStart(), DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")).atZone(zoneId);
        ZonedDateTime endDate = LocalDateTime.parse(schedule.getDateEnd(), DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")).atZone(zoneId);
        
        Instant startInstance = startDate.toInstant();
        Instant endInstance = endDate.toInstant();
        
        if (language.equalsIgnoreCase(Locale.KOREA.getLanguage())) {

            DateTimeFormatter mDisplayDateTimeSchedule = DateTimeFormatter.ofPattern("M월 d일(E), a h:mm", Locale.KOREAN);
            
            sb.append(schedule.getTitle());
            sb.append(", ");
            String startDateString = startInstance.atOffset(offset).format(mDisplayDateTimeSchedule);
            sb.append(startDateString);
            sb.append(" ~ ");
            String endDateString = endInstance.atOffset(offset).format(mDisplayDateTimeSchedule);
            sb.append(endDateString);

        } else {
        	
        	DateTimeFormatter mDisplayDateTimeSchedule = DateTimeFormatter.ofPattern("EEE, MMM dd, hh:mm a", Locale.ENGLISH);
        	
            sb.append(schedule.getTitle());
            sb.append(", ");
            String startDateString = startInstance.atOffset(offset).format(mDisplayDateTimeSchedule);
            sb.append(startDateString);
            sb.append(" ~ ");
            String endDateString = endInstance.atOffset(offset).format(mDisplayDateTimeSchedule);
            sb.append(endDateString);
        }

        return sb.toString();
    }


    @Override
    public List<UserData> getUserListByEmail(String email) throws Exception {

        List<User> emailUserList = userMapper.selectUserListByEmail(email);

        List<AccountInfo> representEmailAccountInfo = accountInfoMapper.selectAccountInfoByRepresentEmail(email);

        List<User> userList = mergeList(emailUserList, representEmailAccountInfo);

        List<UserData> returnList = new ArrayList<UserData>();

        for (User user : userList) {

            DeleteAccount deleteAccount = deleteAccountMapper.selectBeforeDeleteAccountByUserId(user.getId());
            if (deleteAccount != null) {
                continue;
            } else {

                AccountInfo accountInfo = accountInfoMapper.selectAccountInfo(user.getId());
                if (accountInfo == null) {
                    continue;
                }
                UserData userData = new UserData();

                userData.setEmail(user.getEmail());
                userData.setName(user.getName());
                userData.setSnsType(user.getSnsType());
                userData.setProfileImageUrl(accountInfo.getProfileImageUrl());
                userData.setRepresentEmail(accountInfo.getRepresentEmail());

                if (StringUtils.isEmpty(accountInfo.getRepresentEmail()) && user.getSnsType() != SnsType.KAKAOTALK.getValue()) {
                    userData.setRepresentEmail(user.getEmail());
                }

                returnList.add(userData);
            }
        }
        return returnList;
    }


    private List<User> mergeList(List<User> emailUserList, List<AccountInfo> representEmailAccountInfoList) {

        List<User> returnList = new ArrayList<User>();
        returnList.addAll(emailUserList);

        for (AccountInfo accountInfo : representEmailAccountInfoList) {
            boolean isExist = false;
            for (User user : emailUserList) {

                if (user.getId() == accountInfo.getUserId()) {
                    isExist = true;
                    break;
                }
            }

            if (!isExist) {
                User user = userMapper.selectUserByUserId(accountInfo.getUserId());
                returnList.add(user);
            }
        }

        return returnList;
    }
}

