/**
 *  File Name: Albums.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 04:49:04 PM PST
 *
 *  Description: Implementation of Albums container class
 *
 */

#include "Albums.hpp"

Albums::Albums() {

}
Albums::~Albums() {

}

void Albums::loadAlbumsFromFile(std::string albumsFileName) {
    std::fstream albStream;
    albStream.open(albumsFileName.c_str(), std::fstream::in);
    parseJSONArray(albStream);
    albStream.close();
}

void Albums::print() {
    JSONArray::print();
}
