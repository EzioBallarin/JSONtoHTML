/**
 *  File Name: Album.hpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Mon 04 Dec 2017 11:21:58 PM PST
 *
 *  Description: Definition of class Album, subclass of JSONDataObject
 *
 */

#ifndef ALBUM_H
#define ALBUM_H

#include "JSONDataObject.hpp"
#include "Tracks.hpp"
#include "Artist.hpp"
#include "AlbumImage.hpp"

class Album: public JSONDataObject {
    public:
        Album();
        ~Album();

        std::string title();
        std::string genres();
        unsigned albumID();
        unsigned artistID();
        unsigned numImages();
        unsigned numTracks();
        std::string year();

        void setTracks(Tracks *tracks);
        void setArtist(Artist *artist);
        Artist *artist();
        Tracks *tracks()  { return _tracks; }

        AlbumImage *&primaryImage() { return _primaryAlbumImage;   }
        AlbumImage *&secondaryImage()  { return _secondaryAlbumImage; }

        void print();
        std::string htmlString();

    private:
        Tracks* _tracks;
        AlbumImage *_primaryAlbumImage = nullptr, 
                   *_secondaryAlbumImage = nullptr;
};
#endif
