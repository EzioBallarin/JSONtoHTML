/**
 *  File Name: JSONDataObject.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Tue 05 Dec 2017 03:49:20 PM PST
 *
 *  Description:
 *
 */

#include "JSONDataObject.hpp"

JSONDataObject::JSONDataObject() {
    _listOfDataItems = new std::vector<JSONDataItem*>();
}

JSONDataObject::~JSONDataObject() {
    delete _listOfDataItems;
}

void JSONDataObject::parseFromJSONstream(std::fstream &stream) {
    char c = stream.get();
    std::cout << std::endl << "Parsing Object" << std::endl;
    while (stream.good() && c != '}' && c != ']') {
        
        if (c == '"') {
            JSONDataItem* newPair = new JSONDataItem();
            newPair->parseJSONItem(stream);
            _listOfDataItems->push_back(newPair);
        }
            
        c = stream.get();
    }
}

void JSONDataObject::print() {
    std::cout << "JSON Data Object:" << std::endl;
    for (std::vector<JSONDataItem*>::iterator it = _listOfDataItems->begin();
         it != _listOfDataItems->end(); ++it) {
        (*it)->print();
    }
}
