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
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

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
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxStaticText* m_staticTextSysboxlabel;
		wxListBox* m_SysListBox;
		wxStaticText* m_staticParamslabel;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textPNAME;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textRadius;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_textStars;
		wxStaticText* m_staticText61;
		wxTextCtrl* m_textInterference;
		wxStaticText* m_staticText611;
		wxStaticText* m_staticText612;
		wxTextCtrl* m_textPosX;
		wxStaticText* m_staticText6121;
		wxTextCtrl* m_textPosY;
		wxStaticText* m_staticLinksLabel;
		wxListBox* m_SysHyperlinkslist;
		wxToolBar* m_toolBar1;
		wxStatusBar* statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OpenFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void sys_click( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("NUE v0.0.1a"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 915,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUIFrame();
	
};

#endif //__GUIFrame__
