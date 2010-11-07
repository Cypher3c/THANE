#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <string>
#include <vector>
#include <sstream>
#include <wx/wx.h>
//#include "nxml.h"
//#include "space.h"
#include <mxml.h>
#include <wx/msgdlg.h>


class Commodity
{
public:
    //Constructors
    Commodity(){};
    Commodity(const char* p_name, const char* p_descrip, float p_price)
    {
        name = wxString::FromAscii(p_name);
        description = wxString::FromAscii(p_descrip);
        price = p_price;
    }

    wxString name;
    wxString description;
    float price;


};

class Item
{
public:
    Item(const char* p_name)
    {
        name = wxString::FromAscii(p_name);
    }

    wxString name;

private:



};


class Asset
{
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
    Asset(int p_ID, mxml_node_t *sysnode_t, const char* p_name, const char* p_x, const char* p_y, const char* gfx_space_tmp, const char* gfx_ext_tmp,
          const char* p_fac, const char* p_presval, const char* p_presrange, const char* p_plan_class, const char* p_pop, bool p_land, bool p_refuel, bool p_bar, bool p_missions, bool p_commodity,
          bool p_outfits, bool p_shipyard, const char* p_descrip, const char* p_bar_descrip)
    {
        //Set ID
        ID = p_ID;
        sys_node = sysnode_t;
        name = wxString::FromAscii(p_name);
        x_pos = wxString::FromAscii(p_x);
        y_pos = wxString::FromAscii(p_y);
        gfx_space = wxString::FromAscii(gfx_space_tmp);
        gfx_ext = wxString::FromAscii(gfx_ext_tmp);
        //See if faction is present
        if (p_fac != NULL)
        {
            pres_faction = wxString::FromAscii(p_fac);
        }
        else
        {
            pres_faction = wxT("n");
        }
        pres_value = wxString::FromAscii(p_presval);
        pres_range = wxString::FromAscii(p_presrange);
        planet_class = wxString::FromAscii(p_plan_class);
        population = wxString::FromAscii(p_pop);
        land = p_land;
        refuel = p_refuel;
        bar = p_bar;
        missions = p_missions;
        commodity = p_commodity;
        outfits = p_outfits;
        shipyard = p_shipyard;
        //set Description string to (null) if empty
        if (p_descrip != NULL)
        {
            description = wxString(p_descrip, wxConvUTF8);
        }
        else
        {
            description = wxString("(null)", wxConvUTF8);
        }
        bar_description = wxString(p_bar_descrip, wxConvUTF8);

        IsModified = false;

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
    wxString x_pos;
    wxString y_pos;
    wxString pres_faction;
    wxString pres_value;
    wxString pres_range;
    wxString planet_class;
    wxString population;
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
    bool IsModified;


};

class XmlO
{
public:
    /**Methods */
    //(Re)Set file
    void Set(std::string fname)
    {
        //TODO
    }

    //XML Reading Functions

    const char* GetString(mxml_node_t *nd, const char* tag)
    {
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if (temp_sub_node != NULL)
        {
            return temp_sub_node->child->value.text.string;
        }
        else
        {
            return NULL;
        }
    }



    const char* GetStringOpaque(mxml_node_t *nd, const char* tag)
    {
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND_FIRST);
        if (temp_sub_node != NULL)
        {
            return temp_sub_node->child->value.opaque;
        }
        else
        {
            return NULL;
        }
    }

