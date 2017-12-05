/**
 *  File Name: JSONDataItem.hpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Mon 04 Dec 2017 05:43:50 PM PST
 *
 *  Description: Class description for JSONDataItem
 *
 */

#ifndef JSON_DATA_ITEM_H
#define JSON_DATA_ITEM_H

class JSONDataItem {
    public:
        JSONDataItem();
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
};
#endif
