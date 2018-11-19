package com.fasoo.note.api.service;


import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.TimeZone;

import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.time.DateUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.fasoo.note.Constant;
import com.fasoo.note.Parameter;
import com.fasoo.note.WebConfig;
import com.fasoo.note.api.bean.communication.MissionEventData;
import com.fasoo.note.api.mapper.AchieveMissionMapper;
import com.fasoo.note.api.mapper.InlineTagMapper;
import com.fasoo.note.api.mapper.NoteMapper;
import com.fasoo.note.bean.api.AchieveMission;
import com.fasoo.note.bean.api.AchieveMissionData;
import com.fasoo.note.bean.api.MissionEvent;
import com.fasoo.note.bean.api.MissionEventDetail;
import com.fasoo.note.bean.api.UserMissionHistory;
import com.fasoo.note.bean.member.User;
import com.fasoo.note.common.enumtype.InlineTagType;
import com.fasoo.note.common.enumtype.MissionEventType;
import com.fasoo.note.common.enumtype.NoteType;
import com.fasoo.note.common.enumtype.Privilege;
import com.fasoo.note.common.log.Rogger;
import com.fasoo.note.common.log.RoggerFactory;
import com.fasoo.note.member.mapper.UserMapper;


@Service
public class MissionServiceImpl implements MissionService {

    @Autowired
    AchieveMissionMapper achieveMissionMapper;
    @Autowired
    NoteMapper noteMapper;
    @Autowired
    InlineTagMapper inlineTagMapper;
    @Autowired
    UserMapper userMapper;

    private final SimpleDateFormat curDateFormat = new SimpleDateFormat(Constant.DATE_FORMAT_DEFAULT);
    private final String elapseTime = WebConfig.getString("mission.elapse.time");

    private final Rogger rogger = RoggerFactory.getRogger(MissionServiceImpl.class);


    @Override
    @Transactional
    public AchieveMissionData getAchieveMission(long userId, String language, int deviceType, int compareVersion) throws Exception {

        int publicState = 0;
        if (compareVersion >= 0) {
            publicState = 1;
        } else {
            publicState = -1;
        }

        AchieveMissionData achieveMissionData = new AchieveMissionData();
        AchieveMission lastReleaseUserAchieveMission = achieveMissionMapper.selectLastReleaseAchieveMission(userId);

        if (lastReleaseUserAchieveMission != null) {
            curDateFormat.setTimeZone(TimeZone.getTimeZone("UTC"));

            if (!StringUtils.isEmpty(lastReleaseUserAchieveMission.getDateCompleted())) {

                Date dateCurrent = curDateFormat.parse(curDateFormat.format(new Date()));
                Date dateCompleted = curDateFormat.parse(lastReleaseUserAchieveMission.getDateCompleted());
                dateCompleted = DateUtils.addMinutes(dateCompleted, Integer.parseInt(elapseTime));

                if (dateCompleted.after(dateCurrent) == true) {
                    achieveMissionData.setEventId(Constant.NOT_FOUND_RESOURCE_ID);
                    return achieveMissionData;
                }
            }
        }

        AchieveMission achieveMission = achieveMissionMapper.selectReleaseAchieveMission(userId, publicState);

        if (achieveMission == null) {
            UserMissionHistory userMissionHistory = checkAchieveMission(userId, publicState);
            if (userMissionHistory == null) {
                achieveMissionData.setEventId(Constant.NOT_FOUND_RESOURCE_ID);
                return achieveMissionData;
            }
            achieveMission = achieveMissionMapper.selectAchieveMissionByEventId(userMissionHistory.getMissionEventId());
            if (achieveMission == null) {
                achieveMissionData.setEventId(Constant.NOT_FOUND_RESOURCE_ID);
                return achieveMissionData;
            }
            achieveMission.setMissionEventId(userMissionHistory.getMissionEventId());
        }

        MissionEventDetail missionEventDetail = achieveMissionMapper.selectMissionEventDetail(achieveMission.getMissionEventId(),
                                                                                              language, deviceType);
        achieveMissionData.setAchieveMissionData(achieveMission, missionEventDetail);

        // 데이터가 없을 경우에 바로 리턴
        if (achieveMissionData.getEventId() == Constant.NOT_FOUND_RESOURCE_ID) {
            return achieveMissionData;
        }

        // 데이터가 있을 경우에 Prime 링크 체크
        String linkUrl = achieveMissionData.getLinkUrl();
        if (StringUtils.isEmpty(linkUrl) != true) {
            if (linkUrl.contains(Constant.WEB_PRIME_LINK) || linkUrl.contains(Constant.MOBILE_PRIME_LINK)) {
                User user = userMapper.selectUserByUserId(userId);
                if (user.getPrivilege() != Privilege.NORMAL.getValue())
                    achieveMissionData.setLinkUrl(null);
            }
        }

        return achieveMissionData;
    }


