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


class Asset{
public:
    //Constructors
    Asset(){};
    //Make Asset from XmlO params
    Asset(int p_ID, mxml_node_t *sysnode_t, const char* p_name, float p_x, float p_y){
        //Set ID
        ID = p_ID;
        sys_node = sysnode_t;
        name = wxString::FromAscii(p_name);
        x_pos  = p_x;
        y_pos = p_y;

    }
    //Destructor
    ~Asset(){}

    int ID; //ID for Asset that corresponds to vector positions in XmlO
    //Asset Parameters
    wxString name;
    float radius;

    //GFX Files
    wxString gfx_space;
    wxString gfx_ext;
    wxString interference;
    float x_pos;
    float y_pos;
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
        Asset_elem = mxmlWalkNext(tree, tree, MXML_DESCEND_FIRST);

        //Start loading <asset> elements

        //Temporary Elements
        mxml_node_t *node; //Node to save
        mxml_node_t *subnode_pos; //Subnode for pos nodes
        mxml_node_t *subnode; //Subnode
        const char* name_tmp; //String for names of asset
        const char* tmp_str; //String for anything :P
        float x_pos; //X_pos Float
        float y_pos; //Y_pos Float

        //Load first asset
        node = mxmlFindElement(Asset_elem, tree, "asset", NULL, NULL, MXML_DESCEND);
        //Start loading the rest of the ssys elements (but fail if first element is NULL)
        int i = 1;
        while (node != NULL){
            //Load name attrib
            name_tmp = mxmlElementGetAttr(node, "name");

            //Mark Branching nodes
            //TODO

            //Descend to pos element
            subnode_pos = mxmlFindElement(node, tree, "pos", NULL, NULL, MXML_DESCEND);

            //Get Pos parameters x and y
            subnode = mxmlFindElement(subnode_pos, tree, "x", NULL, NULL, MXML_DESCEND);
            if(subnode != NULL){
                tmp_str = (subnode->child->value.text.string);
                x_pos = atof(tmp_str);
            }
            subnode = mxmlFindElement(subnode_pos, tree, "y", NULL, NULL, MXML_DESCEND);
            if(subnode != NULL){
                tmp_str = (subnode->child->value.text.string);
                y_pos = atof(tmp_str);
            }

            //Generate tmp Asset
            Asset asset_sys(i, node, name_tmp, x_pos, y_pos);
            //Load system with its node into vector of Assets
            Sys.push_back(asset_sys);

            //Load next Asset
            node = mxmlFindElement(node, tree, "asset", NULL, NULL, MXML_DESCEND);
            //Increment ID counter
            i++;
        }

    }


    std::vector<Asset> Sys; //Vector of Systems --MUAHAHAHAHA!, we are vectorized. All Systems under my command! -- Sorry
    FILE *fp; //pointer to file of interest
    mxml_node_t *tree; //Pointer to main node
    mxml_node_t *Asset_elem; //Pointer to Systems Element
    std::vector<mxml_node_t*> ssys_elem; //Vector of pointers (!) to syss elements
    std::vector<const char*> ssys_name; //Vector of pointers to name elements for ssys
};

#endif // SYSTEM_H_INCLUDED
