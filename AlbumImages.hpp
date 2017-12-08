/**
 *  File Name: AlbumImages.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 04:59:16 PM PST
 *
 *  Description:
 *
 */


#ifndef ALBUM_IMAGES_H
#define ALBUM_IMAGES_H

#include "JSONArray.hpp"
#include "AlbumImage.hpp"

class AlbumImages: public JSONArray {

    public:
        AlbumImages();
        ~AlbumImages();

        int numImages();
        void addImage(AlbumImage* image);
        void loadImagesFromFile(std::string fileName);
        JSONDataObject* jsonObjectNode() { return new AlbumImage(); }
        std::vector<AlbumImage*>* listOfImages() {
            return (std::vector<AlbumImage*>*) _listOfDataObjects;
        }
        AlbumImages* imagesForAlbum(int albumID);
        virtual void print();

};

#endif
