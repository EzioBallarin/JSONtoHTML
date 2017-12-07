/**
 *  File Name: Track.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Thu 07 Dec 2017 01:33:35 AM PST
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
        std::string artistName();
        std::string albumName();
        std::string duration();
        std::string position();
        unsigned albumID();
        
        std::string htmlString();
        void print();

    private:
        std::string _title, _artist_name, 
                    _album_name, _duration, _position;
        unsigned _albumID;
        bool cachedTitle = false, cachedArtistName = false, 
             cachedAlbumName = false, cachedDuration = false,
             cachedPosition = false, cachedAlbumID = false;


};
#endif
