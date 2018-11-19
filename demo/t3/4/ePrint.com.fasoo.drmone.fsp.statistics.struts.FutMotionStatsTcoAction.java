/**
 * 
 */
package com.fasoo.drmone.fsp.statistics.struts;

import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TimeZone;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;
import com.fasoo.api.server.utils.FutMapUtils;
import com.fasoo.api.server.drmone.stats.TcoStats;
import com.fasoo.commons.gmtdate.FasooGmtUtils;
import com.fasoo.drmone.message.ServerMessage;
import com.fasoo.fut.beans.TcoStatsDate;
import com.fasoo.fut.beans.TcoStatsDept;
import com.fasoo.fut.beans.TcoStatsDoc;
import com.fasoo.fut.beans.TcoStatsUser;
import com.fasoo.logging.Log;
import com.fasoo.logging.LogFactory;
import com.fasoo.server.ServerConfig;

/**
 * @author bjlee
 *
 */
public class FutMotionStatsTcoAction extends DispatchAction {
	
	private Log logger = LogFactory.getLog( FutMotionStatsTcoAction.class );

	protected String getParameter( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		String parameter = mapping.getParameter();

		if( parameter == null )
		{
			String message = messages.getMessage( "dispatch.handler", mapping.getPath() );

			logger.errorString( message );

			throw new ServletException( message );
		}
		return parameter;
	}

	protected String getMethodName( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response, String parameter ) throws Exception
	{
		return request.getParameter( parameter );
	}

	public ActionForward execute( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		if( isCancelled( request ) )
		{
			return null;
		}

		String parameter = getParameter( mapping, form, request, response );

		String name = getMethodName( mapping, form, request, response, parameter );

		if( name == null || "".equals( name ) )
		{
			name = "statsUserToner";
		}

		// Prevent recursive calls
		if( "execute".equals( name ) || "perform".equals( name ) )
		{
			String message = messages.getMessage( "dispatch.recursive", mapping.getPath() );

			logger.errorString( message );
			throw new ServletException( message );
		}

		// Invoke the named method, and return the result
		return dispatchMethod( mapping, form, request, response, name );
	}

	private void checkDayCondition( FutMotionStatsTcoForm statsForm )
	{
		String startDay = statsForm.getStartDay();
		try
		{
			FasooGmtUtils.parse( FasooGmtUtils.pattern9, startDay, TimeZone.getDefault() );
		}
		catch( Exception e )
		{
			Calendar cal = Calendar.getInstance();
			cal.add( Calendar.DATE, -7 );
			statsForm.setStartDay( FasooGmtUtils.format9( cal.getTime() ) );
		}

		String endDay = statsForm.getEndDay();
		try
		{
			FasooGmtUtils.parse( FasooGmtUtils.pattern9, endDay, TimeZone.getDefault() );
		}
		catch( Exception e )
		{
			statsForm.setEndDay( FasooGmtUtils.format9( new Date() ) );
		}

	}

