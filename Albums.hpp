/**
 *  File Name: Albums.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 02:24:50 PM PST
 *
 *  Description: Definition of Albums container class
 *
 */

#ifndef ALBUMS_H
#define ALBUMS_H

#include "JSONArray.hpp"
#include "Album.hpp"

class Albums: public JSONArray {

    public:
        Albums();
        ~Albums();
        JSONDataObject* jsonObjectNode() { return new Album(); }

};

#endif
