/**
 *  File Name: Artists.cpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Wed 06 Dec 2017 12:01:59 PM PST
 *
 *  Description: Implementation of Artists class
 *
 */

#include "Artists.hpp"

Artists::Artists() {

}

Artists::~Artists() {
    
}

void Artists::loadArtistsFromFile(std::string artistsFileName) {
    std::fstream artStream;
    artStream.open(artistsFileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}
