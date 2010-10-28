/***************************************************************
 * Name:      THANEMain.cpp
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

#include <wx/bitmap.h>
#include "THANEMain.h"

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


THANEFrame::THANEFrame(wxFrame *frame)
: GUIFrame(frame)
{
#if wxUSE_STATUSBAR
//    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
 //   statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif

}

THANEFrame::~THANEFrame()
{
}

void THANEAsset::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void THANEAsset::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void THANEAsset::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void THANEAsset::clear_params(){

    //Clear textboxes and checkboxes
    m_textPNAME->ChangeValue(wxT(""));
    m_textPosX->ChangeValue(wxT(""));
    m_textPosY->ChangeValue(wxT(""));
    m_text_GFXSpace->ChangeValue(wxT(""));
    m_text_GFXExt->ChangeValue(wxT(""));
    m_text_Faction->ChangeValue(wxT(""));
    m_checkFac->SetValue(false);
    m_text_PresVal->ChangeValue(wxT(""));
    m_text_PresRange->ChangeValue(wxT(""));
    m_text_Class->ChangeValue(wxT(""));
    m_text_Population->ChangeValue(wxT(""));
    m_checkBoxLand->SetValue(false);
    m_checkBoxRefuel->SetValue(false);
    m_checkBoxBar->SetValue(false);
    m_checkBoxMissions->SetValue(false);
    m_checkBoxCommodity->SetValue(false);
    m_checkBoxOutfits->SetValue(false);
    m_checkBoxShipyard->SetValue(false);
    m_textLandingDescription->ChangeValue(wxT(""));
    m_textBarDescription->ChangeValue(wxT(""));

}


void THANEAsset::sys_click( wxCommandEvent& event ) {

    clear_params();

    //Get the index of the selected item
    int ind;
    ind = m_AssetListBox->GetSelection();

    wxString tmp_asset_nam;
    wxString tmp_x;
    wxString tmp_y;
    wxString tmp_tmp;
    wxString tmp_tmp2;

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
    tmp_tmp2 << SysX.Sys.at(ind).pres_range;
    m_text_PresRange->ChangeValue(tmp_tmp2);

    //Set the Class and Population Boxes

    tmp_tmp = SysX.Sys.at(ind).planet_class;
    m_text_Class->ChangeValue(tmp_tmp);

    tmp_tmp = wxT(""); //Clear it

    tmp_tmp << SysX.Sys.at(ind).population;

    m_text_Population->ChangeValue(tmp_tmp);

    //Set Services Checkboxes
    m_checkBoxLand->SetValue(SysX.Sys.at(ind).land);
    m_checkBoxRefuel->SetValue(SysX.Sys.at(ind).refuel);
    m_checkBoxBar->SetValue(SysX.Sys.at(ind).bar);
    m_checkBoxMissions->SetValue(SysX.Sys.at(ind).missions);
    m_checkBoxCommodity->SetValue(SysX.Sys.at(ind).commodity);
    m_checkBoxOutfits->SetValue(SysX.Sys.at(ind).outfits);
    m_checkBoxShipyard->SetValue(SysX.Sys.at(ind).shipyard);

    //Set the description textboxes
    m_textLandingDescription->ChangeValue(SysX.Sys.at(ind).description);
    m_textBarDescription->ChangeValue(SysX.Sys.at(ind).bar_description);
/*
    //Set the bitmap
    //get path
    wxString tmp_path = wxT("c:\\NaevDev\\naev\\gfx\\planet\\space\\");
    const wxString tmp_path3 = tmp_path + SysX.Sys.at(ind).gfx_space;
    //wxBitmapHandler tmp_bit_hand;
    wxBitmap tmp_bit;
    tmp_bit.LoadFile(tmp_path3, wxBITMAP_TYPE_BMP);

   // tmp_bit_hand.LoadFile(&tmp_bit, tmp_path3);
*/
    //TODO
  //  m_bpAssetPrev->SetBitmapLabel(tmp_bit}
}

  void THANEFrame::SetNaevDir_ev( wxCommandEvent& event ) {
    //TODO
    wxFileDialog* OpenDialog = new wxFileDialog(this, _("Select the Naev Executable"), wxEmptyString, wxEmptyString,_("Naev Executable|naev*"),wxFD_OPEN, wxDefaultPosition);
    if (OpenDialog->ShowModal() == wxID_OK){

    }

  }

