/**
 *  File Name: JSONDataItem.hpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Sun 03 Dec 2017 08:47:45 PM PST
 *
 *  Description: Class description for JSONDataItem
 *
 */

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
