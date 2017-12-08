/**
 *  File Name: ArtistImages.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 04:24:58 PM PST
 *
 *  Description:
 *
 */

#ifndef ARTIST_IMAGES_H
#define ARTIST_IMAGES_H

#include "JSONArray.hpp"
#include "ArtistImage.hpp"

class ArtistImages: public JSONArray {
    public:
        ArtistImages(); 
        ~ArtistImages(); 
        
        int numImages();
        void loadImagesFromFile(std::string fileName);
        JSONDataObject* jsonObjectNode() { return new ArtistImage(); }
        std::vector<ArtistImage*>* listOfImages() { 
            return (std::vector<ArtistImage*>*) _listOfDataObjects;
        }
        virtual void print();
};

#endif
