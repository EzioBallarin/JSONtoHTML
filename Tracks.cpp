/**
 *  File Name: Tracks.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 04:26:38 PM PST
 *
 *  Description:
 *
 */

#include "Tracks.hpp"

Tracks::Tracks() {

}

Tracks::~Tracks() {

}

void Tracks::loadTracksFromFile(std::string tracksFileName) {
    std::fstream trackStream;
    trackStream.open(tracksFileName.c_str(), std::fstream::in);
    parseJSONArray(trackStream);
    trackStream.close();
}

void Tracks::print() {
    JSONArray::print();
}
