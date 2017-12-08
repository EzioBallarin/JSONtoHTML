/**
 *  File Name: AlbumImages.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-07-2017
 *  Last Modified: Thu 07 Dec 2017 05:05:09 PM PST
 *
 *  Description: Implementation of AlbumImages class
 *
 */

#include "AlbumImages.hpp"

AlbumImages::AlbumImages() {

}

AlbumImages::~AlbumImages() {

}

void AlbumImages::addImage(AlbumImage* image) {
    listOfImages()->push_back(image);
}

AlbumImages* AlbumImages::imagesForAlbum(int albumID) {
    AlbumImages* a = new AlbumImages();
    std::vector<AlbumImage*>::iterator it = listOfImages()->begin();
    int curAlbumID = (*it)->valueForIntegerAttribute("album_id");
    while (it != listOfImages()->end()) {
        if (curAlbumID == albumID)
            a->addImage((*it));
        it++;
        if (it == listOfImages()->end())
            break;
        curAlbumID = (*it)->valueForIntegerAttribute("album_id");
    }
    return a;
}

void AlbumImages::loadImagesFromFile(std::string fileName) {
    std::fstream imageStream;
    imageStream.open(fileName.c_str(), std::fstream::in);
    parseJSONArray(imageStream);
    imageStream.close();
}

void AlbumImages::print() {
    JSONArray::print();
}
