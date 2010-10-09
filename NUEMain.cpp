/***************************************************************
 * Name:      NUEMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Cypher ()
 * Created:   2010-10-02
 * Copyright: Cypher ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "NUEMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


NUEFrame::NUEFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif

}

NUEFrame::~NUEFrame()
{
}

void NUEFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void NUEFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void NUEFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

