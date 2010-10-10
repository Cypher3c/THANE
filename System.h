#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <string>
#include <vector>
#include <wx/wx.h>
//#include "nxml.h"
//#include "space.h"
//#include "libxml/parser.h"
//#include "libxml/xmlwriter.h"



class APlanet{
public:
    APlanet();


private:



};


class SSystem{
public:
    //Constructors
    SSystem();
    //Make SSystem from XML Definition. Pass ptr to node
    SSystem(xmlNodePtr Nptr){
        name = xml_nodeProp(Nptr, "Name");
    }
    //Destructor
    ~SSystem(){
        //Clear Planets vect[or
        Planets.clear();
    }

    std::vector<APlanet> Planets;

    std::string name;




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
        //Add first system
        for(int i = 1; i < 4; i++){
            //Create new system from XML Def
            SSystem tmp(node);
            //Add it to the Sys vector
            Sys.push_back(tmp);
            //Move NodePtr to next node
            xml_nextNode(node);
        }
    }



    xmlDocPtr file;     //Pointer to xml file
    xmlNodePtr node;  //Pointer to node of interest
    std::vector<SSystem> Sys; //Vector of Systems --MUAHAHAHAHA!, we are vectorized. All Systems under my command! -- Sorry

};

#endif // SYSTEM_H_INCLUDED
