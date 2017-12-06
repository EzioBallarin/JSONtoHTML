/**
 *  File Name: Artists.cpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Tue 05 Dec 2017 09:24:10 PM PST
 *
 *  Description: Implementation of Artists class
 *
 */

#include "Artists.hpp"

Artists::Artists() {

}

void Artists::loadArtistsFromFile(std::string artistsFileName) {
    std::fstream artStream;
    artStream.open(artistsFileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}
