/**
 *  File Name: Tracks.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 11:42:48 PM PST
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
        std::vector<Track*>* listOfTracks() { return (std::vector<Track*>*) _listOfDataObjects; }
        // Collection info
        int numTracks();

        // Add track to the collection
        void addTrack(Track* track);
        
        // Get all tracks in an album
        Tracks* tracksInAlbum(int albumID);

        // Parse the JSON array
        void loadTracksFromFile(std::string fileName);

        // HTML representation of collection
        std::string htmlString();
        
        // Print for debugging
        virtual void print();

};
#endif
