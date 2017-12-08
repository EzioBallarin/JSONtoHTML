/**
 *  File Name: Tracks.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 04:59:00 PM PST
 *
 *  Description:
 *
 */

#include "Tracks.hpp"

Tracks::Tracks() {

}

Tracks::~Tracks() {

}

int Tracks::numTracks() {
    return numJSONObjects();
}

void Tracks::addTrack(Track* track) {
    listOfTracks()->push_back(track);
}

Tracks* Tracks::tracksInAlbum(int albumID) {
    Tracks* t = new Tracks();
    std::vector<Track*>::iterator it = listOfTracks()->begin();
    int curAlbumID = (*it)->valueForIntegerAttribute("album_id");
    while (it != listOfTracks()->end()) {
        if (curAlbumID == albumID)
            t->addTrack((*it));
        it++;
        if (it == listOfTracks()->end())
            break;
        curAlbumID = (*it)->valueForIntegerAttribute("album_id");
        
    }
    return t;
}

void Tracks::loadTracksFromFile(std::string tracksFileName) {
    std::fstream trackStream;
    trackStream.open(tracksFileName.c_str(), std::fstream::in);
    parseJSONArray(trackStream);
    trackStream.close();
}

std::string Tracks::htmlString() {
    std::string html = "\t\t<h2>Tracklist</h2>\n";
    html += "\t\t<table class=\"tracks\">\n";
    html += "\t\t\t<tbody>\n";
    std::vector<Track*>::iterator it = listOfTracks()->begin();
    while (it != listOfTracks()->end()) {
        html += (*it)->htmlString();
        it++;
    }   
    html += "\t\t\t</tbody>\n";
    html += "\t\t</table>\n";
    return html;
}

void Tracks::print() {
    JSONArray::print();
}
