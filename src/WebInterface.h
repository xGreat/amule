/*  This file is part of aMule project
 *  
 *  aMule Copyright (C)2003-2004 aMule Team ( http://www.amule-project.net )
 *  This file Copyright (C)2003 Kry (elkry@sourceforge.net  http://www.amule-project.net)
 *  This file Copyright (C)2004 shakraw <shakraw@users.sourceforge.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H

#ifdef __WXMSW__
	#include <wx/msw/winundef.h>
#endif
#include <wx/wx.h>

#ifdef AMULEWEBDLG
	#include <wx/textdlg.h>
#else
	#include <wx/cmdline.h>
#endif

#ifndef WIN32
	#include "config.h"
#endif

#define theApp (*((CamulewebApp*)wxTheApp))


#ifndef AMULEWEBDLG
static const wxCmdLineEntryDesc cmdLineDesc[] = {
//	{ wxCMD_LINE_OPTION, "h", "help",  "show this help" },
	{ wxCMD_LINE_OPTION, wxT("rh"), wxT("remote-host"), wxT("host where aMule is running (default localhost)")},
	{ wxCMD_LINE_OPTION, wxT("p"), wxT("port"), wxT("aMule's port for External Connection"), wxCMD_LINE_VAL_NUMBER},
	{ wxCMD_LINE_NONE }
};
#endif


#ifdef AMULEWEBDLG //define frame dialog
class CamulewebFrame : public wxFrame {
	public:
		// ctor(s)
		CamulewebFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);

		// event handlers (these functions should _not_ be virtual)
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void OnCommandEnter(wxCommandEvent& event);
		void OnSize( wxSizeEvent& event );
		wxTextCtrl    *log_text;
		wxTextCtrl    *cmd_control;
	private:
		wxLog *logTargetOld;
		// any class wishing to process wxWindows events must use this macro
		DECLARE_EVENT_TABLE()
};
#endif


class CamulewebApp : public wxApp { 
	public:
		void 		Print(char *sFormat, ...);
		wxString	SendRecvMsg(const wxChar *msg);
#ifndef AMULEWEBDLG
		virtual int 	OnRun();
		virtual void 	OnInitCmdLine(wxCmdLineParser& amuleweb_parser) { amuleweb_parser.SetDesc(cmdLineDesc); }
		virtual bool 	OnCmdLineParsed(wxCmdLineParser& amuleweb_parser);
		void 		ParseCommandLine();
#else
		virtual bool	OnInit();
		int		OnExit();
		CamulewebFrame 	*frame;
#endif
		wxString 	sPort;
		wxString 	hostName;
};

#endif //WEBINTERFACE_H
