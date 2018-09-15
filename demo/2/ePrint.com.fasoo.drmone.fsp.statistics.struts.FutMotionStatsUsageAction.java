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

import com.fasoo.logging.Log;
import com.fasoo.logging.LogFactory;
import com.fasoo.server.ServerConfig;

import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.fasoo.fut.beans.UsageStatsDate;
import com.fasoo.fut.beans.UsageStatsDept;
import com.fasoo.fut.beans.UsageStatsDoc;
import com.fasoo.fut.beans.UsageStatsUser;
import com.fasoo.api.server.drmone.stats.UsageStats;
import com.fasoo.commons.gmtdate.FasooGmtUtils;
import com.fasoo.drmone.message.ServerMessage;

public class FutMotionStatsUsageAction extends DispatchAction
{
	private Log logger = LogFactory.getLog( FutMotionStatsUsageAction.class );

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
			name = "statsUser";
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

	private void checkDayCondition( FutMotionStatsUsageForm statsForm, TimeZone userTimeZone )
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
			if( userTimeZone != null )
				statsForm.setStartDay( FasooGmtUtils.format9( cal.getTime(), userTimeZone ) );
			else
				statsForm.setStartDay( FasooGmtUtils.format9( cal.getTime() ) );
		}

		String endDay = statsForm.getEndDay();
		try
		{
			FasooGmtUtils.parse( FasooGmtUtils.pattern9, endDay, TimeZone.getDefault() );
		}
		catch( Exception e )
		{
			if( userTimeZone != null )
				statsForm.setEndDay( FasooGmtUtils.format9( new Date(), userTimeZone ) );
			else
				statsForm.setEndDay( FasooGmtUtils.format9( new Date() ) );
		}

	}

	public ActionForward statsUser( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsUsageForm statsForm = (FutMotionStatsUsageForm)form;
		HttpSession httpSession = request.getSession();
		
		checkDayCondition( statsForm, (TimeZone) httpSession.getAttribute( "USERTIMEZONE" ) );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
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
		
		UsageStats statsUsageApi = new UsageStats();
		List<UsageStatsUser> statsList = statsUsageApi.selectTopUser( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.usage.user" );
	}

	public ActionForward statsDept( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsUsageForm statsForm = (FutMotionStatsUsageForm)form;
		HttpSession httpSession = request.getSession();
		
		checkDayCondition( statsForm, (TimeZone) httpSession.getAttribute( "USERTIMEZONE" ) );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
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
		
		UsageStats statsUsageApi = new UsageStats();
		List<UsageStatsDept> statsList = statsUsageApi.selectTopDept( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.usage.dept" );
	}

	public ActionForward statsDoc( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {

		FutMotionStatsUsageForm statsForm = (FutMotionStatsUsageForm)form;
		HttpSession httpSession = request.getSession();
		
		checkDayCondition( statsForm, (TimeZone) httpSession.getAttribute( "USERTIMEZONE" ) );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
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
		
		UsageStats statsUsageApi = new UsageStats();
		List<UsageStatsDoc> statsList = statsUsageApi.selectTopDoc( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.usage.doc" );
	}

	public ActionForward statsDate( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {

		FutMotionStatsUsageForm statsForm = (FutMotionStatsUsageForm)form;
		HttpSession httpSession = request.getSession();
		
		checkDayCondition( statsForm, (TimeZone) httpSession.getAttribute( "USERTIMEZONE" ) );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
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
		
		UsageStats statsUsageApi = new UsageStats();
		List<UsageStatsDate> statsList = statsUsageApi.selectDateDay( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.usage.date" );
	}

	public ActionForward statsMonth( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {

		FutMotionStatsUsageForm statsForm = (FutMotionStatsUsageForm)form;
		HttpSession httpSession = request.getSession();
		
		checkDayCondition( statsForm, (TimeZone) httpSession.getAttribute( "USERTIMEZONE" ) );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
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
		
		UsageStats statsUsageApi = new UsageStats();
		List<UsageStatsDate> statsList = statsUsageApi.selectDateMonth( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.usage.month" );
	}

	public ActionForward statsYear( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsUsageForm statsForm = (FutMotionStatsUsageForm)form;
		HttpSession httpSession = request.getSession();
		
		checkDayCondition( statsForm, (TimeZone) httpSession.getAttribute( "USERTIMEZONE" ) );
		
		/*
		 * hyhan - 2012.03.16
		 * 화면에서 받은 값을 사용하지 않고 drmone.xml에 정의된 값을 사용
		 */
		statsForm.setLimitRowSize( ServerConfig.getInstance().getValue( "STATIATICS_TOP_COUNT", "10" ) );
		
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
		
		UsageStats statsUsageApi = new UsageStats();
		List<UsageStatsDate> statsList = statsUsageApi.selectDateYear( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.usage.year" );
	}

}