    int GetInt(mxml_node_t *nd, const char* tag)
    {
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if (temp_sub_node != NULL)
        {
            //  tmp_str = (temp_sub_node->child->value.text.string);
            return atoi(temp_sub_node->child->value.opaque);
        }
        else
        {
            return NULL;
        }

    }
    float GetFloat(mxml_node_t *nd, const char* tag)
    {
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);
        if (temp_sub_node != NULL)
        {
            //  tmp_str = (temp_sub_node->child->value.text.string);
            return atof(temp_sub_node->child->value.opaque);
        }
        else
        {
            return NULL;
        }

    }

    bool TagIsPresent(mxml_node_t *nd, const char* tag)
    {
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);

        if (temp_sub_node != NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    //XML Writing Functions
    //Return code to signify completion status

    //Params: asset node pointer, tag to change text in, text to add
    int SetStringOpaque(mxml_node_t *nd, const char * tag, const char* text)
    {
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);

        //If node exists:
        if (temp_sub_node != NULL)
        {
            mxmlSetOpaque(temp_sub_node->child, text);
            return 1; //success
        }
        else
        {
            return 0; //no node exists
        }
    }

    int SetFloat(mxml_node_t *nd, const char * tag, float value)
    {
        mxml_node_t *temp_sub_node;
        temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);

        //If node exists:
        if (temp_sub_node != NULL)
        {
            char* tmp;
            snprintf(tmp, 79, "%f",value);
            mxmlSetOpaque(temp_sub_node->child, tmp);
            return 1; //success
        }
        else
        {
            return 0; //no node exists
        }
    }
        int SetBool(mxml_node_t *nd, const char * parent_tag, const char * tag, bool value)
        {
            mxml_node_t *temp_sub_node;
            temp_sub_node = mxmlFindElement(nd, nd, tag, NULL, NULL, MXML_DESCEND);

            //If node exists:
            if (temp_sub_node != NULL)
            {
                if (!value) //if value is false
                {
                    mxmlDelete(temp_sub_node); //delete element to turn off flag
                }
                //Otherwise do nothing
                return 1; //success
            }
            else //If flag is not already present
            {
                if(value) //if value is true
                {
                    //Set temp node to parent element
                    temp_sub_node = mxmlFindElement(nd, nd, parent_tag, NULL, NULL, MXML_DESCEND);
                    if (temp_sub_node != NULL) //Make sure the parent element exists
                    {
                        //Create element with appropriate name
                        mxml_node_t *flag = mxmlNewElement(temp_sub_node, tag);
                        return 1; //Success
                    }
                    else
                    {
                        return 0; //Something went wrong
                    }
                }
            }
    }

    //Massively Enormous saving loop

    virtual int WriteChanges(){}

    //Generate New XML file
    //TODO

    void MakeNew();

    //Load XML file into XmlO
    //Filename, type (1 = assets.xml, 2 = commodities.xml)
    void load(wxString filenam)
    {
        //First, convert wxString to std::string for safety (char* is transient), then to const char*
        std::string tmp_filenam = std::string(filenam.mb_str());
        const char* tmp_filenam2 = tmp_filenam.c_str();
        //Get pointer to file
        fp = fopen(tmp_filenam2,"r");
        //Load tree
        tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);

        //Close file (be nice!)
        fclose(fp);

    }
    void save(wxString filenam)
    {
        std::string tmp_filenam = std::string(filenam.mb_str());
        const char* tmp_filenam2 = tmp_filenam.c_str();
        //Create/Open file for editing, wiping its contents
        fp = fopen(tmp_filenam2,"w");

        //Save XML tree to file
        mxmlSaveFile(tree, fp, MXML_NO_CALLBACK);
        //Close file
        fclose(fp);

    }

    virtual int Parse(){}

    //Update a parameter in the xml tree from the correct form. obj a node pointer to the asset/commodity to be updated
    //param is the name of the parameter, and obj_type is the type of object: 1 = asset, 2 = commodity
    //data is the (text) value to change the param to
    int UpdateParam_Str(mxml_node_t *obj, const char* param, wxString data)
    {
            mxml_node_t *tmp;
            char* tmp_str;
            //Special case for changing name param (the only attribute so far in asset.xml)
            if (param == "name")
            {
                mxmlElementSetAttr(obj, "name", data.mb_str());
                return 1; //Success
            }
            else
            {
                //Descend to proper depth
                tmp = mxmlFindElement(obj, obj, param, NULL, NULL, MXML_DESCEND);
                strncpy(tmp_str, data.mb_str(), 1024);
                mxmlSetOpaque(tmp, tmp_str);
                return 1; //Success
            }

    }
    //Same as above, but for updating object name. Only need the node pointer and the data to write
    int UpdateName(mxml_node_t *obj, wxString data)
    {


        return 1; //Hopefully success, error handling to be written later
    }


    FILE *fp; //pointer to file of interest
    mxml_node_t *tree; //Pointer to main node
    mxml_node_t *Asset_elem; //Pointer to Main Asset Element
    mxml_node_t *Comm_elem; //Pointer to Main Commodities element
};

class XmlAsset : public XmlO
{
public:

