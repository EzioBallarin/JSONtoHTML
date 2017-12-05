/**
 *  File Name: JSONDataObject.hpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Tue 05 Dec 2017 02:23:16 PM PST
 *
 *  Description: Class definition for JSONDataObject
 *
 */

#ifndef JSON_DATA_OBJECT_H
#define JSON_DATA_OBJECT_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "JSONDataItem.hpp"

class JSONDataObject {
    public:
        JSONDataObject();
        virtual ~JSONDataObject();
        std::vector<JSONDataItem *> *listOfDataItems() const { return _listOfDataItems; }
        void parseFromJSONstream(std::fstream &stream);
        virtual void print();
        std::string valueForStringAttribute(std::string s);
        int valueForIntegerAttribute(std::string s);

    private:
        std::vector<JSONDataItem *> *_listOfDataItems;
};
#endif
