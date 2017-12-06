/**
 *  File Name: Albums.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Tue 05 Dec 2017 09:38:14 PM PST
 *
 *  Description:
 *
 */

#ifndef ALBUMS_H
#define ALBUMS_H

#include "JSONArray.hpp"

class Albums: public JSONArray {

    public:
        Albums();
        ~Albums();
        virtual JSONDataObject* jsonObjectNode();

};

#endif