	public ActionForward statsUserToner( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsUser> statsList = selectTopUser( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tco.user" );
	}

	public ActionForward statsDeptToner( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDept> statsList = selectTopDept( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tco.dept" );
	}

	public ActionForward statsDocToner( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDoc> statsList = selectTopDoc( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tco.doc" );
	}

	public ActionForward statsDateToner( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsDate> statsList = selectDateDay( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tco.date" );
	}

	public ActionForward statsMonthToner( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsDate> statsList = selectDateMonth( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tco.month" );
	}

	public ActionForward statsYearToner( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsDate> statsList = selectDateYear( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tco.year" );
	}
	
	public ActionForward statsUserColor( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsUser> statsList = selectTopUser( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tcocolor.user" );
	}

	public ActionForward statsDeptColor( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDept> statsList = selectTopDept( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tcocolor.dept" );
	}

	public ActionForward statsDocColor( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDoc> statsList = selectTopDoc( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tcocolor.doc" );
	}

	public ActionForward statsDateColor( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsDate> statsList = selectDateDay( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tcocolor.date" );
	}

	public ActionForward statsMonthColor( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsDate> statsList = selectDateMonth( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tcocolor.month" );
	}

	public ActionForward statsYearColor( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDate> statsList = selectDateYear( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tcocolor.year" );
	}
	
	public ActionForward statsUserNup( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsUser> statsList = selectTopUser( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tconup.user" );
	}

	public ActionForward statsDeptNup( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDept> statsList = selectTopDept( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tconup.dept" );
	}

	public ActionForward statsDocNup( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDoc> statsList = selectTopDoc( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tconup.doc" );
	}

	public ActionForward statsDateNup( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsDate> statsList = selectDateDay( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tconup.date" );
	}

	public ActionForward statsMonthNup( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		

		List<TcoStatsDate> statsList = selectDateMonth( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tconup.month" );
	}

	public ActionForward statsYearNup( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsTcoForm statsForm = (FutMotionStatsTcoForm)form;
		checkDayCondition( statsForm );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
		HttpSession httpSession = request.getSession();
		String userID = (String)httpSession.getAttribute( "USERID" );
		String dsdCode = statsForm.getDsdCode();

		if( dsdCode == null || "".equals( dsdCode ) || userID == null || "".equals( userID ) )
		{
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put( "dsdCode", statsForm.getDsdCode() );
		searchMap.put( "startDay", statsForm.getStartDay() );
		searchMap.put( "endDay", statsForm.getEndDay() );
		searchMap.put( "sortItem", statsForm.getSortItem() );
		// searchMap.put( "limitRowSize", Integer.parseInt( statsForm.getLimitRowSize() ) );
		TimeZone timezone = (TimeZone) httpSession.getAttribute( "USERTIMEZONE" );
		searchMap.put( "timeZoneId", timezone.getID() );
		
		
		List<TcoStatsDate> statsList = selectDateYear( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.tconup.year" );
	}

	public List<TcoStatsDate> selectDateDay( Map<String, Object> params )
	{

		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		String dsdCode = FutMapUtils.getString( params, "dsdCode", null );
		String startDay = FutMapUtils.getString( params, "startDay", null );
		String endDay = FutMapUtils.getString( params, "endDay", null );
		
		int limitRowSize = FutMapUtils.getInt( params, "limitRowSize", 0 );
		String timeZoneId = FutMapUtils.getString( params, "timeZoneId", null );
		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		RestTemplate client = new RestTemplate();
		List<TcoStatsDate> list = null;
		DSDConfig dsdConfig = factory.getDSDConfig(dsdCode);
		String targetURL = dsdConfig.getValue("FUTSERVER_URL");
		try
		{
			ObjectMapper om = new ObjectMapper();
		    om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
	     	String jsonResponseBody =  client.getForObject(targetURL + "/fut/api/eprint/stat/tco/day?dsdCode=" + dsdCode + "&startDate=" 
		    + startDay + "&endDate=" + endDay + "&rowCount=" + limitRowSize + "&timeZoneId=" + timeZoneId, String.class);
	     	list = om.readValue(jsonResponseBody, new TypeReference<List<TcoStatsDate>>(){});
		} catch (Exception e) {
			logger.error("Not connected Fut Server.", e);
		}
		return list;
	}

	public List<TcoStatsDate> selectDateMonth( Map<String, Object> params )
	{

		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		String dsdCode = FutMapUtils.getString( params, "dsdCode", null );
		String startDay = FutMapUtils.getString( params, "startDay", null );
		String endDay = FutMapUtils.getString( params, "endDay", null );

		int limitRowSize = FutMapUtils.getInt( params, "limitRowSize", 0 );
		String timeZoneId = FutMapUtils.getString( params, "timeZoneId", null );
		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		RestTemplate client = new RestTemplate();
		List<TcoStatsDate> list = null;
		DSDConfig dsdConfig = factory.getDSDConfig(dsdCode);
		String targetURL = dsdConfig.getValue("FUTSERVER_URL");
		try
		{
			ObjectMapper om = new ObjectMapper();
		    om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
	     	String jsonResponseBody =  client.getForObject(targetURL + "/fut/api/eprint/stat/tco/month?dsdCode=" + dsdCode + "&startDate=" 
		    + startDay + "&endDate=" + endDay + "&rowCount=" + limitRowSize + "&timeZoneId=" + timeZoneId, String.class);
	     	list = om.readValue(jsonResponseBody, new TypeReference<List<TcoStatsDate>>(){});
		}catch (Exception e) {
			logger.error("Not connected Fut Server.", e);
		}
		return list;
	}

	public List<TcoStatsDate> selectDateYear( Map<String, Object> params )
	{

		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		String dsdCode = FutMapUtils.getString( params, "dsdCode", null );
		String startDay = FutMapUtils.getString( params, "startDay", null );
		String endDay = FutMapUtils.getString( params, "endDay", null );

		int limitRowSize = FutMapUtils.getInt( params, "limitRowSize", 0 );
		String timeZoneId = FutMapUtils.getString( params, "timeZoneId", null );
		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		RestTemplate client = new RestTemplate();
		List<TcoStatsDate> list = null;
		DSDConfig dsdConfig = factory.getDSDConfig(dsdCode);
		String targetURL = dsdConfig.getValue("FUTSERVER_URL");
		try
		{
			ObjectMapper om = new ObjectMapper();
		    om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
	     	String jsonResponseBody =  client.getForObject( targetURL + "/fut/api/eprint/stat/tco/year?dsdCode=" + dsdCode + "&startDate=" 
		    + startDay + "&endDate=" + endDay + "&rowCount=" + limitRowSize + "&timeZoneId=" + timeZoneId, String.class);
	     	list = om.readValue(jsonResponseBody, new TypeReference<List<TcoStatsDate>>(){});
		}catch (Exception e) {
			logger.error("Not connected Fut Server.", e);
		}
		return list;
	}

	public List<TcoStatsDept> selectTopDept( Map<String, Object> params )
	{

		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		String dsdCode = FutMapUtils.getString( params, "dsdCode", null );
		String startDay = FutMapUtils.getString( params, "startDay", null );
		String endDay = FutMapUtils.getString( params, "endDay", null );

		String sortItem = FutMapUtils.getString( params, "sortItem", null );
		int limitRowSize = FutMapUtils.getInt( params, "limitRowSize", 0 );
		String timeZoneId = FutMapUtils.getString( params, "timeZoneId", null );
		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		RestTemplate client = new RestTemplate();
		List<TcoStatsDept> list = null;
		DSDConfig dsdConfig = factory.getDSDConfig(dsdCode);
		String targetURL = dsdConfig.getValue("FUTSERVER_URL");
		try
		{
			ObjectMapper om = new ObjectMapper();
		    om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
	     	String jsonResponseBody =  client.getForObject(targetURL + "/fut/api/eprint/stat/tco/dept?dsdCode=" + dsdCode + "&startDate=" 
		    + startDay + "&endDate=" + endDay + "&rowCount=" + limitRowSize + "&sortItem=" + sortItem + "&timeZoneId=" + timeZoneId, String.class);
	     	list = om.readValue(jsonResponseBody, new TypeReference<List<TcoStatsDept>>(){});
		}catch (Exception e) {
			logger.error("Not connected Fut Server.", e);
		}
		return list;
	}

	public List<TcoStatsDoc> selectTopDoc( Map<String, Object> params )
	{

		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		String dsdCode = FutMapUtils.getString( params, "dsdCode", null );
		String startDay = FutMapUtils.getString( params, "startDay", null );
		String endDay = FutMapUtils.getString( params, "endDay", null );

		String sortItem = FutMapUtils.getString( params, "sortItem", null );
		int limitRowSize = FutMapUtils.getInt( params, "limitRowSize", 0 );
		String timeZoneId = FutMapUtils.getString( params, "timeZoneId", null );
		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		RestTemplate client = new RestTemplate();
		List<TcoStatsDoc> list = null;
		DSDConfig dsdConfig = factory.getDSDConfig(dsdCode);
		String targetURL = dsdConfig.getValue("FUTSERVER_URL");
		try
		{
			ObjectMapper om = new ObjectMapper();
		    om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
	     	String jsonResponseBody =  client.getForObject(targetURL + "/fut/api/eprint/stat/tco/doc?dsdCode=" + dsdCode + "&startDate=" 
		    + startDay + "&endDate=" + endDay + "&rowCount=" + limitRowSize + "&sortItem=" + sortItem + "&timeZoneId=" + timeZoneId, String.class);
	     	list = om.readValue(jsonResponseBody, new TypeReference<List<TcoStatsDoc>>(){});
		}catch (Exception e) {
			logger.error("Not connected Fut Server.", e);
		}
		return list;
	}

	public List<TcoStatsUser> selectTopUser( Map<String, Object> params )
	{

		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		String dsdCode = FutMapUtils.getString( params, "dsdCode", null );
		String startDay = FutMapUtils.getString( params, "startDay", null );
		String endDay = FutMapUtils.getString( params, "endDay", null );

		String sortItem = FutMapUtils.getString( params, "sortItem", null );
		int limitRowSize = FutMapUtils.getInt( params, "limitRowSize", 0 );
		String timeZoneId = FutMapUtils.getString( params, "timeZoneId", null );
		//////////////////////////////////////////////////////////////////////
		//
		//////////////////////////////////////////////////////////////////////
		RestTemplate client = new RestTemplate();
		List<TcoStatsUser> list = null;
		DSDConfig dsdConfig = factory.getDSDConfig(dsdCode);
		String targetURL = dsdConfig.getValue("FUTSERVER_URL");
		try
		{
			ObjectMapper om = new ObjectMapper();
		    om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
	     	String jsonResponseBody =  client.getForObject(targetURL + "/fut/api/eprint/stat/tco/user?dsdCode=" + dsdCode 
	     			+ "&startDate=" + startDay + "&endDate=" + endDay + "&rowCount=" + limitRowSize + "&sortItem=" + sortItem + "&timeZoneId=" + timeZoneId, String.class);
	     	list = om.readValue(jsonResponseBody, new TypeReference<List<TcoStatsUser>>(){});
		} catch (Exception e) {
			logger.error("Not connected Fut Server.", e);
		}
		return list;
	}

}
