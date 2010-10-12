#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <string>
#include <vector>
#include <wx/wx.h>
//#include "nxml.h"
//#include "space.h"
#include "libxml/parser.h"
#include "libxml/xmlwriter.h"
#include <libxml/tree.h>


class APlanet{
public:
    APlanet();


private:



};


class SSystem{
public:
    //Constructors
    SSystem(){};
    //Make SSystem from XML Definition. Pass ptr to node
    SSystem(xmlNodePtr Nptr, xmlDocPtr Dptr){
        name = wxString((char *)xmlGetProp(Nptr, (xmlChar*)"name"), wxConvUTF8);
        //Move to next level down, the <general> element
        Nptr = Nptr->xmlChildrenNode;
        //Move one more level down to the <radius> element
        Nptr = Nptr->xmlChildrenNode;
        //Get Radius value
        if (!xmlStrcmp(Nptr->name, (const xmlChar *)"radius")) {
            char* contents = (char*)xmlNodeGetContent(Nptr);
            std::string test1 = std::string(contents);
            radius = wxString(contents, wxConvUTF8);
        }
    }
    //Destructor
    ~SSystem(){
        //Clear Planets vect[or
        Planets.clear();
    }

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
/*
    XmlO(std::string filename){
        file = xmlParseFile(filename.c_str());

    } */
    //Destructor
    ~XmlO(){
        delete file;
    }
    /**Methods */
    //(Re)Set file
    void Set(std::string fname){
        file = xmlParseFile(fname.c_str());
    }
    //Load Systems
    void load(std::string filenam){
        //Only handle nodes, foolish XML library
//       xml_onlyNodes(node);   //Doesn't work, complains about continue statement
        file = xmlParseFile(filenam.c_str()); //Get XmlDocPtr
        node = file->xmlChildrenNode; //Set NodePtr to main node
        //TODO: Error handling here: Is this the proper type of xml file?
        node = node->xmlChildrenNode; //Set NodePtr to first system node
        //TODO: More Error handling, is there a node here?

        //Add systems to vector in turn (right now just adds 3 systems)
        while(node != NULL) {
            if ((!xmlStrcmp(node->name, (const xmlChar *)"ssys"))){
                //Create new system from XML Def
                SSystem tmp(node, file);
                //Add it to the Sys vector
                Sys.push_back(tmp);
                //Move NodePtr to next node
            }
            node = node->next;
        }
    }



    xmlDocPtr file;     //Pointer to xml file
    xmlNodePtr node;  //Pointer to node of interest
    std::vector<SSystem> Sys; //Vector of Systems --MUAHAHAHAHA!, we are vectorized. All Systems under my command! -- Sorry

};

#endif // SYSTEM_H_INCLUDED
