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
                //Convert path from wxString to std::String
                std::string pathp = std::string(OpenDialog->GetPath().mb_str());
                //Set m_SysListBox contents to names from ssys.xml
                SysX.load("c:\\ssys.xml"); //Crashing here
                //Start adding names to m_SysListbox
               // unsigned int vecsize = SysX.Sys.size(); //Aha, vector size is a problem
                for(int i = 0; i <= 3; i++){
                    //Convert name from string to wxString
                    //  const char *tempstr =
                    //Convert Sys name to string
                  //  const char* SysStr = SysX.Sys.at(2).name.c_str();
                  //  wxString Sysnam = wxString("Hello", wxConvUTF8);
                  //  m_SysListBox->AppendString(Sysnam);
                }
                // MainEditBox->LoadFile(CurrentDocPath); //Opens that file
                //SetTitle(wxString("Edit - ") <<OpenDialog->GetFilename()); // Set the Title to reflect the file open
            }

        // Clean up after ourselves
        OpenDialog->Destroy();


        }
};

#endif // NUEMAIN_H
