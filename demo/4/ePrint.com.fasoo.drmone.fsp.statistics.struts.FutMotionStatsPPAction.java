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
public class FutMotionStatsPPAction extends DispatchAction {

	private Log logger = LogFactory.getLog( FutMotionStatsPPAction.class );

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

	private void checkDayCondition( FutMotionStatsPPForm statsForm )
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

	public ActionForward statsUser( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsPPForm statsForm = (FutMotionStatsPPForm)form;
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

		TcoStats statsTcoApi = new TcoStats();
		List<TcoStatsUser> statsList = statsTcoApi.selectTopUser( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.pp.user" );
	}

	public ActionForward statsDept( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsPPForm statsForm = (FutMotionStatsPPForm)form;
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

		TcoStats statsTcoApi = new TcoStats();
		List<TcoStatsDept> statsList = statsTcoApi.selectTopDept( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.pp.dept" );
	}

	public ActionForward statsDoc( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception
	{
		FutMotionStatsPPForm statsForm = (FutMotionStatsPPForm)form;
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

		TcoStats statsTcoApi = new TcoStats();
		List<TcoStatsDoc> statsList = statsTcoApi.selectTopDoc( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.pp.doc" );
	}

	public ActionForward statsDate( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {

		FutMotionStatsPPForm statsForm = (FutMotionStatsPPForm)form;
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

		TcoStats statsTcoApi = new TcoStats();
		List<TcoStatsDate> statsList = statsTcoApi.selectDateDay( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.pp.date" );
	}

	public ActionForward statsMonth( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {

		FutMotionStatsPPForm statsForm = (FutMotionStatsPPForm)form;
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

		TcoStats statsTcoApi = new TcoStats();
		List<TcoStatsDate> statsList = statsTcoApi.selectDateMonth( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.pp.month" );
	}

	public ActionForward statsYear( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {

		FutMotionStatsPPForm statsForm = (FutMotionStatsPPForm)form;
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

		TcoStats statsTcoApi = new TcoStats();
		List<TcoStatsDate> statsList = statsTcoApi.selectDateYear( searchMap );

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "STATSLIST", statsList );

		return mapping.findForward( "fsp.motionstats.pp.year" );
	}
}
