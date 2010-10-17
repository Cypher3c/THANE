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
    Asset(int p_ID, mxml_node_t *sysnode_t, const char* p_name, float p_x, float p_y, const char* gfx_space_tmp, const char* gfx_ext_tmp){
        //Set ID
        ID = p_ID;
        sys_node = sysnode_t;
        name = wxString::FromAscii(p_name);
        x_pos  = p_x;
        y_pos = p_y;
        gfx_space = wxString::FromAscii(gfx_space_tmp);
        gfx_ext = wxString::FromAscii(gfx_ext_tmp);


    }
    //Destructor
    ~Asset(){}

    int ID; //ID for Asset that corresponds to vector positions in XmlO
    mxml_node_t *sys_node;
    //Asset Parameters
    wxString name;
    float radius;

    //GFX Files
    wxString gfx_space;
    wxString gfx_ext;
    float x_pos;
    float y_pos;



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
        mxml_node_t *subnode_GFX; //Subnode for GFX nodes
        mxml_node_t *subnode_pres; //Subnode for presence nodes
        mxml_node_t *subnode_gen; //Subnode for general nodes
        mxml_node_t *subnode; //Subnode
        const char* name_tmp; //String for names of asset
        const char* tmp_str; //String for anything :P
        float x_pos; //X_pos Float
        float y_pos; //Y_pos Float
        const char* gfx_space;
        const char* gfx_ext;

        //Load first asset
        node = mxmlFindElement(Asset_elem, tree, "asset", NULL, NULL, MXML_DESCEND);
        //Start loading the rest of the ssys elements (but fail if first element is NULL)
        int i = 1;
        while (node != NULL){
            //Load name attrib
            name_tmp = mxmlElementGetAttr(node, "name");

            //Mark Branching nodes
            //Pos Element
            subnode_pos = mxmlFindElement(node, tree, "pos", NULL, NULL, MXML_DESCEND);
            //GFX Element
            subnode_GFX = mxmlFindElement(node, tree, "GFX", NULL, NULL, MXML_DESCEND);
            //Presence Element
            subnode_pres = mxmlFindElement(node, tree, "presence", NULL, NULL, MXML_DESCEND);
            //General Element
            subnode_gen = mxmlFindElement(node, tree, "general", NULL, NULL, MXML_DESCEND);


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

            //Get GFX Parameters space and exterior
            subnode = mxmlFindElement(subnode_GFX, tree, "space", NULL, NULL, MXML_DESCEND);
            if(subnode != NULL){
                gfx_space = (subnode->child->value.text.string);
            }
            subnode = mxmlFindElement(subnode_GFX, tree, "exterior", NULL, NULL, MXML_DESCEND);
            if(subnode != NULL){
                gfx_ext = (subnode->child->value.text.string);
            }

            //Get elements from general node (class, population, servicesTODO, description, bar)
            //Generate tmp Asset
            Asset asset_sys(i, node, name_tmp, x_pos, y_pos, gfx_space, gfx_ext);
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
