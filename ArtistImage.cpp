/**
 *  File Name: ArtistImage.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-07-2017
 *  Last Modified: Thu 07 Dec 2017 04:34:40 PM PST
 *
 *  Description:
 *
 */

#include "ArtistImage.hpp"

std::string ArtistImage::type() {
    if (cachedType)
        return _type;
    cachedType = true;
    return _type = valueForStringAttribute("type");
}
std::string ArtistImage::uri() {
    if (cachedURI)
        return _uri;
    cachedURI = true;
    return _uri = valueForStringAttribute("uri");
}
unsigned ArtistImage::width() {
    if (cachedWidth)
        return _width;
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}
unsigned ArtistImage::height() {
    if (cachedHeight)
        return _height;
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}
unsigned ArtistImage::artistID() {
    if (cachedArtistID)
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

void ArtistImage::print() {
    std::cout << "AristImage:" << std::endl;
    std::cout << "\tType: " << type() << std::endl;
    std::cout << "\tURI: " << uri() << std::endl;
    std::cout << "\tHeight: " << height() << std::endl;
    std::cout << "\tWidth: " << width() << std::endl;
    std::cout << "\tArtist ID: " << artistID() << std::endl;
    std::cout << std::endl;
}