    int Parse()
    {

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
        const char* name_tmp; //String for names of asset
        const char* tmp_str; //String for anything :P
        const char* x_pos; //X_pos Float
        const char* y_pos; //Y_pos Float
        const char* gfx_space;
        const char* gfx_ext;
        const char* pres_fac;
        const char* pres_val;
        const char* pres_range;
        const char* plan_class;
        const char* population;
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
        while (node)
        {
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
            x_pos = GetStringOpaque(subnode_pos, "x");

            y_pos = GetStringOpaque(subnode_pos, "y");

            //Get GFX filenames
            gfx_space = GetStringOpaque(subnode_GFX, "space");

            gfx_ext = GetStringOpaque(subnode_GFX, "exterior");

            //Get Presence Parameters (faction, value, and range)

            pres_fac = GetStringOpaque(subnode_pres, "faction");

            pres_val = GetStringOpaque(subnode_pres, "value");

            pres_range = GetStringOpaque(subnode_pres, "range");

            //Get elements from general node (class, population, servicesTODO, description, bar)
            plan_class = GetStringOpaque(subnode_gen, "class");

            population = GetStringOpaque(subnode_gen, "population");

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
         //   ParseCommodities(subnode_gen);

            //Generate tmp Asset
            Asset asset_sys(i, node, name_tmp, x_pos, y_pos, gfx_space, gfx_ext, pres_fac,
                            pres_val, pres_range, plan_class, population, land, refuel,
                            bar, missions, commodity, outfits, shipyard, descrip, bar_descrip);
            //Load system with its node into vector of Assets
            Assets.push_back(asset_sys);

            //Load next Asset
            node = mxmlFindElement(node, tree, "asset", NULL, NULL, MXML_DESCEND);
            //Increment ID counter
            i++;
        }
        return 1; //Success
    }

    virtual int WriteChanges(){

        //Parse through Asset objects
        for(int i = 0; i < Assets.size(); i++)
        {
            //Check and see if Asset is modified
            if(Assets.at(i).IsModified){

                SetStringOpaque(Assets.at(i).sys_node, "x", Assets.at(i).x_pos.mb_str()); //Set X
                SetStringOpaque(Assets.at(i).sys_node, "y", Assets.at(i).y_pos.mb_str()); //Set Y
                SetStringOpaque(Assets.at(i).sys_node, "space", Assets.at(i).gfx_space.mb_str()); //Set GFX_space
                SetStringOpaque(Assets.at(i).sys_node, "exterior", Assets.at(i).gfx_ext.mb_str()); //Set GFX_ext
               // SetStringOpaque(Assets.at(i).sys_node, "value", Assets.at(i).pres_value.mb_str()); //Set Faction
                SetStringOpaque(Assets.at(i).sys_node, "value", Assets.at(i).pres_value.mb_str()); //Set Presence value
                SetStringOpaque(Assets.at(i).sys_node, "range", Assets.at(i).pres_range.mb_str()); //Set Presence range

                SetStringOpaque(Assets.at(i).sys_node, "class", Assets.at(i).planet_class.mb_str()); //Set Planet Class
                SetStringOpaque(Assets.at(i).sys_node, "population", Assets.at(i).population.mb_str()); //Set Population


                SetBool(Assets.at(i).sys_node, "services", "land", Assets.at(i).land); //Set Land flag
                SetBool(Assets.at(i).sys_node, "services", "refuel", Assets.at(i).refuel); //Set Refuel flag
                SetBool(Assets.at(i).sys_node, "services", "bar", Assets.at(i).bar); //Set Bar flag
                SetBool(Assets.at(i).sys_node, "services", "missions", Assets.at(i).missions); //Set Missions flag
                SetBool(Assets.at(i).sys_node, "services", "commodity", Assets.at(i).commodity); //Set Commodity flag
                SetBool(Assets.at(i).sys_node, "services", "outfits", Assets.at(i).outfits); //Set Outfits flag
                SetBool(Assets.at(i).sys_node, "services", "shipyard", Assets.at(i).shipyard); //Set Shipyard flag

                SetStringOpaque(Assets.at(i).sys_node, "description", Assets.at(i).description.mb_str()); //Set Description
                SetStringOpaque(Assets.at(i).sys_node, "bar", Assets.at(i).bar_description.mb_str()); //Set Bar Description


                //Turn off 'modified' flag for asset
                Assets.at(i).IsModified = false;

            }

        }
    }

    std::vector<Asset> Assets; //Vector of Assets --MUAHAHAHAHA!, we are vectorized. All Assets under my command! -- Sorry
};

class XmlCommodity : public XmlO
{
public:
    int Parse()
    {

        //Load <Systems> node
        Comm_elem = mxmlWalkNext(tree, tree, MXML_DESCEND_FIRST);

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
        while (node)
        {
            //Load name attrib
            name = mxmlElementGetAttr(node, "name");

            //Get description, if any
            description = GetStringOpaque(node, "description");

            //Get Price, if any
            price = GetFloat(node, "price");

            //Generate tmp Asset
            Commodity comms_tmp(name, description, price);
            //Load system with its node into vector of Assets
            Commodities.push_back(comms_tmp);
            //Load next Asset
            node = mxmlFindElement(node, tree, "commodity", NULL, NULL, MXML_DESCEND);
            //Increment ID counter
            i++;
        }
        return 1; //Success
    }

    std::vector<Commodity> Commodities; //Vector of commodities

};


#endif // SYSTEM_H_INCLUDED
