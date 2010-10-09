/** System.cpp

Obtain systems, planets, oh my!

*/

#include "System.h"
#include <string>
#include <wx/wx.h>
#include "GUIFrame.h"

std::vector<SSystem> Load_Systems(wxString chosen_file){

    //Get passed file location, turn into standard string
    std::string ssys_file = std::string(chosen_file.mb_str());

    //Create new Xml object
   // XmlO SysX(ssys_file);
    //Set m_SysListBox contents to names from ssys.xml
  //  return SysX.Sys;


}
