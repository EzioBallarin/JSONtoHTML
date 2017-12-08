/**
 *  File Name: ArtistImages.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-07-2017
 *  Last Modified: Thu 07 Dec 2017 04:20:01 PM PST
 *
 *  Description: Implementation of ArtistImages class
 *
 */

#include "ArtistImages.hpp"

ArtistImages::ArtistImages() {

}

ArtistImages::~ArtistImages() {

}
void ArtistImages::loadImagesFromFile(std::string fileName) {
    std::fstream imageStream;
    imageStream.open(fileName.c_str(), std::fstream::in);
    parseJSONArray(imageStream);
    imageStream.close();
}

void ArtistImages::print() {
    JSONArray::print();
}
