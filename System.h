#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <string>
#include <vector>
#include <wx/wx.h>
#include "tinystr.h"
#include "tinyxml.h"



class APlanet{
public:
    APlanet();


private:



};


class SSystem{
public:
    //Constructors
    SSystem();
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


/*
    XmlO(std::string filename){
        file = xmlParseFile(filename.c_str()); */
    /**Methods */
    //Load Systems
    void load(std::string filenam){
        //Only handle nodes, foolish XML library
//       xml_onlyNodes(node);   //Doesn't work, complains about continue statement
        file = TiXmlDocument(filenam.c_str()); //Load Document into object
        //Define handles
    //    fdoc = TiXmlHandle(&file); //Handle to document
    //    TiXmlHandle doc(&file); //Handle to root
    //    pElem = file.FirstChildElement("Systems"); //main element
    //    node = file->xmlChildrenNode; //Set NodePtr to main node
        //TODO: Error handling here: Is this the proper type of xml file?
      //  node = node->xmlChildrenNode; //Set NodePtr to first system node
        //TODO: More Error handling, is there a node here?

        //Add systems to vector in turn (right now just adds 3 systems)
        //Add first system
    //    for(int i = 1; i < 4; i++){
            //Create new system from XML Def
         //   SSystem tmp(node);
            //Add it to the Sys vector
        //    Sys.push_back(tmp);
            //Move NodePtr to next node
        //    xml_nextNode(node);
      //  }
    }



    TiXmlDocument file;     //XML Doc (TinyXML)
    TiXmlElement* root;  //Pointer to root element
  //  TiXmlElement* pElem; //Element pointer
    const std::string root_name;
   // TiXmlHandle f_root; //Root Handle
    std::vector<SSystem> Sys; //Vector of Systems --MUAHAHAHAHA!, we are vectorized. All Systems under my command! -- Sorry

};

#endif // SYSTEM_H_INCLUDED
