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

    //Reset flags
    param_flags = 0;

}

void THANEAsset::loadMainComms( wxCommandEvent& event ){
    wxFileDialog* OpenDialog2 = new wxFileDialog(this, _("Choose commodity file to open"), wxEmptyString, wxEmptyString,_("XML Files (*.xml)|*.xml"),wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog
    if (OpenDialog2->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
    {
        //Set m_ComListBox contents to names from commodity.xml
        SysC.load(OpenDialog2->GetPath());
        SysC.Parse();
        Commodity comm_temp;
        //Start adding names to m_ComListBox
        for(unsigned int i = 0; i < SysC.Commodities.size(); i++){
           comm_temp = SysC.Commodities.at(i);
            //Get name of system as string
            //Convert name from string to wxString
            m_ComListBox->AppendString(comm_temp.name);
        }
    }

}


void THANEAsset::OpenFile( wxCommandEvent& event ){
            wxFileDialog* OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,_("XML Files (*.xml)|*.xml"),wxFD_OPEN, wxDefaultPosition);

            // Creates a "open file" dialog with 4 file types
            if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
            {
                //Change Statusbar to display path of opened file
                SetStatusText(OpenDialog->GetPath(),0);

                //Set m_SysListBox contents to names from ssys.xml
                SysA.load(OpenDialog->GetPath());
                SysA.Parse();
                Asset assetsys;
                //Start adding names to m_SysListbox
                //Pointer to system
                for(unsigned int i = 0; i < SysA.Assets.size(); i++){
                   assetsys = SysA.Assets.at(i);
                    //Get name of system as string
                    m_AssetListBox->AppendString(assetsys.name);
                }
            }
                SetTitle(wxString("Edit - ", wxConvUTF8) <<OpenDialog->GetFilename()); // Set the Title to reflect the file open


        // Clean up after ourselves
        OpenDialog->Destroy();
  }

void THANEAsset::FileSave( wxCommandEvent& event )
{
    SysA.WriteChanges(); //Write Changes from object to XML tree

    wxFileDialog* SaveDialog = new wxFileDialog(this, _("Select Path to Save File"), wxEmptyString, wxEmptyString,_("XML Files (*.xml)|*.xml"),wxFD_SAVE, wxDefaultPosition);
    if (SaveDialog->ShowModal() == wxID_OK)
    {
        SysA.save(SaveDialog->GetPath());
    }


}


void THANEAsset::sys_click( wxCommandEvent& event ) {

    clear_params();

    //Get the index of the selected item
    int ind;
    ind = m_AssetListBox->GetSelection();

    wxString tmp_asset_nam;
  //  wxString tmp_x;
  //  wxString tmp_y;
    wxString tmp_tmp;
    wxString tmp_tmp2;

    tmp_asset_nam = SysA.Assets.at(ind).name;
  //  tmp_x << SysA.Assets.at(ind).x_pos;
  //  tmp_y << SysA.Assets.at(ind).y_pos;

    //Set the asset name textbox
    m_textPNAME->ChangeValue(tmp_asset_nam);

    //Set the X_pos textbok
    m_textPosX->ChangeValue(SysA.Assets.at(ind).x_pos);

    //Set the Y_pos textbox
    m_textPosY->ChangeValue(SysA.Assets.at(ind).y_pos);

    //Set the GFX_space textbox
    m_text_GFXSpace->ChangeValue(SysA.Assets.at(ind).gfx_space);
    //Set the GFX_space textbox
    m_text_GFXExt->ChangeValue(SysA.Assets.at(ind).gfx_ext);

    //Set the faction textbox and checkbox
    if(SysA.Assets.at(ind).pres_faction != wxT("n")){
        m_text_Faction->ChangeValue(SysA.Assets.at(ind).pres_faction);
        m_checkFac->SetValue(true);
    }
    else{
      //  m_text_Faction->
    }

    //Set the value textbox
  //  tmp_tmp << SysA.Assets.at(ind).pres_value;
    m_text_PresVal->ChangeValue(SysA.Assets.at(ind).pres_value);
    //Set the range textbox
   // tmp_tmp2 << SysA.Assets.at(ind).pres_range;
    m_text_PresRange->ChangeValue(SysA.Assets.at(ind).pres_range);

    //Set the Class and Population Boxes

    tmp_tmp = SysA.Assets.at(ind).planet_class;
    m_text_Class->ChangeValue(tmp_tmp);

    tmp_tmp = wxT(""); //Clear it

   // tmp_tmp << SysA.Assets.at(ind).population;

    m_text_Population->ChangeValue(SysA.Assets.at(ind).population);

    //Set Services Checkboxes
    m_checkBoxLand->SetValue(SysA.Assets.at(ind).land);
    m_checkBoxRefuel->SetValue(SysA.Assets.at(ind).refuel);
    m_checkBoxBar->SetValue(SysA.Assets.at(ind).bar);
    m_checkBoxMissions->SetValue(SysA.Assets.at(ind).missions);
    m_checkBoxCommodity->SetValue(SysA.Assets.at(ind).commodity);
    m_checkBoxOutfits->SetValue(SysA.Assets.at(ind).outfits);
    m_checkBoxShipyard->SetValue(SysA.Assets.at(ind).shipyard);

    //Set the description textboxes
    m_textLandingDescription->ChangeValue(SysA.Assets.at(ind).description);
    m_textBarDescription->ChangeValue(SysA.Assets.at(ind).bar_description);
}

void THANEAsset::ChangeMade( wxCommandEvent& event){

    //Enable 'Save Changes' Button
    m_AssetSaveChanges->Enable(true);

}

//And now, the name and parameter changing functions
void THANEAsset::Name_Changed( wxCommandEvent& event ){
    //Check if user modfied name box
    if(m_textPNAME->IsModified()){
        //Wait for focus to leave box
        //TODO

        //Get index of selection in asset list box
        int ind;
        ind = m_AssetListBox->GetSelection();

        //set name in object
        SysA.Assets.at(ind).name = m_textPNAME->GetValue();

        //set name in listbox by first inserting new name before last one, then deleting existing name off list
        //Insert new item
        m_AssetListBox->Insert(SysA.Assets.at(ind).name, ind+1);

        //Select new item
        m_AssetListBox->SetSelection(ind+1);
        //Delete old item
        m_AssetListBox->Delete(ind);
    }

}

void THANEAsset::GetChanges_Float(wxTextCtrl*& text_box, float &val){
    if(text_box->IsModified()){
        //Turn off 'modified' flag for GUI
        text_box->SetModified(false);
        //set name in object
        val = atof((text_box->GetValue()).mb_str());
    }
}

void THANEAsset::GetChanges_String(wxTextCtrl*& text_box, wxString &val){
    if(text_box->IsModified()){
        //Turn off 'modified' flag
        text_box->SetModified(false);
        //set name in object
        val = text_box->GetValue();
    }
}

void THANEAsset::SaveAssetChanges( wxCommandEvent& event ){

    //Get index of selection in asset list box
    int ind;
    ind = m_AssetListBox->GetSelection();

    //Save changes
    GetChanges_String(m_textPosX, SysA.Assets.at(ind).x_pos); //X Position
    GetChanges_String(m_textPosY, SysA.Assets.at(ind).y_pos); //Y Position
    GetChanges_String(m_text_GFXSpace, SysA.Assets.at(ind).gfx_space); //Space graphics
    GetChanges_String(m_text_GFXExt, SysA.Assets.at(ind).gfx_ext); //Ext graphics
    //Disable "Save Changes button"
    m_AssetSaveChanges->Enable(false);

    //Set 'modified' flag in Asset object
    SysA.Assets.at(ind).IsModified = true;
}

  void THANEFrame::SetNaevDir_ev( wxCommandEvent& event ) {
    //TODO
    wxFileDialog* OpenDialog = new wxFileDialog(this, _("Select the Naev Executable"), wxEmptyString, wxEmptyString,_("Naev Executable|naev*"),wxFD_OPEN, wxDefaultPosition);
    if (OpenDialog->ShowModal() == wxID_OK){
    }

  }


