/**
 *  File Name: JSONArray.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Tue 05 Dec 2017 02:23:23 PM PST
 *
 *  Description: Definition of JSONArray class
 *
 */

#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "JSONDataObject.hpp"

class JSONArray {
    public:
        JSONArray();
        ~JSONArray();
        std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
        virtual JSONDataObject *jsonObjectNode() = 0;
        int numJSONObjects();
        void parseJSONArray(std::fstream &stream);
        virtual void print();

    protected:
        std::vector<JSONDataObject *> *_listOfDataObjects;

};
#endif