    private UserMissionHistory checkAchieveMission(long userId, int publicState) {

        List<MissionEvent> unachieveMissions = achieveMissionMapper.selectUnachieveMissionList(userId, publicState);

        boolean firstData = true;
        UserMissionHistory resultData = null;

        for (MissionEvent missionEvent : unachieveMissions) {

            int eventType = missionEvent.getEventType();
            int threshold = 0;

            switch (MissionEventType.valueOf(eventType)) {
            case NOTE_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                threshold = noteMapper.selectNoteCountByUserIdAndType(userId, NoteType.NORMAL.getValue());
                break;
            }
            case DATE_INLINE_TAG_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                param.put(Parameter.INLINE_TAG_TYPE, InlineTagType.DATE.getType());
                threshold = inlineTagMapper.selectInlineTagsCountByUserIdAndType(param);
                break;
            }
            case NAME_INLINE_TAG_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                param.put(Parameter.INLINE_TAG_TYPE, InlineTagType.NAME.getType());
                threshold = inlineTagMapper.selectInlineTagsCountByUserIdAndType(param);
                break;
            }
            case LOCATION_INLINE_TAG_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                param.put(Parameter.INLINE_TAG_TYPE, InlineTagType.LOCATION.getType());
                threshold = inlineTagMapper.selectInlineTagsCountByUserIdAndType(param);
                break;
            }
            default: {
                // 예외처리의 경우 루프를 돌림.
                continue;
            }
            }

            if (threshold >= missionEvent.getThreshold()) {
                UserMissionHistory userMissionHistory = new UserMissionHistory(missionEvent.getId(), userId);
                achieveMissionMapper.insertUserMissionHistory(userMissionHistory);
                if (firstData == true) {
                    resultData = userMissionHistory;
                    firstData = false;
                }
            }
        }

        return resultData;
    }


    @Override
    public int updateAchieveMissionClosed(UserMissionHistory userMissionHistory) throws Exception {

        return achieveMissionMapper.updateClosedTime(userMissionHistory);
    }


    @Override
    public List<MissionEventData> getGuestAchieveMissionList(String language, int deviceType) {

        List<MissionEventData> returnList = new ArrayList<MissionEventData>();

        List<MissionEvent> guestMissionEventList = achieveMissionMapper.selectMissionEventByGuestType(Constant.GUEST_MODE);

        for (MissionEvent guestMission : guestMissionEventList) {

            MissionEventData missionEventData = new MissionEventData();
            MissionEventDetail missionEventDetail = achieveMissionMapper.selectMissionEventDetail(guestMission.getId(), language, deviceType);
            if (missionEventDetail == null) {
                rogger.error("Resource Not Found Error");
                continue;
            }
            missionEventData.setMissionEvent(guestMission, missionEventDetail);

            returnList.add(missionEventData);
        }

        return returnList;
    }


    @Override
    public AchieveMissionData getAchieveMissionByMajorVersion(long userId, String language, int deviceType, int majorVersion) throws Exception {

        AchieveMissionData achieveMissionData = new AchieveMissionData();
        AchieveMission lastReleaseUserAchieveMission = achieveMissionMapper.selectLastReleaseAchieveMissionByMajorVersion(userId, majorVersion);

        if (lastReleaseUserAchieveMission != null) {
            curDateFormat.setTimeZone(TimeZone.getTimeZone("UTC"));

            if (!StringUtils.isEmpty(lastReleaseUserAchieveMission.getDateCompleted())) {

                Date dateCurrent = curDateFormat.parse(curDateFormat.format(new Date()));
                Date dateCompleted = curDateFormat.parse(lastReleaseUserAchieveMission.getDateCompleted());
                dateCompleted = DateUtils.addMinutes(dateCompleted, Integer.parseInt(elapseTime));

                if (dateCompleted.after(dateCurrent) == true) {
                    achieveMissionData.setEventId(Constant.NOT_FOUND_RESOURCE_ID);
                    return achieveMissionData;
                }
            }
        }

        AchieveMission achieveMission = achieveMissionMapper.selectReleaseAchieveMissionByMajorVersion(userId, majorVersion);

        if (achieveMission == null) {
            UserMissionHistory userMissionHistory = checkAchieveMissionByMajorVersion(userId, majorVersion);
            if (userMissionHistory == null) {
                achieveMissionData.setEventId(Constant.NOT_FOUND_RESOURCE_ID);
                return achieveMissionData;
            }
            achieveMission = achieveMissionMapper.selectAchieveMissionByEventId(userMissionHistory.getMissionEventId());
            if (achieveMission == null) {
                achieveMissionData.setEventId(Constant.NOT_FOUND_RESOURCE_ID);
                return achieveMissionData;
            }
            achieveMission.setMissionEventId(userMissionHistory.getMissionEventId());
        }

        MissionEventDetail missionEventDetail = achieveMissionMapper.selectMissionEventDetail(achieveMission.getMissionEventId(),
                                                                                              language, deviceType);
        achieveMissionData.setAchieveMissionData(achieveMission, missionEventDetail);

        // 데이터가 없을 경우에 바로 리턴
        if (achieveMissionData.getEventId() == Constant.NOT_FOUND_RESOURCE_ID) {
            return achieveMissionData;
        }

        // 데이터가 있을 경우에 Prime 링크 체크
        String linkUrl = achieveMissionData.getLinkUrl();
        if (StringUtils.isEmpty(linkUrl) != true) {
            if (linkUrl.contains(Constant.WEB_PRIME_LINK) || linkUrl.contains(Constant.MOBILE_PRIME_LINK)) {
                User user = userMapper.selectUserByUserId(userId);
                if (user.getPrivilege() != Privilege.NORMAL.getValue())
                    achieveMissionData.setLinkUrl(null);
            }
        }

        return achieveMissionData;
    }


    private UserMissionHistory checkAchieveMissionByMajorVersion(long userId, int majorVersion) {

        List<MissionEvent> unachieveMissions = achieveMissionMapper.selectUnachieveMissionListByMajorVersion(userId, majorVersion);

        boolean firstData = true;
        UserMissionHistory resultData = null;

        for (MissionEvent missionEvent : unachieveMissions) {

            int eventType = missionEvent.getEventType();
            int threshold = 0;

            switch (MissionEventType.valueOf(eventType)) {
            case NOTE_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                threshold = noteMapper.selectNoteCountByUserIdAndType(userId, NoteType.NORMAL.getValue());
                break;
            }
            case DATE_INLINE_TAG_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                param.put(Parameter.INLINE_TAG_TYPE, InlineTagType.DATE.getType());
                threshold = inlineTagMapper.selectInlineTagsCountByUserIdAndType(param);
                break;
            }
            case NAME_INLINE_TAG_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                param.put(Parameter.INLINE_TAG_TYPE, InlineTagType.NAME.getType());
                threshold = inlineTagMapper.selectInlineTagsCountByUserIdAndType(param);
                break;
            }
            case LOCATION_INLINE_TAG_COUNT: {
                HashMap<String, Object> param = new HashMap<String, Object>();
                param.put(Parameter.USER_ID, userId);
                param.put(Parameter.INLINE_TAG_TYPE, InlineTagType.LOCATION.getType());
                threshold = inlineTagMapper.selectInlineTagsCountByUserIdAndType(param);
                break;
            }
            default: {
                // 예외처리의 경우 루프를 돌림.
                continue;
            }
            }

            if (threshold >= missionEvent.getThreshold()) {
                UserMissionHistory userMissionHistory = new UserMissionHistory(missionEvent.getId(), userId);
                achieveMissionMapper.insertUserMissionHistory(userMissionHistory);
                if (firstData == true) {
                    resultData = userMissionHistory;
                    firstData = false;
                }
            }
        }

        return resultData;
    }


    @Override
    public AchieveMissionData getAchiveMissionById(String bannerId, String language) throws Exception{

        if (StringUtils.isEmpty(bannerId)) {
            return null;
        }

        int id = Integer.parseInt(bannerId);

        AchieveMission achieveMission = achieveMissionMapper.selectAchieveMissionByEventId(id);
        MissionEventDetail missionEventDetail = achieveMissionMapper.selectMissionEventDetail(id, language, 1);

        AchieveMissionData achieveMissionData = new AchieveMissionData();
        achieveMissionData.setAchieveMissionData(achieveMission, missionEventDetail);

        return achieveMissionData;
    }
}
