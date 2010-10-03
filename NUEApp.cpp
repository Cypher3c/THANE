/***************************************************************
 * Name:      NUEApp.cpp
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

#include "NUEApp.h"
#include "NUEMain.h"

IMPLEMENT_APP(NUEApp);

bool NUEApp::OnInit()
{
    NUEFrame* frame = new NUEFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
