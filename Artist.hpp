/**
 *  File Name: Artist.hpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Mon 04 Dec 2017 09:47:08 PM PST
 *
 *  Description: Definition of class Artist, subclass of JSONDataObject
 *
 */

#ifndef ARTIST_H
#define ARTIST_H

#include "Albums.hpp"
#include "ArtistImage.hpp"

class Artist: public JSONDataObject {
    public:
        Artist();
        ~Artist();

        std::string profile();
        std::string artistName();
        std::string realName();
        std::string numImages();  // since it's a string in the JSON file
        unsigned artistID();

        void print();
        std::string htmlString();

        // the following 4 function-prototypes are new to this project.
        void setAlbums(Albums *albums) { _albums = albums; }
        Albums *albums() { return _albums; }
        ArtistImage *&primaryImage() { return _primaryImage; }
        ArtistImage *&secondaryImage() { return _secondaryImage; }

    private:
        std::string _name, _realName, _profile, _numImages;
        unsigned _artistID;
        bool cachedName, cachedRealName,
        cachedProfile, cachedNumImages,
        cachedArtistID;

        // the following 3 variables are new to
        // this project.
        ArtistImage *_primaryImage,
        *_secondaryImage;
        Albums *_albums;

};
#endif
