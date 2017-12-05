/**
 *  File Name: Track.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Mon 04 Dec 2017 10:56:01 PM PST
 *
 *  Description:Definition of class Track, subclass of JSONDataObject
 *
 */
#ifndef TRACK_H
#define TRACK_H

#include "JSONDataObject.hpp"

class Track: public JSONDataObject {
    public:
        Track();
        ~Track();

        std::string title();
        std::string artist_name();
        std::string album_name();
        unsigned album_id();
        std::string duration();
        unsigned position();

        void print();

    private:

};
#endif
