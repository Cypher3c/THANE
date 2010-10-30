#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <string>
#include <vector>
#include <wx/wx.h>
//#include "nxml.h"
//#include "space.h"
#include <mxml.h>
#include <wx/msgdlg.h>


class Commodity{
public:
    //Constructors
    Commodity(){};
    Commodity(const char* p_name, const char* p_descrip, float p_price){
        name = wxString::FromAscii(p_name);
        description = wxString::FromAscii(p_descrip);
        price = p_price;
    }

    wxString name;
    wxString description;
    float price;


};

class Item{
public:
    Item(const char* p_name){
        name = wxString::FromAscii(p_name);
    }

    wxString name;

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
        description = wxString(p_descrip, wxConvUTF8);
        bar_description = wxString(p_bar_descrip, wxConvUTF8);

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
    std::vector<Commodity> Commodities;
    std::vector<Item> Items;


};

class XmlO{
public:
    //Constructors
    XmlO(){};

    //Destructor
    ~XmlO(){};
    /**Methods */
    //(Re)Set file
    void Set(std::string fname){
        //TODO
    }

    //XML Reading Functions

    const char* GetString(mxml_node_t *nd, const char* tag){
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if(temp_sub_node != NULL){
            return temp_sub_node->child->value.text.string;
        }
        else{
            return NULL;
        }
    }



