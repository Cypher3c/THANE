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

    //ID, node, Asset Name, X position,
    //Y position, Space graphic, exterior graphic,
    //faction name, value, range,
    //planet/station class, population, land,
    //refuel, bar, missions, commodity
    //outfits, shipyard, description, bar description
    Asset(int p_ID, mxml_node_t *sysnode_t, const char* p_name, float p_x, float p_y, const char* gfx_space_tmp, const char* gfx_ext_tmp,
          const char* p_fac, float p_presval, int p_presrange, const char* p_plan_class, int p_pop, bool p_land, bool p_refuel, bool p_bar, bool p_missions, bool p_commodity,
          bool p_outfits, bool p_shipyard, const char* p_descrip, const char* p_bar_descrip){
        //Set ID
        ID = p_ID;
        sys_node = sysnode_t;
        name = wxString::FromAscii(p_name);
        x_pos  = p_x;
        y_pos = p_y;
        gfx_space = wxString::FromAscii(gfx_space_tmp);
        gfx_ext = wxString::FromAscii(gfx_ext_tmp);
        //See if faction is present
        if(p_fac != NULL){
            pres_faction = wxString::FromAscii(p_fac);
        }
        else{
            pres_faction = wxT("n");
        }
        pres_value = p_presval;
        pres_range = p_presrange;
        planet_class = wxString::FromAscii(p_plan_class);
        population = p_pop;
        land = p_land;
        refuel = p_refuel;
        bar = p_bar;
        missions = p_missions;
        commodity = p_commodity;
        outfits = p_outfits;
        shipyard = p_shipyard;
        description = wxString::FromAscii(p_descrip);
        bar_description = wxString::FromAscii(p_bar_descrip);

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
    wxString pres_faction;
    float pres_value;
    int pres_range;
    wxString planet_class;
    int population;
    bool land;
    bool refuel;
    bool bar;
    bool missions;
    bool commodity;
    bool outfits;
    bool shipyard;
    wxString description;
    wxString bar_description;



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

    //XML Reading Functions

    const char* GetString(mxml_node_t *nd, const char* tag){
        const char * tmp_str;
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if(temp_sub_node != NULL){
            return temp_sub_node->child->value.text.string;
        }
        else{
            return NULL;
        }
        delete tmp_str;
        delete temp_sub_node;
    }

    int GetInt(mxml_node_t *nd, const char* tag){
        const char * tmp_str;
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if(temp_sub_node != NULL){
            tmp_str = (temp_sub_node->child->value.text.string);
            return atoi(tmp_str);
        }
        else{
            return NULL;
        }
        delete tmp_str;
        delete temp_sub_node;

    }
    float GetFloat(mxml_node_t *nd, const char* tag){
        const char * tmp_str;
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if(temp_sub_node != NULL){
            tmp_str = (temp_sub_node->child->value.text.string);
            return atof(tmp_str);
        }
        else{
            return NULL;
        }
        delete tmp_str;
        delete temp_sub_node;

    }

        bool TagIsPresent(mxml_node_t *nd, const char* tag){
        const char * tmp_str;
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if(temp_sub_node != NULL){
            return true;
        }
        else{
            return false;
        }
        delete tmp_str;
        delete temp_sub_node;
    }


    //XML Writing Functions
    //TODO

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
        mxml_node_t *subnode_serv; //Subnode for services nodes
        mxml_node_t *subnode; //Subnode
        const char* name_tmp; //String for names of asset
        const char* tmp_str; //String for anything :P
        float x_pos; //X_pos Float
        float y_pos; //Y_pos Float
        const char* gfx_space;
        const char* gfx_ext;
        const char* pres_fac;
        float pres_val;
        int pres_range;
        const char* plan_class;
        int population;
        bool land;
        bool refuel;
        bool bar;
        bool missions;
        bool commodity;
        bool outfits;
        bool shipyard;
        const char* descrip;
        const char* bar_descrip;

        //Load first asset
        node = mxmlFindElement(Asset_elem, tree, "asset", NULL, NULL, MXML_DESCEND);
        //Start loading the rest of the ssys elements (but fail if first element is NULL)
        int i = 1;
        while (node != NULL){
            //Load name attrib
            name_tmp = mxmlElementGetAttr(node, "name");

            //Mark Branching nodes
            //Pos Element
            subnode_pos = mxmlFindElement(node, Asset_elem, "pos", NULL, NULL, MXML_DESCEND);
            //GFX Element
            subnode_GFX = mxmlFindElement(node, Asset_elem, "GFX", NULL, NULL, MXML_DESCEND);
            //Presence Element
            subnode_pres = mxmlFindElement(node, Asset_elem, "presence", NULL, NULL, MXML_DESCEND);
            //General Element
            subnode_gen = mxmlFindElement(node, Asset_elem, "general", NULL, NULL, MXML_DESCEND);
            //Services Sub-element
            subnode_serv = mxmlFindElement(subnode_gen, Asset_elem, "services", NULL, NULL, MXML_DESCEND);

            //Get Pos parameters x and y
            x_pos = GetFloat(subnode_pos, "x");

            y_pos = GetFloat(subnode_pos, "y");

            //Get GFX filenames
            gfx_space = GetString(subnode_GFX, "space");

            gfx_ext = GetString(subnode_GFX, "exterior");

            //Get Presence Parameters (faction, value, and range)

            pres_fac = GetString(subnode_pres, "faction");

            pres_val = GetFloat(subnode_pres, "value");

            pres_range = GetInt(subnode_pres, "range");

            //Get elements from general node (class, population, servicesTODO, description, bar)
            plan_class = GetString(subnode_gen, "class");

            population = GetInt(subnode_gen, "population");

            //Get available services as true/false values
            land = TagIsPresent(subnode_serv, "land");
            refuel = TagIsPresent(subnode_serv, "refuel");
            bar = TagIsPresent(subnode_serv, "bar");
            missions = TagIsPresent(subnode_serv, "missions");
            commodity = TagIsPresent(subnode_serv, "commodity");
            outfits = TagIsPresent(subnode_serv, "outfits");
            shipyard = TagIsPresent(subnode_serv, "shipyard");

            //Get Descriptions
       //     descrip = GetString(subnode_gen, "description");
            descrip = "TODO";
            bar_descrip = "TODO";

       //     bar_descrip = GetString(subnode_gen, "bar");


            //Generate tmp Asset
            Asset asset_sys(i, node, name_tmp, x_pos, y_pos, gfx_space, gfx_ext, pres_fac,
                            pres_val, pres_range, plan_class, population, land, refuel,
                            bar, missions, commodity, outfits, shipyard, descrip, bar_descrip);
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
