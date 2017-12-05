/**
 *  File Name: JSONArray.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Tue 05 Dec 2017 02:19:18 PM PST
 *
 *  Description: Implementation of JSONArray class.
 *
 */

#include "JSONArray.hpp"

JSONArray::JSONArray() {

}

JSONArray::~JSONArray() {

}
/*
virtual JSONDataObject *jsonObjectNode() = 0;
int numJSONObjects();
void parseJSONArray(std::fstream &stream);
virtual void print();
*/
void JSONArray::parseJSONArray(std::fstream &stream) {
    char c;
    stream >> c;
    std::cout << c;
}

JSONDataObject* JSONArray::jsonObjectNode() {
    return nullptr;
}

void JSONArray::print() {

}
