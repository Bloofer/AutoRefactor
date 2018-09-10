package com.fasoo.drmone.usage.struts;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.TimeZone;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.fasoo.drmone.message.ServerMessage;
import com.fasoo.drmone.usage.bl.HistoryLogBL;
import com.fasoo.drmone.usage.bl.HistoryLogBeans;
import com.fasoo.drmone.usage.bl.HistoryLogID;
import com.fasoo.logging.Log;
import com.fasoo.logging.LogFactory;
import com.fasoo.util.DateUtil;
import com.fasoo.util.StringUtil;

public class HistoryLogAction extends DispatchAction {

	private Log logger = LogFactory.getLog( HistoryLogAction.class );

	private int rawOffset = 0;

	/**
         * <p>
         * Returns the parameter value.
         * </p>
         * 
         * @param mapping
         *                The ActionMapping used to select this instance
         * @param form
         *                The optional ActionForm bean for this request (if any)
         * @param request
         *                The HTTP request we are processing
         * @param response
         *                The HTTP response we are creating
         * @return The <code>ActionMapping</code> parameter's value
         * @throws Exception
         *                 if the parameter is missing.
         */
	protected String getParameter( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {
		// Identify the request parameter containing the method name
		String parameter = mapping.getParameter();

		if( parameter == null ) {
			String message = messages.getMessage( "dispatch.handler", mapping.getPath() );

			logger.errorString( message );

			throw new ServletException( message );
		}
		return parameter;
	}

	/**
         * Returns the method name, given a parameter's value.
         * 
         * @param mapping
         *                The ActionMapping used to select this instance
         * @param form
         *                The optional ActionForm bean for this request (if any)
         * @param request
         *                The HTTP request we are processing
         * @param response
         *                The HTTP response we are creating
         * @param parameter
         *                The <code>ActionMapping</code> parameter's name
         * 
         * @return The method's name.
         * @since Struts 1.2.0
         */
	protected String getMethodName( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response, String parameter ) throws Exception {

		// Identify the method name to be dispatched to.
		// dispatchMethod() will call unspecified() if name is null
		return request.getParameter( parameter );
	}

	public ActionForward execute( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {
		if( isCancelled( request ) ) {
			return null;
		}
		// Default Method 吏???
		// Get the parameter. This could be overridden in subclasses.
		String parameter = getParameter( mapping, form, request, response );

		// Get the method's name. This could be overridden in
		// subclasses.
		String name = getMethodName( mapping, form, request, response, parameter );

		if( name == null || "".equals( name ) ) {
			name = "list";
		}
		// Prevent recursive calls
		if( "execute".equals( name ) || "perform".equals( name ) ) {
			String message = messages.getMessage( "dispatch.recursive", mapping.getPath() );

			logger.errorString( message );
			throw new ServletException( message );
		}
		setRawOffset( request.getSession() );

		// Invoke the named method, and return the result
		return dispatchMethod( mapping, form, request, response, name );
	}
	
	public ActionForward detailPage( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {
		HistoryLogForm historyLogForm = ( HistoryLogForm ) form;
		String dsdCode = historyLogForm.getDsdCode();
		
		HistoryLogBL historyLogBL = null;
		HistoryLogID historyLogListID = null;
		try {
			HistoryLogID historyLogID = ( HistoryLogID ) setIdentity( form, request.getSession() );

			historyLogBL = new HistoryLogBL();
			historyLogID.setDsdCode( dsdCode );
			historyLogListID = historyLogBL.detailData( historyLogID );

		} catch( Exception e ) {
			logger.errorString( "list", e.toString() );
			logger.trace( "list", e );

			// Report the error using the appropriate name and ID.
			request.setAttribute( "ERROR.MESSAGE", ServerMessage.getMessage( request.getLocale(), "error.KNOWN" ) );
		}
		
		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "HISTORYLOGLIST", historyLogListID );
		
		return mapping.findForward( "usage.historylog.historylog_detail" );
	}
	public ActionForward list( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {
		HistoryLogForm historyLogForm = ( HistoryLogForm ) form;

		HttpSession httpSession = request.getSession();
		String userID = ( String ) httpSession.getAttribute( "USERID" );

		String dsdCode = historyLogForm.getDsdCode();

		if( userID == null || "".equals( userID ) ) {
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		HistoryLogBL historyLogBL = null;
		HistoryLogID historyLogListID = null;
		try {
			HistoryLogID historyLogID = ( HistoryLogID ) setIdentity( form, request.getSession() );

			historyLogBL = new HistoryLogBL();
			historyLogID.setDsdCode( dsdCode );
			historyLogID.setProductType( historyLogForm.getProductType() );
			historyLogListID = historyLogBL.list( historyLogID );

			List logList = historyLogListID.list();
			/*
			for( int i = 0; i < logList.size(); i++ ) {
				HistoryLogBeans logBeans = ( HistoryLogBeans ) logList.get( i );
				logBeans.setObjDesc( getStringLabel( request, "history." + logBeans.getObjType() ) );
			}
			*/
			processForView( request, logList );
		} catch( Exception e ) {
			logger.errorString( "list", e.toString() );
			logger.trace( "list", e );

			// Report the error using the appropriate name and ID.
			request.setAttribute( "ERROR.MESSAGE", ServerMessage.getMessage( request.getLocale(), "error.KNOWN" ) );
		}

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "HISTORYLOGLIST", historyLogListID );

		return mapping.findForward( "usage.historylog.historylog_list" );
	}

	public ActionForward logexport( ActionMapping mapping, ActionForm form, HttpServletRequest request, HttpServletResponse response ) throws Exception {
		HistoryLogForm historyLogForm = ( HistoryLogForm ) form;

		HttpSession httpSession = request.getSession();
		String userID = ( String ) httpSession.getAttribute( "USERID" );

		String dsdCode = historyLogForm.getDsdCode();

		if( userID == null || "".equals( userID ) ) {
			request.setAttribute( "AUTHACTION", ServerMessage.getMessage( request.getLocale(), "msg.need.auth" ) );
			return mapping.findForward( "NEEDAUTH" );
		}

		HistoryLogBL historyLogBL = null;
		HistoryLogID historyLogListID = null;
		try {
			HistoryLogID historyLogID = ( HistoryLogID ) setIdentity( form, request.getSession() );

			historyLogBL = new HistoryLogBL();
			historyLogID.setDsdCode( dsdCode );
			historyLogID.setProductType( historyLogForm.getProductType() );
			historyLogListID = historyLogBL.list( historyLogID );

			List logList = historyLogListID.list();
			/*
			for( int i = 0; i < logList.size(); i++ ) {
				HistoryLogBeans logBeans = ( HistoryLogBeans ) logList.get( i );
				logBeans.setObjDesc( getStringLabel( request, "history." + logBeans.getObjType() ) );
			}
			*/
			processForView( request, logList );
		} catch( Exception e ) {
			logger.errorString( "list", e.toString() );
			logger.trace( "list", e );

			// Report the error using the appropriate name and ID.
			request.setAttribute( "ERROR.MESSAGE", ServerMessage.getMessage( request.getLocale(), "error.KNOWN" ) );
		}

		request.setAttribute( "ACTIONFORM", form );
		request.setAttribute( "HISTORYLOGLIST", historyLogListID );

		return mapping.findForward( "usage.historylog.log_export" );
	}
	
	private HistoryLogID setIdentity( ActionForm actionForm, HttpSession httpSession ) {
		HistoryLogForm historyLogForm = ( HistoryLogForm ) actionForm;

		HistoryLogID historyLogListID = new HistoryLogID();

		historyLogListID.setDsdCode( historyLogForm.getDsdCode() );
		historyLogListID.setHistoryNo(historyLogForm.getHistoryNo());
		
		historyLogListID.setActorID( historyLogForm.getActorID() );
		historyLogListID.setActorName( historyLogForm.getActorName() );
		
		historyLogListID.setActorIP(historyLogForm.getActorIP());
		historyLogListID.setActorMenu(historyLogForm.getActorMenu());
		historyLogListID.setActorType(historyLogForm.getActorType());
		historyLogListID.setKeyName(historyLogForm.getKeyName());
		historyLogListID.setKeyValue(historyLogForm.getKeyValue());
		historyLogListID.setHistoryDataNoOld(historyLogForm.getHistoryDataNoOld());
		historyLogListID.setHistoryDataNoNew(historyLogForm.getHistoryDataNoNew());
		historyLogListID.setProductType(historyLogForm.getProductType());

		historyLogListID.setPageNo( Integer.parseInt( StringUtil.toString( historyLogForm.getPageNo(), "0" ) ) );
		historyLogListID.setPerPage( Integer.parseInt( StringUtil.toString( historyLogForm.getPerPage(), "0" ) ) );

		// # use user's local timezone - hyhan 2013.05.22
		TimeZone userTimeZone = null;
		if( httpSession != null )
			userTimeZone = ( TimeZone ) httpSession.getAttribute( "USERTIMEZONE" );
			
		historyLogListID.setStartDate( DateUtil.toSearchStartDate( historyLogForm.getStartDate(), historyLogForm.getStartDateHour(), historyLogForm.getStartDateMinute(), userTimeZone ) );
		historyLogListID.setEndDate( DateUtil.toSearchEndDate( historyLogForm.getEndDate(), historyLogForm.getEndDateHour(), historyLogForm.getEndDateMinute(), userTimeZone ) );

		return historyLogListID;
	}

	private Date getDateFromString( String strDate, String strHour, String strMinute, boolean isStartDate ) {
		Date returnDate = null;
		Calendar cal = Calendar.getInstance();
		TimeZone tz = TimeZone.getDefault();

		tz.setRawOffset( this.rawOffset );
		cal = Calendar.getInstance( tz );

		if( strDate == null || strDate.equals( "" ) ) {
			if( isStartDate ) {
				cal.set( Calendar.HOUR_OF_DAY, 0 );
				cal.set( Calendar.MINUTE, 0 );
				cal.set( Calendar.SECOND, 0 );
				cal.set( Calendar.MILLISECOND, 0 );
			} else {
				cal.set( Calendar.HOUR_OF_DAY, 23 );
				cal.set( Calendar.MINUTE, 59 );
				cal.set( Calendar.SECOND, 59 );
				cal.set( Calendar.MILLISECOND, 59 );
			}
			returnDate = cal.getTime();
		} else {
			try {
				SimpleDateFormat sdf = new SimpleDateFormat( "yyyy-MM-dd" );
				sdf.setTimeZone( tz );
				returnDate = sdf.parse( strDate );
				cal.setTime( returnDate );
				if( isStartDate ) {
					cal.set( Calendar.HOUR_OF_DAY, Integer.parseInt(strHour) );
					cal.set( Calendar.MINUTE, Integer.parseInt(strMinute) );
					cal.set( Calendar.SECOND, 0 );
					cal.set( Calendar.MILLISECOND, 0 );
				} else {
					cal.set( Calendar.HOUR_OF_DAY, Integer.parseInt(strHour) );
					cal.set( Calendar.MINUTE, Integer.parseInt(strMinute) );
					cal.set( Calendar.SECOND, 59 );
					cal.set( Calendar.MILLISECOND, 59 );
				}
				returnDate = cal.getTime();
			} catch( ParseException pe ) {
				if( isStartDate ) {
					cal.set( Calendar.HOUR_OF_DAY, 0 );
					cal.set( Calendar.MINUTE, 0 );
					cal.set( Calendar.SECOND, 0 );
					cal.set( Calendar.MILLISECOND, 0 );
				} else {
					cal.set( Calendar.HOUR_OF_DAY, 23 );
					cal.set( Calendar.MINUTE, 59 );
					cal.set( Calendar.SECOND, 59 );
					cal.set( Calendar.MILLISECOND, 59 );
				}
				returnDate = cal.getTime();
			}
		}
		return returnDate;
	}

	private void processForView( HttpServletRequest request, List historyLogList ) {
		HistoryLogBeans historyLogBeans = null;

		if(historyLogList == null)
			return;
		
		// # use user's local timezone - hyhan 2013.05.22
		TimeZone userTimeZone = null;
		HttpSession httpSession = request.getSession();
		if( httpSession != null )
			userTimeZone = ( TimeZone ) httpSession.getAttribute( "USERTIMEZONE" );
		
		for( Iterator iterator = historyLogList.iterator(); iterator.hasNext(); ) {
			historyLogBeans = ( HistoryLogBeans ) iterator.next();
			historyLogBeans.setStrEntryTS( DateUtil.toString( historyLogBeans.getEntryTS(), "yyyy-MM-dd HH:mm:ss", userTimeZone ) );
		}
	}

	private String getDateStr( Date date, String dateFormat ) {
		SimpleDateFormat sdf = null;
		String defaultDateFormat = "yyyy-MM-dd HH:mm:ss";

		if( dateFormat == null || "".equals( dateFormat ) ) {
			dateFormat = defaultDateFormat;
		}

		sdf = new SimpleDateFormat( dateFormat );
		{
			TimeZone tz = TimeZone.getDefault();
			tz.setRawOffset( this.rawOffset );

			sdf.setTimeZone( tz );
		}
		return sdf.format( date );
	}

	private String getStringLabel( HttpServletRequest request, String labelKey ) {
		String strLabel = null;

		try {
			strLabel = ServerMessage.getMessage( request.getLocale(), labelKey );
		} catch( Exception e ) {
			return "";
		}
		return strLabel;
	}

	private void setRawOffset( HttpSession httpSession ) {
		String strRawOffset = ( String ) httpSession.getAttribute( "RAWOFFSET" );

		try {
			this.rawOffset = Integer.parseInt( strRawOffset );
		} catch( NumberFormatException nfe ) {
			this.rawOffset = TimeZone.getDefault().getRawOffset();
		}
	}
}
