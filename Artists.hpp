/**
 *  File Name: Artists.hpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Wed 06 Dec 2017 02:11:30 PM PST
 *
 *  Description: Definition of the Artists class, a subclass of JSONArray
 *
 */

#ifndef ARTISTS_H
#define ARTISTS_H

#include "JSONArray.hpp"
#include "Artist.hpp"
#include "ArtistImages.hpp"

class Artist;
class ArtistImages;

class Artists: public JSONArray {
    public:
        Artists();
        ~Artists();

        int numArtists();
        void addArtist(Artist *artist);
        Artist *artistWithID(int aID);
        void loadArtistsFromFile(std::string fileName);
        std::string htmlString();
        JSONDataObject *jsonObjectNode() { return new Artist();  }
        void setAlbumsForArtists(Albums *albums);
        void setImagesForArtists(ArtistImages *);
        std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }
        void runAsserts();  // used for checking the integrity of this class.
        virtual void print();
};
#endif
