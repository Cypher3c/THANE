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
enum wxbuildinfoformat {short_f, long_f };

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
//    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
 //   statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif

}

NUEFrame::~NUEFrame()
{
}

void NUEAsset::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void NUEAsset::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void NUEAsset::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void NUEAsset::sys_click( wxCommandEvent& event ) {

    //Set Faction Check box to off
    m_checkFac->SetValue(false);
    //Get the index of the selected item
    int ind;
    ind = m_AssetListBox->GetSelection();

    wxString tmp_asset_nam;
    wxString tmp_x;
    wxString tmp_y;
    wxString tmp_tmp;

    tmp_asset_nam = SysX.Sys.at(ind).name;
    tmp_x << SysX.Sys.at(ind).x_pos;
    tmp_y << SysX.Sys.at(ind).y_pos;

    //Set the asset name textbox
    m_textPNAME->ChangeValue(tmp_asset_nam);

    //Set the X_pos textbok
    m_textPosX->ChangeValue(tmp_x);

    //Set the Y_pos textbox
    m_textPosY->ChangeValue(tmp_y);

    //Set the GFX_space textbox
    m_text_GFXSpace->ChangeValue(SysX.Sys.at(ind).gfx_space);
    //Set the GFX_space textbox
    m_text_GFXExt->ChangeValue(SysX.Sys.at(ind).gfx_ext);

    //Set the faction textbox and checkbox
    if(SysX.Sys.at(ind).pres_faction != wxT("n")){
        m_text_Faction->ChangeValue(SysX.Sys.at(ind).pres_faction);
        m_checkFac->SetValue(true);
    }
    else{
      //  m_text_Faction->
    }

    //Set the value textbox
    tmp_tmp << SysX.Sys.at(ind).pres_value;
    m_text_PresVal->ChangeValue(tmp_tmp);
    //Set the range textbox
    tmp_tmp << SysX.Sys.at(ind).pres_range;
    m_text_PresVal->ChangeValue(tmp_tmp);

}
