/***************************************************************
 * Name:      THANEApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Cypher ()
 * Created:   2010-10-02
 * Copyright: Cypher ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "THANEApp.h"
#include "THANEMain.h"

IMPLEMENT_APP(THANEApp);

bool THANEApp::OnInit()
{
    THANEFrame* frame = new THANEFrame(0L);
  //  frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();



    return true;
}
