/**
 *  File Name: Tracks.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Tue 05 Dec 2017 09:38:39 PM PST
 *
 *  Description:
 *
 */

#ifndef TRACKS_H
#define TRACKS_H

#include "JSONArray.hpp"

class Tracks: public JSONArray {
    public:
        Tracks();
        ~Tracks();
        virtual JSONDataObject* jsonObjectNode();
};
#endif
