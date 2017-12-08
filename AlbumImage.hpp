/**
 *  File Name: AlbumImage.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 04:48:49 PM PST
 *
 *  Description:
 *
 */

#ifndef ALBUM_IMAGE_H
#define ALBUM_IMAGE_H

#include "JSONDataObject.hpp"

class AlbumImage: public JSONDataObject {
    public:
        AlbumImage();
        ~AlbumImage();

        std::string type();
        std::string uri();
        unsigned width();
        unsigned height();
        unsigned albumID();

        void print();
        std::string htmlString();
    private:
        std::string _type = "", _uri = "";
        unsigned _width = -1, _height = -1, _albumID = -1;
        bool cachedType = false, cachedURI = false,
             cachedWidth = false, cachedHeight = false,
             cachedArtistID = false;
};

#endif
