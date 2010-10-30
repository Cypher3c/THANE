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
        virtual void loadMainComms( wxCommandEvent& event );

        //Open File Event
        virtual void OpenFile( wxCommandEvent& event );
        //Handle clicking on a system
        virtual void sys_click( wxCommandEvent& event );

        void clear_params();
        virtual void Name_Changed( wxCommandEvent& event );
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
