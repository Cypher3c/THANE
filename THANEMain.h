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
        THANEAsset(wxFrame *frame): AssetEd(frame){
            param_flags = 0;

            }
        ~THANEAsset(){};

        //Xml object
        XmlO SysX;

        //Parameter flags, stored in hex int
        int Param_Flags;
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void FileSave( wxCommandEvent& event );
        virtual void OnAbout(wxCommandEvent& event);
        virtual void loadMainComms( wxCommandEvent& event );

        //Open File Event
        virtual void OpenFile( wxCommandEvent& event );
        //Handle clicking on a system
        virtual void sys_click( wxCommandEvent& event );

        void clear_params();
        virtual void Name_Changed( wxCommandEvent& event );
     //   virtual void param_change( wxCommandEvent& event );
        virtual void SaveAssetChanges( wxCommandEvent& event );
        void GetChanges_Float(wxTextCtrl*& text_box, float &float_val);
        void GetChanges_String(wxTextCtrl*& text_box, wxString &float_val);
        virtual void ChangeMade( wxCommandEvent& event);

        int param_flags; //Parameter flags, for judging whether stuff has been changed, decimal format, compact

        //Here is the format:

        /*
        1 = changed, 0 = unchanged

        This is backwards:
        | Name | X | Y | Space | Ext | Faction | AnyFaction | Value | Range | Class | Population -- (continued below)
        | Land | Refuel | Bar | Missions | Commodity | Outfits | Shipyard | Landing Descrip | Bar Descrip | Commodity list|

       This is correct: Name = 1, X = 2, Y = 4, Space = 8, Ext = 16, Faction = 32

        */
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
