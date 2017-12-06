/**
 *  File Name: JSONDataObject.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 12:26:29 PM PST
 *
 *  Description:
 *
 */

#include <typeinfo>
#include "JSONDataObject.hpp"

// Initialize new vector representing the items contained in this object
JSONDataObject::JSONDataObject() {
    _listOfDataItems = new std::vector<JSONDataItem*>();
}

JSONDataObject::~JSONDataObject() {
    _listOfDataItems->erase(_listOfDataItems->begin(), _listOfDataItems->end());
    delete _listOfDataItems;
}

/**
 * Name: parseFromJSONstream()
 * 
 * Purpose: Parses a full object from a given JSON filestream
 * Parameters: std::fstream &stream - the JSON filestream to parse.
 * Return: None.
 * 
 * Notes: We expect the internal cursor of the filestream to be at the
 *        start of a JSON object. The internal cursor is then modified, 
 *        and is placed at the next object in a JSON array, or at the
 *        end of the array.
 */
void JSONDataObject::parseFromJSONstream(std::fstream &stream) {
    char c = stream.get();
    while (stream.good() && c != '}' && c != ']') {
        if (c == '"') {
            JSONDataItem* newPair = new JSONDataItem();
            newPair->parseJSONItem(stream);
            _listOfDataItems->push_back(newPair);
        } 
        c = stream.get();
    }
}

/**
 * Name: print()
 * 
 * Purpose: Debugging JSONDataObjects.
 *          Output is an iterated list of JSONDataItems in this object.
 * Parameters: None.
 * Return: None.
 * 
 */
void JSONDataObject::print() {
    std::cout << "JSON Data Object:" << std::endl;
    for (std::vector<JSONDataItem*>::iterator it = _listOfDataItems->begin();
         it != _listOfDataItems->end(); ++it) {
        (*it)->print();
    }
}

/**
 * Name: valueForStringAttribute()
 * 
 * Purpose: Get the string value associated with a given attribute.
 * Parameters: std::string s - the attribute to get the value of
 * Return: The value associated with attribute s.
 * 
 */
std::string JSONDataObject::valueForStringAttribute(std::string s) {
    std::vector<JSONDataItem*>::iterator it = listOfDataItems()->begin();
    while ((*it)->attribute() != s)
        ++it;
    return (*it)->stringValue();
}

/**
 * Name: valueForIntegerAttribute()
 * 
 * Purpose: Get the integer value associated with a given attribute.
 * Parameters: std::string s - the attribute to get the value of
 * Return: The value associated with attribute s.
 * 
 */
int JSONDataObject::valueForIntegerAttribute(std::string s) {
    std::vector<JSONDataItem*>::iterator it = listOfDataItems()->begin();
    while ((*it)->attribute() != s) 
        it++;
    return (*it)->integerValue();
}
