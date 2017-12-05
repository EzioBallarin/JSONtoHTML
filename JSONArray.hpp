/**
 *  File Name: JSONArray.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Sun 03 Dec 2017 09:30:20 PM PST
 *
 *  Description: Definition of JSONArray class
 *
 */
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
