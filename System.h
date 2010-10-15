#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <string>
#include <vector>
#include <wx/wx.h>
//#include "nxml.h"
//#include "space.h"
#include <mxml.h>
#include <wx/msgdlg.h>


class APlanet{
public:
    APlanet();


private:



};


class SSystem{
public:
    //Constructors
    SSystem(){};
    //Make SSystem from XmlO params
    SSystem(int p_ID, const char* p_name){
        //Set ID
        ID = p_ID;
        name = wxString::FromAscii(p_name);
    }
    //Destructor
    ~SSystem(){
        //Clear Planets vect[or
        Planets.clear();
    }

    int ID; //ID for SSystem that corresponds to vector positions in XmlO
    std::vector<APlanet> Planets;
    //System Parameters
    wxString name;
    wxString radius;
    wxString stars;
    wxString asteriods;
    wxString interference;
    wxString pos_x;
    wxString pos_y;



};

class XmlO{
public:
    //Constructors
    XmlO(){};

    //Destructor
    ~XmlO(){
    }
    /**Methods */
    //(Re)Set file
    void Set(std::string fname){
        //TODO
    }

    //Load XML file into XmlO
    void load(wxString filenam){
        //First, convert wxString to std::string for safety (char* is transient), then to const char*
        std::string tmp_filenam = std::string(filenam.mb_str());
        const char* tmp_filenam2 = tmp_filenam.c_str();
        //Get pointer to file
        fp = fopen(tmp_filenam2,"r");
        //Load tree
        tree = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);

        //Close file (be nice!)
        fclose(fp);

        //Load <Systems> node
        Systems_elem = mxmlWalkNext(tree, tree, MXML_DESCEND_FIRST);

        //Start loading <ssys> elements
        mxml_node_t *node; //temporary node to save
        const char* name_tmp; //Temporary string for names of ssys
        //Load first ssys
        node = mxmlFindElement(Systems_elem, tree, "ssys", NULL, NULL, MXML_DESCEND);
        //Start loading the rest of the ssys elements (but fail if first element is NULL)
        while (node != NULL){
            //Load node into vector of pointers
            ssys_elem.push_back(node);
            //Get name attribute
            name_tmp = mxmlElementGetAttr(node, "name");
            ssys_name.push_back(name_tmp);
            //load next ssys
            node = mxmlFindElement(node, tree, "ssys", NULL, NULL, MXML_DESCEND);
        }

    }

    void Generate_objs(){


        int ssys_num = ssys_elem.size();

        const char* tmp_name;
        for (int i = 0; i<ssys_num; i++){
            tmp_name = ssys_name[i];
            SSystem tmp_sys(i, tmp_name);
            Sys.push_back(tmp_sys);
        }


    }



    std::vector<SSystem> Sys; //Vector of Systems --MUAHAHAHAHA!, we are vectorized. All Systems under my command! -- Sorry
    FILE *fp; //pointer to file of interest
    mxml_node_t *tree; //Pointer to main node
    mxml_node_t *Systems_elem; //Pointer to Systems Element
    std::vector<mxml_node_t*> ssys_elem; //Vector of pointers (!) to syss elements
    std::vector<const char*> ssys_name; //Vector of pointers to name elements for ssys
};

#endif // SYSTEM_H_INCLUDED
