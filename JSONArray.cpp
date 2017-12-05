/**
 *  File Name: JSONArray.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Mon 04 Dec 2017 05:43:40 PM PST
 *
 *  Description: Implementation of JSONArray class.
 *
 */

#include "JSONArray"

void JSONArray::parseJSONArray(std::fstream &stream) {
    char cc[2], prev = ' ';
    cc[1] = '\0';
    // we expect this to be a open-bracket character.
    if( ! (stream >> cc[0]) || cc[0] != '[' )  
    // print an error message and exit
    do {
        JSONDataObject *dItem = jsonObjectNode();
        dItem->parseFromJSONstream(stream);
        _listOfDataObjects->push_back(dItem);

        if( ! (stream >> cc[0]) ) 
        // print an error message and
        if( cc[0] != ']' && cc[0] != ',' )  
        // print an error message and exit            

    } while(cc[0]!=']');
}
