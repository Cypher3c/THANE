/***************************************************************
 * Name:      NUEMain.h
 * Purpose:   Defines Application Frame
 * Author:    Cypher ()
 * Created:   2010-10-02
 * Copyright: Cypher ()
 * License:
 **************************************************************/
#include "System.h"
#ifndef NUEMAIN_H
#define NUEMAIN_H


#include "NUEApp.h"
#include "GUIFrame.h"
#include "System.h"
#include <wx/wx.h>

class NUEFrame: public GUIFrame
{
    public:
        NUEFrame(wxFrame *frame);
        ~NUEFrame();

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
                SysX.load(OpenDialog->GetPath());
                SSystem tempsys;
                //Start adding names to m_SysListbox
                //Pointer to system
                wxString temp_rad;
                for(int i = 0; i < SysX.Sys.size(); i++){
                    tempsys = SysX.Sys.at(i);
                    //Get name of system as string
                    //Convert name from string to wxString
                    m_SysListBox->AppendString(tempsys.name);
                }
                // MainEditBox->LoadFile(CurrentDocPath); //Opens that file
            }
                //SetTitle(wxString("Edit - ") <<OpenDialog->GetFilename()); // Set the Title to reflect the file open


        // Clean up after ourselves
        OpenDialog->Destroy();


        }
        //Handle clicking on a system
        virtual void sys_click( wxCommandEvent& event ) {
            //Get the index of the selected item
            int ind;
            ind = m_SysListBox->GetSelection();

            wxString tmp_sys_nam;
            wxString tmp_rad;

            tmp_sys_nam = SysX.Sys.at(ind).name;
            tmp_rad << SysX.Sys.at(ind).radius;

            //Set the system name listbox
            m_textPNAME->ChangeValue(tmp_sys_nam);

            //Set the radius listbox
            m_textRadius->ChangeValue(tmp_rad);

        }
};

#endif // NUEMAIN_H
