/**
 *  File Name: Albums.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Tue 05 Dec 2017 09:37:25 PM PST
 *
 *  Description:
 *
 */

#include "Albums.hpp"

Albums::Albums() {

}
Albums::~Albums() {

}

JSONDataObject* Albums::jsonObjectNode() {
    return new JSONDataObject();
}
