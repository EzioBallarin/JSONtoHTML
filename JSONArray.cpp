/**
 *  File Name: JSONArray.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Tue 05 Dec 2017 05:28:22 PM PST
 *
 *  Description: Implementation of JSONArray class.
 *
 */

#include "JSONArray.hpp"

JSONArray::JSONArray() {
    _listOfDataObjects = new std::vector<JSONDataObject*>();
}

JSONArray::~JSONArray() {
    delete _listOfDataObjects;
}
/*
virtual JSONDataObject *jsonObjectNode() = 0;
int numJSONObjects();
void parseJSONArray(std::fstream &stream);
virtual void print();
*/
void JSONArray::parseJSONArray(std::fstream &stream) {
    char c;
    std::cout << std::endl << "Parsing array..." << std::endl;
    while (stream.good()) {
        stream >> c;
        
        // New JSONDataObject encountered, 
        // check for this JSONArray empty,
        // then add the new object to the list.
        if (c == '{') {
            
            JSONDataObject* newObj = new JSONDataObject();
            newObj->parseFromJSONstream(stream);
            _listOfDataObjects->push_back(newObj);

        }
    }
}

JSONDataObject* JSONArray::jsonObjectNode() {
    return nullptr;
}

void JSONArray::print() {
    std::cout << "JSON Array contains: " << std::endl;
    for (std::vector<JSONDataObject*>::iterator it = _listOfDataObjects->begin();
         it != _listOfDataObjects->end(); ++it) {
        (*it)->print();
    }
    std::vector<JSONDataObject*>::iterator it = _listOfDataObjects->begin();
    std::cout << "Looking for artist name" << std::endl;
    while (it != _listOfDataObjects->end()) {
        std::string name = (*it)->valueForStringAttribute("name");
        std::cout << name << std::endl;
        ++it;
    }
}
