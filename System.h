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
    SSystem(int p_ID, mxml_node_t *sysnode_t, const char* p_name, float p_rad){
        //Set ID
        ID = p_ID;
        sys_node = sysnode_t;
        name = wxString::FromAscii(p_name);
        radius  = p_rad;
        //stars =

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
    float radius;
    wxString stars;
    wxString asteriods;
    wxString interference;
    wxString pos_x;
    wxString pos_y;
    mxml_node_t *sys_node;



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

        //Temporary Elements
        mxml_node_t *node; //Node to save
        mxml_node_t *subnode_gen; //Subnode for general nodes
        mxml_node_t *subnode; //Subnode
        const char* name_tmp; //String for names of ssys
        const char* tmp_str; //String for anything :P
        float rad; //Radius Float

        //Load first ssys
        node = mxmlFindElement(Systems_elem, tree, "ssys", NULL, NULL, MXML_DESCEND);
        //Start loading the rest of the ssys elements (but fail if first element is NULL)
        int i = 1;
        SSystem tmp_sys; //Temporary system object to add to Sys vector
        while (node != NULL){
            //Load name attrib
            name_tmp = mxmlElementGetAttr(node, "name");

            //Descend to General element
            subnode_gen = mxmlFindElement(node, tree, "general", NULL, NULL, MXML_DESCEND);
            subnode = mxmlFindElement(subnode_gen, tree, "radius", NULL, NULL, MXML_DESCEND);
            if(subnode != NULL){
                tmp_str = (subnode->child->value.text.string);
                rad = atof(tmp_str);
            }
            //Generate tmp system
            SSystem tmp_sys(i, node, name_tmp, rad);
            //Load system with its node into vector of SSystems
            Sys.push_back(tmp_sys);
            //load next ssys
            node = mxmlFindElement(node, tree, "ssys", NULL, NULL, MXML_DESCEND);
            //Increment ID counter
            i++;
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
