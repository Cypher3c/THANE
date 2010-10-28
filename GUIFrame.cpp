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
	fgSizer4 = new wxFlexGridSizer( 4, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_buttonAsset = new wxButton( this, wxID_ANY, wxT("Asset Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAsset->SetToolTip( wxT("Asset Editor") );
	
	fgSizer4->Add( m_buttonAsset, 0, wxALL, 5 );
	
	m_buttonCom = new wxButton( this, wxID_ANY, wxT("Comm. Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonCom->Enable( false );
	m_buttonCom->SetToolTip( wxT("Commodity Editor") );
	
	fgSizer4->Add( m_buttonCom, 0, wxALL, 5 );
	
	m_buttonShip = new wxButton( this, wxID_ANY, wxT("Ship Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonShip->Enable( false );
	
	fgSizer4->Add( m_buttonShip, 0, wxALL, 5 );
	
	m_buttonTech = new wxButton( this, wxID_ANY, wxT("Tech Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonTech->Enable( false );
	
	fgSizer4->Add( m_buttonTech, 0, wxALL, 5 );
	
	m_buttonOutfit = new wxButton( this, wxID_ANY, wxT("Outfit Editor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonOutfit->Enable( false );
	
	fgSizer4->Add( m_buttonOutfit, 0, wxALL, 5 );
	
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
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer3->Add( m_staticText5, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPosX = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textPosX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 1 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer3->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textPosY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textPosY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer41->Add( fgSizer3, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* GFXBox;
	GFXBox = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer311;
	gSizer311 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticText611 = new wxStaticText( this, wxID_ANY, wxT("GFX"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	m_staticText611->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer311->Add( m_staticText611, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	GFXBox->Add( gSizer311, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, wxT("Space:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer4->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_GFXSpace = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_text_GFXSpace, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText612 = new wxStaticText( this, wxID_ANY, wxT("Ext:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText612->Wrap( -1 );
	fgSizer4->Add( m_staticText612, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_GFXExt = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_text_GFXExt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	GFXBox->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	bSizer41->Add( GFXBox, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* FactionBox;
	FactionBox = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer3112;
	gSizer3112 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticTextPresence = new wxStaticText( this, wxID_ANY, wxT("Presence"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPresence->Wrap( -1 );
	m_staticTextPresence->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer3112->Add( m_staticTextPresence, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	FactionBox->Add( gSizer3112, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer313;
	gSizer313 = new wxGridSizer( 1, 3, 0, 0 );
	
	m_staticTextFaction = new wxStaticText( this, wxID_ANY, wxT("Faction:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFaction->Wrap( -1 );
	gSizer313->Add( m_staticTextFaction, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_Faction = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer313->Add( m_text_Faction, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkFac = new wxCheckBox( this, wxID_ANY, wxT("Any?"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer313->Add( m_checkFac, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	FactionBox->Add( gSizer313, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextValue = new wxStaticText( this, wxID_ANY, wxT("Value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextValue->Wrap( -1 );
	fgSizer11->Add( m_staticTextValue, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_PresVal = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_text_PresVal, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextRange = new wxStaticText( this, wxID_ANY, wxT("Range:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRange->Wrap( -1 );
	fgSizer11->Add( m_staticTextRange, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_PresRange = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_text_PresRange, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	FactionBox->Add( fgSizer11, 0, 0, 5 );
	
	wxBoxSizer* GeneralBox;
	GeneralBox = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer31121;
	gSizer31121 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticTextGeneral = new wxStaticText( this, wxID_ANY, wxT("General"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGeneral->Wrap( -1 );
	m_staticTextGeneral->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer31121->Add( m_staticTextGeneral, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	GeneralBox->Add( gSizer31121, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextFaction1 = new wxStaticText( this, wxID_ANY, wxT("Class:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFaction1->Wrap( -1 );
	fgSizer12->Add( m_staticTextFaction1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_Class = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( m_text_Class, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextPopulation = new wxStaticText( this, wxID_ANY, wxT("Population:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPopulation->Wrap( -1 );
	fgSizer12->Add( m_staticTextPopulation, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_text_Population = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( m_text_Population, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	GeneralBox->Add( fgSizer12, 0, 0, 5 );
	
	wxGridSizer* gSizer3131;
	gSizer3131 = new wxGridSizer( 1, 2, 0, 0 );
	
	GeneralBox->Add( gSizer3131, 0, 0, 5 );
	
	wxGridSizer* gSizer31212;
	gSizer31212 = new wxGridSizer( 1, 2, 0, 0 );
	
	GeneralBox->Add( gSizer31212, 0, 0, 5 );
	
	FactionBox->Add( GeneralBox, 0, 0, 5 );
	
	wxBoxSizer* FactionBox11;
	FactionBox11 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer311211;
	gSizer311211 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_staticTextServices = new wxStaticText( this, wxID_ANY, wxT("Services"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextServices->Wrap( -1 );
	m_staticTextServices->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer311211->Add( m_staticTextServices, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	FactionBox11->Add( gSizer311211, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_checkBoxLand = new wxCheckBox( this, wxID_ANY, wxT("Land"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_checkBoxLand, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBoxRefuel = new wxCheckBox( this, wxID_ANY, wxT("Refuel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_checkBoxRefuel, 0, wxALL, 5 );
	
	m_checkBoxBar = new wxCheckBox( this, wxID_ANY, wxT("Bar"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_checkBoxBar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBoxMissions = new wxCheckBox( this, wxID_ANY, wxT("Missions"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_checkBoxMissions, 0, wxALL, 5 );
	
	FactionBox11->Add( fgSizer5, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_checkBoxCommodity = new wxCheckBox( this, wxID_ANY, wxT("Commodity"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer51->Add( m_checkBoxCommodity, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBoxOutfits = new wxCheckBox( this, wxID_ANY, wxT("Outfits"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer51->Add( m_checkBoxOutfits, 0, wxALL, 5 );
	
	m_checkBoxShipyard = new wxCheckBox( this, wxID_ANY, wxT("Shipyard"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer51->Add( m_checkBoxShipyard, 0, wxALL, 5 );
	
	FactionBox11->Add( fgSizer51, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	FactionBox->Add( FactionBox11, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer91;
	fgSizer91 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer91->SetFlexibleDirection( wxBOTH );
	fgSizer91->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextLandDescription = new wxStaticText( this, wxID_ANY, wxT("Landing Description"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLandDescription->Wrap( -1 );
	m_staticTextLandDescription->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer91->Add( m_staticTextLandDescription, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textLandingDescription = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,53 ), wxTE_MULTILINE|wxTE_WORDWRAP );
	fgSizer91->Add( m_textLandingDescription, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer15->Add( fgSizer91, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer911;
	fgSizer911 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer911->SetFlexibleDirection( wxBOTH );
	fgSizer911->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextLandDescription1 = new wxStaticText( this, wxID_ANY, wxT("Bar Description"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLandDescription1->Wrap( -1 );
	m_staticTextLandDescription1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer911->Add( m_staticTextLandDescription1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textBarDescription = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,53 ), wxTE_MULTILINE|wxTE_PROCESS_TAB|wxTE_WORDWRAP );
	fgSizer911->Add( m_textBarDescription, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer15->Add( fgSizer911, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	FactionBox->Add( bSizer15, 1, wxEXPAND, 5 );
	
	bSizer41->Add( FactionBox, 1, wxEXPAND, 5 );
	
	bSizer3->Add( bSizer41, 1, wxEXPAND, 5 );
	
	fgSizer1->Add( bSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticCommoditiesLabel = new wxStaticText( this, wxID_ANY, wxT("Commodities"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCommoditiesLabel->Wrap( -1 );
	m_staticCommoditiesLabel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer4->Add( m_staticCommoditiesLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_ComListBox = new wxListBox( this, wxID_ANY, wxPoint( -1,-1 ), wxDefaultSize, 0, NULL, wxLB_ALWAYS_SB|wxLB_HSCROLL|wxLB_SINGLE ); 
	m_ComListBox->SetMinSize( wxSize( 200,200 ) );
	
	bSizer21->Add( m_ComListBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer181;
	gSizer181 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_buttonAddCom = new wxButton( this, wxID_ANY, wxT("Add Commodity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAddCom->Enable( false );
	
	gSizer181->Add( m_buttonAddCom, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonDeleteCom = new wxButton( this, wxID_ANY, wxT("Delete Commodity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonDeleteCom->Enable( false );
	
	gSizer181->Add( m_buttonDeleteCom, 0, wxALL, 5 );
	
	bSizer21->Add( gSizer181, 1, wxEXPAND, 5 );
	
	bSizer4->Add( bSizer21, 1, wxEXPAND, 5 );
	
	fgSizer1->Add( bSizer4, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 30 );
	
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
	m_ComListBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( AssetEd::sys_click ), NULL, this );
}

AssetEd::~AssetEd()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OpenFile ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OnQuit ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( AssetEd::OnAbout ) );
	m_AssetListBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( AssetEd::sys_click ), NULL, this );
	m_ComListBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( AssetEd::sys_click ), NULL, this );
	
}

CommEditor::CommEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	
	this->Centre( wxBOTH );
}

CommEditor::~CommEditor()
{
}

MyFrame4::MyFrame4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	
	this->Centre( wxBOTH );
}

MyFrame4::~MyFrame4()
{
}
