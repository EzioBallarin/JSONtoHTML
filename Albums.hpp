/**
 *  File Name: Albums.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 04:52:16 PM PST
 *
 *  Description: Definition of Albums container class
 *
 */

#ifndef ALBUMS_H
#define ALBUMS_H

#include "JSONArray.hpp"
#include "Album.hpp"

class Artist;
class AlbumImages;

class Albums: public JSONArray {

    public:
        Albums();
        ~Albums();
        JSONDataObject* jsonObjectNode() { return new Album(); }
        std::vector<Album*>* listOfAlbums() { return (std::vector<Album*>*) _listOfDataObjects; }

        // Collection info
        int numAlbums();

        // Find all albums that belong to an artist 
        Albums* albumsForArtistWithID(int artistID); 
    
        // Collection Modification
        void addAlbum(Album* album);
        
        // Parse the JSON array
        void loadAlbumsFromFile(std::string fileName);

        // HTML representation of collection
        std::string htmlString();

        // Functions for associating tracks, artists,
        // and images with the proper albums
        void setTracksForAlbums(Tracks* tracks);
        void setArtistForAlbums(Artist* artist);
        void setImagesForAlbums(AlbumImages* images);
        bool isArtistSet() { return _isArtistSet; }

        // Print for debugging
        virtual void print();

    private:
        bool _isArtistSet = false;


};

#endif
