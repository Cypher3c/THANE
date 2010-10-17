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
	
	m_menubar2 = new wxMenuBar( 0 );
	m_file = new wxMenu();
	wxMenuItem* m_menuquit;
	m_menuquit = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("&Quit") ) + wxT('\t') + wxT("alt-f4"), wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_menuquit );
	
	m_menubar2->Append( m_file, wxT("&File") ); 
	
	m_Settings = new wxMenu();
	wxMenuItem* m_SetNaevDir;
	m_SetNaevDir = new wxMenuItem( m_Settings, wxID_ANY, wxString( wxT("Set Naev Directory") ) , wxEmptyString, wxITEM_NORMAL );
	m_Settings->Append( m_SetNaevDir );
	
	m_menubar2->Append( m_Settings, wxT("&Settings") ); 
	
	this->SetMenuBar( m_menubar2 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 4, 4, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer4->Add( 20, 0, 1, wxEXPAND, 5 );
	
	m_buttonAsset = new wxButton( this, wxID_ANY, wxT("Asset Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_buttonAsset, 0, wxALL, 5 );
	
	m_buttonShip = new wxButton( this, wxID_ANY, wxT("Ship Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonShip->Enable( false );
	
	fgSizer4->Add( m_buttonShip, 0, wxALL, 5 );
	
	
	fgSizer4->Add( 20, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer4->Add( 20, 0, 1, wxEXPAND, 5 );
	
	m_buttonTech = new wxButton( this, wxID_ANY, wxT("Tech Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonTech->Enable( false );
	
	fgSizer4->Add( m_buttonTech, 0, wxALL, 5 );
	
	m_buttonOutfit = new wxButton( this, wxID_ANY, wxT("Outfit Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonOutfit->Enable( false );
	
	fgSizer4->Add( m_buttonOutfit, 0, wxALL, 5 );
	
	
	fgSizer4->Add( 20, 0, 1, wxEXPAND, 5 );
	
	this->SetSizer( fgSizer4 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( m_SetNaevDir->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::SetNaevDir_ev ) );
	m_buttonAsset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::launch_asset_ed ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::SetNaevDir_ev ) );
	m_buttonAsset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::launch_asset_ed ), NULL, this );
	
}

AssetEd::AssetEd( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
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
	
	m_staticText_TitleAssets = new wxStaticText( this, wxID_ANY, wxT("Assets"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_TitleAssets->Wrap( -1 );
	m_staticText_TitleAssets->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer2->Add( m_staticText_TitleAssets, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_AssetListBox = new wxListBox( this, wxID_ANY, wxPoint( -1,-1 ), wxDefaultSize, 0, NULL, wxLB_ALWAYS_SB|wxLB_HSCROLL|wxLB_SINGLE ); 
	m_AssetListBox->SetMinSize( wxSize( 200,300 ) );
	
	bSizer2->Add( m_AssetListBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer18;
	gSizer18 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_buttonAddAsset = new wxButton( this, wxID_ANY, wxT("Add Asset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAddAsset->Enable( false );
	
	gSizer18->Add( m_buttonAddAsset, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonDeleteAsset = new wxButton( this, wxID_ANY, wxT("Delete Asset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonDeleteAsset->Enable( false );
	
	gSizer18->Add( m_buttonDeleteAsset, 0, wxALL, 5 );
	
	bSizer2->Add( gSizer18, 1, wxEXPAND, 5 );
	
	fgSizer1->Add( bSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 30 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_staticParamslabel = new wxStaticText( this, wxID_ANY, wxT("Asset Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	wxGridSizer* gSizer3111;
	gSizer3111 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticText6111 = new wxStaticText( this, wxID_ANY, wxT("Position"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6111->Wrap( -1 );
	m_staticText6111->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer3111->Add( m_staticText6111, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer41->Add( gSizer3111, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer2->Add( m_staticText5, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPosX = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_textPosX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( gSizer2, 0, 0, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer3->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textPosY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_textPosY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( gSizer3, 0, 0, 5 );
	
	wxBoxSizer* GFXBox;
	GFXBox = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer311;
	gSizer311 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticText611 = new wxStaticText( this, wxID_ANY, wxT("GFX"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	m_staticText611->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer311->Add( m_staticText611, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	GFXBox->Add( gSizer311, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer31;
	gSizer31 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, wxT("Space:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	gSizer31->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_GFXSpace = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_text_GFXSpace->Enable( false );
	
	gSizer31->Add( m_text_GFXSpace, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	GFXBox->Add( gSizer31, 0, 0, 5 );
	
	wxGridSizer* gSizer312;
	gSizer312 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_staticText612 = new wxStaticText( this, wxID_ANY, wxT("Exterior:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText612->Wrap( -1 );
	gSizer312->Add( m_staticText612, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_GFXExt = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_text_GFXExt->Enable( false );
	
	gSizer312->Add( m_text_GFXExt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	GFXBox->Add( gSizer312, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer41->Add( GFXBox, 0, 0, 5 );
	
	wxBoxSizer* FactionBox;
	FactionBox = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer3112;
	gSizer3112 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticText6112 = new wxStaticText( this, wxID_ANY, wxT("GFX"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6112->Wrap( -1 );
	m_staticText6112->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer3112->Add( m_staticText6112, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	FactionBox->Add( gSizer3112, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer313;
	gSizer313 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_staticText613 = new wxStaticText( this, wxID_ANY, wxT("Space:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText613->Wrap( -1 );
	gSizer313->Add( m_staticText613, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_GFXSpace1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_text_GFXSpace1->Enable( false );
	
	gSizer313->Add( m_text_GFXSpace1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	FactionBox->Add( gSizer313, 0, 0, 5 );
	
	wxGridSizer* gSizer3121;
	gSizer3121 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_staticText6121 = new wxStaticText( this, wxID_ANY, wxT("Exterior:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6121->Wrap( -1 );
	gSizer3121->Add( m_staticText6121, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_GFXExt1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_text_GFXExt1->Enable( false );
	
	gSizer3121->Add( m_text_GFXExt1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	FactionBox->Add( gSizer3121, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer41->Add( FactionBox, 1, wxEXPAND, 5 );
	
	bSizer3->Add( bSizer41, 1, wxEXPAND, 5 );
	
	fgSizer1->Add( bSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 30 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticPrevLabel = new wxStaticText( this, wxID_ANY, wxT("Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPrevLabel->Wrap( -1 );
	m_staticPrevLabel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer4->Add( m_staticPrevLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bitmap_AssetPreview = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 300,300 ), 0 );
	bSizer4->Add( m_bitmap_AssetPreview, 0, wxALL, 5 );
	
	wxGridSizer* gSizer19;
	gSizer19 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Space"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_button7->Enable( false );
	
	gSizer19->Add( m_button7, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button8 = new wxButton( this, wxID_ANY, wxT("Ext"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_button8->Enable( false );
	
	gSizer19->Add( m_button8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer4->Add( gSizer19, 1, wxEXPAND, 5 );
	
	fgSizer1->Add( bSizer4, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 30 );
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar1->Realize();
	
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( menuFileOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OpenFile ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OnQuit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OnAbout ) );
	m_AssetListBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( AssetEd::sys_click ), NULL, this );
}

AssetEd::~AssetEd()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OpenFile ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OnQuit ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OnAbout ) );
	m_AssetListBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( AssetEd::sys_click ), NULL, this );
	
}
