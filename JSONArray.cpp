/**
 *  File Name: JSONArray.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Wed 06 Dec 2017 12:25:47 PM PST
 *
 *  Description: Implementation of JSONArray class.
 *
 */

#include "JSONArray.hpp"

// Initialize new vector of JSONDataObject's when a JSONArray is created
JSONArray::JSONArray() {
    _listOfDataObjects = new std::vector<JSONDataObject*>();
}

JSONArray::~JSONArray() {
    listOfDataObjects()->erase(listOfDataObjects()->begin(), listOfDataObjects()->end());
    delete _listOfDataObjects;
}

/**
 * Name: parseJSONArray() 
 * 
 * Purpose: Parse a given JSON filestream for objects.
 * Parameters: std::fstream &stream - the JSON filestream to read from.
 * Return: None.
 * 
 * Notes: We expect the internal cursor of the JSON filestream to be at
 * the beginning of the JSON array. After parsing, the internal cursor will
 * be at the end of the array.
 */
void JSONArray::parseJSONArray(std::fstream &stream) {
    char c;
    while (stream.good()) {
        stream >> c;
        
        // New JSONDataObject encountered, 
        // check for this JSONArray empty,
        // then add the new object to the list.
        if (c == '{') {
            

            JSONDataObject* newObj = jsonObjectNode(); 
            newObj->parseFromJSONstream(stream);
            _listOfDataObjects->push_back(newObj);

        }
    }
}

/**
 * Name: jsonObjectNode()
 * 
 * Purpose: Returns a pointer to a generic type of element in this
 *          JSONArray's collection. I.e. Artists.jsonObjectNode() would
 *          return a pointer to a new Artist() object, and so on.
 * Parameters: None.
 * Return: A pointer to the type of elements contained in this JSONArray.
 * 
 */
JSONDataObject* JSONArray::jsonObjectNode() {
    return new JSONDataObject();
}

/**
 * Name: numJSONObjects()
 * 
 * Purpose: Determine the number of JSON objects in this JSON array.
 * Parameters: None.
 * Return: The number of JSON objects in the internal vector.
 * 
 */
int JSONArray::numJSONObjects() {
    return _listOfDataObjects->size();
}

/**
 * Name: print()
 * 
 * Purpose: Debugging the objects contained in this JSON array.
 *          Output varies in format, but generally tests the operations
 *          of the underlying objects, along with the operations of the
 *          JSONArray.
 * Parameters: None.
 * Return: None.
 * 
 */
void JSONArray::print() {
    std::cout << "JSON Array contains: " << std::endl;
    for (std::vector<JSONDataObject*>::iterator it = _listOfDataObjects->begin();
         it != _listOfDataObjects->end(); ++it) {
        (*it)->print();
    }
    std::cout << std::endl << "Num objects: " << numJSONObjects() << std::endl;

}
