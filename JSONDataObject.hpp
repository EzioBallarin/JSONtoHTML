/**
 *  File Name: JSONDataObject.hpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Sun 03 Dec 2017 08:48:28 PM PST
 *
 *  Description: Class definition for JSONDataObject
 *
 */

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
