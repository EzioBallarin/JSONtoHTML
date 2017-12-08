/**
 *  File Name: ArtistImage.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 04:44:37 PM PST
 *
 *  Description:
 *
 */

#ifndef ARTIST_IMAGE_H
#define ARTIST_IMAGE_H

#include "JSONDataObject.hpp"

class ArtistImage: public JSONDataObject {
    public:
        ArtistImage() { }
        ~ArtistImage() { }

        std::string type();
        std::string uri();
        unsigned width();
        unsigned height();
        unsigned artistID();

        void print();
        std::string htmlString();
    private:
        std::string _type = "", _uri = "";
        unsigned _width = -1, _height = -1, _artistID = -1;
        bool cachedType = false, cachedURI = false,
             cachedWidth = false, cachedHeight = false,
             cachedArtistID = false;

};

#endif
