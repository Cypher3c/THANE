///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuQuit 1000
#define idMenuAbout 1001

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar2;
		wxMenu* m_file;
		wxMenu* m_Settings;
		wxButton* m_buttonAsset;
		wxButton* m_buttonCom;
		wxButton* m_buttonShip;
		wxButton* m_buttonTech;
		wxButton* m_buttonOutfit;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void SetNaevDir_ev( wxCommandEvent& event ) { event.Skip(); }
		virtual void launch_asset_ed( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("THANE v0.0.2a"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 242,200 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUIFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AssetEd
///////////////////////////////////////////////////////////////////////////////
class AssetEd : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxStaticText* m_staticText_TitleAssets;
		wxListBox* m_AssetListBox;
		wxButton* m_buttonAddAsset;
		wxButton* m_buttonDeleteAsset;
		wxStaticText* m_staticParamslabel;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textPNAME;
		wxStaticText* m_staticText6111;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textPosX;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_textPosY;
		wxStaticText* m_staticText611;
		wxStaticText* m_staticText61;
		wxTextCtrl* m_text_GFXSpace;
		wxStaticText* m_staticText612;
		wxTextCtrl* m_text_GFXExt;
		wxStaticText* m_staticTextPresence;
		wxStaticText* m_staticTextFaction;
		wxTextCtrl* m_text_Faction;
		wxCheckBox* m_checkFac;
		wxStaticText* m_staticTextValue;
		wxTextCtrl* m_text_PresVal;
		wxStaticText* m_staticTextRange;
		wxTextCtrl* m_text_PresRange;
		wxStaticText* m_staticTextGeneral;
		wxStaticText* m_staticTextFaction1;
		wxTextCtrl* m_text_Class;
		wxStaticText* m_staticTextPopulation;
		wxTextCtrl* m_text_Population;
		wxStaticText* m_staticTextServices;
		wxCheckBox* m_checkBoxLand;
		wxCheckBox* m_checkBoxRefuel;
		wxCheckBox* m_checkBoxBar;
		wxCheckBox* m_checkBoxMissions;
		wxCheckBox* m_checkBoxCommodity;
		wxCheckBox* m_checkBoxOutfits;
		wxCheckBox* m_checkBoxShipyard;
		wxStaticText* m_staticTextLandDescription;
		wxTextCtrl* m_textLandingDescription;
		wxStaticText* m_staticTextLandDescription1;
		wxTextCtrl* m_textBarDescription;
		wxStaticText* m_staticCommoditiesLabel;
		wxListBox* m_ComListBox;
		wxButton* m_buttonAddCom;
		wxButton* m_buttonDeleteCom;
		wxToolBar* m_toolBar1;
		wxStatusBar* statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OpenFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void sys_click( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AssetEd( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,743 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~AssetEd();
	
};

#endif //__GUIFrame__
