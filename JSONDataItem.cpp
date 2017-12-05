/**
 *  File Name: JSONDataItem.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Tue 05 Dec 2017 03:53:50 PM PST
 *
 *  Description:
 *
 */

#include <sstream>
#include "JSONDataItem.hpp"

JSONDataItem::JSONDataItem() {

}
/*
        void parseJSONItem(std::fstream &stream);
        std::string attribute();
        int integerValue();
        std::string stringValue();
        bool isNumber();
        void print();  // purely for debugging -- any format you want

    private:
        std::string _attribute, _svalue;
        int _ivalue;
        bool hasReadAnItem, _isNumber;

        std::string readQuotedString(std::fstream &stream);
*/
void JSONDataItem::parseJSONItem(std::fstream &stream) {

    char c;
    stream >> c;

    std::string key = "";

    while (c != '"') {
        key += c;
        stream >> c;
    }
    if (!(stream >> c) || c != ':') {
        std::cout << "Improper JSON. Found " << c << ", expected :" << std::endl;
        return;
    }
    stream >> c;
    char p = c;

    if (c == '"') {
        std::string val = "";
        stream >> c;
        while (c != '"' || p == '\\') {
            val += c;
            p = c;
            c = stream.get();
        }

        _attribute = key;
        _svalue = val;

    // Else we know that it's the artist_id key, so we convert
    // the number to an unsigned int and store it in _artistID
    } else {
        std::string val = "";
        while (c != '"' && c != ',') {
            val += c;
            stream >> c;
        }

        _attribute = key;
        _svalue = val;

    }

}

void JSONDataItem::print() {
    std::cout << "\t" << _attribute << ": " << _svalue << std::endl; 
}