    const char* GetStringOpaque(mxml_node_t *nd, const char* tag){
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND_FIRST);
        if(temp_sub_node != NULL){
            return temp_sub_node->child->value.opaque;
        }
        else{
            return NULL;
        }
    }

    int GetInt(mxml_node_t *nd, const char* tag){
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if(temp_sub_node != NULL){
          //  tmp_str = (temp_sub_node->child->value.text.string);
            return atoi(temp_sub_node->child->value.opaque);
        }
        else{
            return NULL;
        }

    }
    float GetFloat(mxml_node_t *nd, const char* tag){
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if(temp_sub_node != NULL){
          //  tmp_str = (temp_sub_node->child->value.text.string);
            return atof(temp_sub_node->child->value.opaque);
        }
        else{
            return NULL;
        }

    }

        bool TagIsPresent(mxml_node_t *nd, const char* tag){
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);

        if(temp_sub_node != NULL){
            return true;
        }
        else{
            return false;
        }
    }


    //XML Writing Functions
    //Return code to signify completion status

    //Params: asset node pointer, tag to change text in, text to add
    int SetStringOpaque(mxml_node_t *nd, const char * tag, const char* text){
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);

        //If node exists:
        if(temp_sub_node != NULL){
            mxmlSetOpaque(temp_sub_node->child, text);
            return 1; //success
        }
        else{
            return 0; //no node exists
        }
    }

    //Load XML file into XmlO
    //Filename, type (1 = assets.xml, 2 = commodities.xml)
    void load(wxString filenam, int type_id){
        //First, convert wxString to std::string for safety (char* is transient), then to const char*
        std::string tmp_filenam = std::string(filenam.mb_str());
        const char* tmp_filenam2 = tmp_filenam.c_str();
        //Get pointer to file
        fp = fopen(tmp_filenam2,"r");
        //Load tree
        tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);

        //Close file (be nice!)
        fclose(fp);

        if(type_id == 1){
            ParseAssets(tree);
        }
        else if (type_id == 2){
            ParseCommodities(tree);

        }

    }

     int ParseCommodities(mxml_node_t *p_tree){

            //Load <Systems> node
            Comm_elem = mxmlWalkNext(p_tree, p_tree, MXML_DESCEND_FIRST);

            //Start loading <asset> elements

            //Temporary Elements
            mxml_node_t *node; //Node to save
            const char* name; //String for names of commodity
            const char* description; //String for description
            float price;

            //Load first commodity
            node = mxmlFindElement(Comm_elem, tree, "Commodities", NULL, NULL, MXML_DESCEND);
            node = mxmlFindElement(node, tree, "commodity", NULL, NULL, MXML_DESCEND);
            //Start loading the rest of the ssys elements (but fail if first element is NULL)
            int i = 1;
                while (node){
                    //Load name attrib
                    name = mxmlElementGetAttr(node, "name");

                    //Get description, if any
                    description = GetStringOpaque(node, "description");

                    //Get Price, if any
                    price = GetFloat(node, "price");

                //Generate tmp Asset
                Commodity comms_tmp(name, description, price);
                //Load system with its node into vector of Assets
                MainCommodities.push_back(comms_tmp);
                //Load next Asset
                node = mxmlFindElement(node, tree, "commodity", NULL, NULL, MXML_DESCEND);
                //Increment ID counter
               i++;
           }
           return 1; //Success
        }
    int ParseAssets(mxml_node_t *p_tree){

            //Load <Systems> node
            Asset_elem = mxmlWalkNext(p_tree, p_tree, MXML_DESCEND_FIRST);

            //Start loading <asset> elements

            //Temporary Elements
            mxml_node_t *node; //Node to save
            mxml_node_t *subnode_pos; //Subnode for pos nodes
            mxml_node_t *subnode_GFX; //Subnode for GFX nodes
            mxml_node_t *subnode_pres; //Subnode for presence nodes
            mxml_node_t *subnode_gen; //Subnode for general nodes
            mxml_node_t *subnode_serv; //Subnode for services nodes
        //    mxml_node_t *subnode; //Subnode
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
            std::vector<const char*> temp_commodities;

            //Load first asset
            node = mxmlFindElement(Asset_elem, tree, "asset", NULL, NULL, MXML_DESCEND);
            //Start loading the rest of the ssys elements (but fail if first element is NULL)
            int i = 1;
                while (node){
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
                gfx_space = GetStringOpaque(subnode_GFX, "space");

                gfx_ext = GetStringOpaque(subnode_GFX, "exterior");

                //Get Presence Parameters (faction, value, and range)

                pres_fac = GetStringOpaque(subnode_pres, "faction");

                pres_val = GetFloat(subnode_pres, "value");

                pres_range = GetInt(subnode_pres, "range");

                //Get elements from general node (class, population, servicesTODO, description, bar)
                plan_class = GetStringOpaque(subnode_gen, "class");

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

                descrip = GetStringOpaque(subnode_gen, "description");
                bar_descrip = GetStringOpaque(subnode_gen, "bar");

                //Get commodities (Temp, will be checked against list in future versions)
                ParseCommodities(subnode_gen);

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
           return 1; //Success
        }
    //Update a parameter in the xml tree from the correct form. obj a node pointer to the asset/commodity to be updated
    //param is the name of the parameter, and obj_type is the type of object: 1 = asset, 2 = commodity
    //data is the (text) value to change the param to
    int UpdateParam(mxml_node_t *obj,  int obj_type, const char* param, wxString data){
        switch(obj_type)
        {
            case 1 :
            //Special case for changing name param (the only attribute so far)

            break;

            default :
            return 0; //Error
        }

    }
    //Same as above, but for updating object name. Only need the node pointer and the data to write
    int UpdateName(mxml_node_t *obj, wxString data){
        mxmlElementSetAttr(obj, "name", data.mb_str());

        return 1; //Hopefully success, error handling to be written later
    }


    std::vector<Asset> Sys; //Vector of Systems --MUAHAHAHAHA!, we are vectorized. All Systems under my command! -- Sorry
    std::vector<Commodity> MainCommodities; //Vector of commodities
    FILE *fp; //pointer to file of interest
    mxml_node_t *tree; //Pointer to main node
    mxml_node_t *Asset_elem; //Pointer to Main Asset Element
    mxml_node_t *Comm_elem; //Pointer to Main Commodities element
};

#endif // SYSTEM_H_INCLUDED
