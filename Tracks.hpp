/**
 *  File Name: Tracks.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 03:10:21 PM PST
 *
 *  Description:
 *
 */

#ifndef TRACKS_H
#define TRACKS_H

#include "JSONArray.hpp"
#include "Track.hpp"

class Tracks: public JSONArray {
    public:
        Tracks();
        ~Tracks();
        JSONDataObject* jsonObjectNode() { return new Track(); }
};
#endif
