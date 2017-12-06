/**
 *  File Name: JSONDataItem.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Tue 05 Dec 2017 11:12:25 PM PST
 *
 *  Description:
 *
 */

#include <sstream>
#include "JSONDataItem.hpp"

// Empty ctor
JSONDataItem::JSONDataItem() {}

/**
 * Name: parseJSONItem()
 * 
 * Purpose: Parses a single key-value pair in a JSON filestream.
 * Parameters: std::fstream &stream - the JSON filestream to read from.
 * Return: None.
 * 
 * Notes: We assume that the internal cursor in the filestream is at the
 *        start of an attribute. This function then modifies the internal
 *        cursor, and may place it at the end of the object, or at another
 *        key-value pair.
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
        _isNumber = false;

    // Else we know that it's the artist_id key, so we convert
    // the number to an unsigned int and store it in _artistID
    } else {
        std::stringstream* s = new std::stringstream();

        // Keep adding to the val string while current char is not 
        // the next attribute or while the next char is not
        // the end of the current object
        while (c != '"' && c != ',' && stream.peek() != '}') {
            s->put(c);
            stream >> c;
        }

        unsigned val = 0;
        (*s) >> val;
        
        delete s;

        _attribute = key;
        _ivalue = val;
        _isNumber = true;

    }


}

/**
 * Name: attribute()
 * 
 * Purpose: Get the name of an attribute in a key-value pair.
 * Parameters: None.
 * Return: The attribute name as a string.
 * 
 */
std::string JSONDataItem::attribute() {
    return _attribute;
}

/**
 * Name: integerValue() 
 * 
 * Purpose: Get the integer value stored in this item.
 * Parameters: None.
 * Return: An integer representation of the JSON number parsed above.
 * 
 */
int JSONDataItem::integerValue() {
    return _ivalue;
}

/**
 * Name: stringValue()
 * 
 * Purpose: Get the string value stored in this item.
 * Parameters: None.
 * Return: A string representation of the JSON value parsed above.
 * 
 */
std::string JSONDataItem::stringValue() {
    return _svalue;
}

/**
 * Name: isNumber()
 * 
 * Purpose: Determine if this item has a number as it's value.
 * Parameters: None.
 * Return: True if this item's value is a number, false otherwise.
 * 
 */
bool JSONDataItem::isNumber() {
    return _isNumber;
}

/**
 * Name: print()
 * 
 * Purpose: Debugging our item entries.
 *          Prints the item in key-value pairs of the format
 *              Attribute: Value
 * Parameters: None.
 * Return: None.
 * 
 */
void JSONDataItem::print() {
    std::cout << "\t" << attribute() << ": "; 
    if (isNumber())
        std::cout << "n"<<integerValue() << std::endl;
    else
        std::cout << "s"<<stringValue() << std::endl;
}
