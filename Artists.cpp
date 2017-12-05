/**
 *  File Name: Artists.cpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Mon 04 Dec 2017 05:42:54 PM PST
 *
 *  Description: Implementation of Artists class
 *
 */

#include "Artists.hpp"

void Artists::loadArtistsFromFile(std::string artistsFileName) {
    std::fstream artStream;
    artStream.open(artistsFileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}
