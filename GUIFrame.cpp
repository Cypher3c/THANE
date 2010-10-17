///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileNew;
	menuFileNew = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("&New") ) , wxT("Create a new Naev System File"), wxITEM_NORMAL );
	fileMenu->Append( menuFileNew );
	
	wxMenuItem* menuFileOpen;
	menuFileOpen = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("&Open") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( menuFileOpen );
	
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );
	
	mbar->Append( fileMenu, wxT("&File") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, wxT("&Help") ); 
	
	this->SetMenuBar( mbar );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextSysboxlabel = new wxStaticText( this, wxID_ANY, wxT("Systems"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSysboxlabel->Wrap( -1 );
	m_staticTextSysboxlabel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer2->Add( m_staticTextSysboxlabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_SysListBox = new wxListBox( this, wxID_ANY, wxPoint( -1,-1 ), wxDefaultSize, 0, NULL, wxLB_ALWAYS_SB|wxLB_HSCROLL|wxLB_SINGLE ); 
	m_SysListBox->SetMinSize( wxSize( -1,300 ) );
	
	bSizer2->Add( m_SysListBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer1->Add( bSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 30 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_staticParamslabel = new wxStaticText( this, wxID_ANY, wxT("System Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticParamslabel->Wrap( -1 );
	m_staticParamslabel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer3->Add( m_staticParamslabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer1->Add( m_staticText4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPNAME = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_textPNAME, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( gSizer1, 0, 0, 5 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Radius:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer2->Add( m_staticText5, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textRadius = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_textRadius, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( gSizer2, 0, 0, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Stars:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer3->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textStars = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_textStars, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( gSizer3, 0, 0, 5 );
	
	wxGridSizer* gSizer31;
	gSizer31 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, wxT("Interference:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	gSizer31->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textInterference = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer31->Add( m_textInterference, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( gSizer31, 0, 0, 5 );
	
	wxGridSizer* gSizer311;
	gSizer311 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticText611 = new wxStaticText( this, wxID_ANY, wxT("Position"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	m_staticText611->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer311->Add( m_staticText611, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( gSizer311, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer312;
	gSizer312 = new wxGridSizer( 1, 2, 0, 0 );
	
	wxGridSizer* gSizer14;
	gSizer14 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText612 = new wxStaticText( this, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText612->Wrap( -1 );
	gSizer14->Add( m_staticText612, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textPosX = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer14->Add( m_textPosX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	gSizer312->Add( gSizer14, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxGridSizer* gSizer141;
	gSizer141 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText6121 = new wxStaticText( this, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6121->Wrap( -1 );
	gSizer141->Add( m_staticText6121, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textPosY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer141->Add( m_textPosY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	gSizer312->Add( gSizer141, 0, 0, 5 );
	
	bSizer41->Add( gSizer312, 0, 0, 5 );
	
	bSizer3->Add( bSizer41, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	bSizer3->Add( bSizer6, 1, wxEXPAND, 5 );
	
	fgSizer1->Add( bSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 30 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticLinksLabel = new wxStaticText( this, wxID_ANY, wxT("Hyperjump Links"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLinksLabel->Wrap( -1 );
	m_staticLinksLabel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer4->Add( m_staticLinksLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_SysHyperlinkslist = new wxListBox( this, wxID_ANY, wxPoint( -1,-1 ), wxDefaultSize, 0, NULL, 0 ); 
	m_SysHyperlinkslist->SetMinSize( wxSize( -1,300 ) );
	
	bSizer4->Add( m_SysHyperlinkslist, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer1->Add( bSizer4, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 30 );
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar1->Realize();
	
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( menuFileOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OpenFile ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_SysListBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUIFrame::sys_click ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OpenFile ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_SysListBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUIFrame::sys_click ), NULL, this );
	
}
