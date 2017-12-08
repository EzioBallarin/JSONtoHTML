/**
 *  File Name: AlbumImage.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-07-2017
 *  Last Modified: Thu 07 Dec 2017 04:47:05 PM PST
 *
 *  Description: Implementation of AlbumImage class
 *
 */

#include "AlbumImage.hpp"

AlbumImage::AlbumImage() {

}

AlbumImage::~AlbumImage() {

}

std::string AlbumImage::type() {
    if (cachedType)
        return _type;
    cachedType = true;
    return _type = valueForStringAttribute("type");
}
std::string AlbumImage::uri() {
    if (cachedURI)
        return _uri;
    cachedURI = true;
    return _uri = valueForStringAttribute("uri");
}
unsigned AlbumImage::width() {
    if (cachedWidth)
        return _width;
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}
unsigned AlbumImage::height() {
    if (cachedHeight)
        return _height;
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}
unsigned AlbumImage::albumID() {
    if (cachedArtistID)
        return _albumID;
    cachedArtistID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

void AlbumImage::print() {
    std::cout << "AlbumImage:" << std::endl;
    std::cout << "\tType: " << type() << std::endl;
    std::cout << "\tURI: " << uri() << std::endl;
    std::cout << "\tHeight: " << height() << std::endl;
    std::cout << "\tWidth: " << width() << std::endl;
    std::cout << "\tArtist ID: " << albumID() << std::endl;
    std::cout << std::endl;
}
