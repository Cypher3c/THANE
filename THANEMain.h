/***************************************************************
 * Name:      THANEMain.h
 * Purpose:   Defines Application Frame
 * Author:    Cypher ()
 * Created:   2010-10-02
 * Copyright: Cypher ()
 * License:
 **************************************************************/
#ifndef THANEMAIN_H
#define THANEMAIN_H
#include "System.h"
#include "THANEApp.h"
#include "GUIFrame.h"

#include <wx/wx.h>


class THANEAsset : public AssetEd
{
    public:
        THANEAsset(wxFrame *frame): AssetEd(frame){}
        ~THANEAsset(){};

        //Xml object
        XmlO SysX;
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);

        //Open File Event
        virtual void OpenFile( wxCommandEvent& event ){
            wxFileDialog* OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,_("XML Files (*.xml)|*.xml"),wxFD_OPEN, wxDefaultPosition);

            // Creates a "open file" dialog with 4 file types
            if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
            {
                //Change Statusbar to display path of opened file
                SetStatusText(OpenDialog->GetPath(),0);

                //Set m_SysListBox contents to names from ssys.xml
                SysX.load(OpenDialog->GetPath(), 1);
                Asset assetsys;
                //Start adding names to m_SysListbox
                //Pointer to system
                for(int i = 0; i < SysX.Sys.size(); i++){
                   assetsys = SysX.Sys.at(i);
                    //Get name of system as string
                    //Convert name from string to wxString
                    m_AssetListBox->AppendString(assetsys.name);
                }
                // MainEditBox->LoadFile(CurrentDocPath); //Opens that file
            }
                //SetTitle(wxString("Edit - ") <<OpenDialog->GetFilename()); // Set the Title to reflect the file open


        // Clean up after ourselves
        OpenDialog->Destroy();


        }
        //Handle clicking on a system
        virtual void sys_click( wxCommandEvent& event );

        void clear_params();
};


class THANEFrame: public GUIFrame
{
    public:
        THANEFrame(wxFrame *frame);
        ~THANEFrame();

    private:
        virtual void SetNaevDir_ev( wxCommandEvent& event );

        //Launch Asset Editor
        virtual void launch_asset_ed( wxCommandEvent& event ) {
            THANEAsset* asset_ed_frame = new THANEAsset(0L);
        //    asset_ed_frame->SetIcon(wxICON(aaaa)); // To Set App Icon

          //Show Asset Editor Frame
            asset_ed_frame->Show();

        }
};

#endif // THANEMAIN_H
