/**
 *  File Name: Albums.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 12:21:48 AM PST
 *
 *  Description: Implementation of Albums container class
 *
 */

#include "Albums.hpp"

Albums::Albums() {

}
Albums::~Albums() {

}

void Albums::addAlbum(Album* album) {
    listOfAlbums()->push_back(album);
}

Albums* Albums::albumsForArtistWithID(int artistID) {
    Albums* a = new Albums();
    std::vector<Album*>::iterator it = listOfAlbums()->begin();
    int curArtistID; 
    while (it != listOfAlbums()->end()) {
        curArtistID = (*it)->valueForIntegerAttribute("artist_id");
        if (curArtistID == artistID)
            a->addAlbum((*it));
        it++;
    }
    return a;
}

void Albums::loadAlbumsFromFile(std::string albumsFileName) {
    std::fstream albStream;
    albStream.open(albumsFileName.c_str(), std::fstream::in);
    parseJSONArray(albStream);
    albStream.close();
}

void Albums::setTracksForAlbums(Tracks* tracks) {
    std::vector<Album*>::iterator it = listOfAlbums()->begin();
    Album* curAlbum; 
    int curAlbumID;
    while (it != listOfAlbums()->end()) {
        curAlbum = (*it);
        curAlbumID = curAlbum->valueForIntegerAttribute("album_id");
        Tracks* curAlbumTracks = tracks->tracksInAlbum(curAlbumID);
        curAlbum->setTracks(curAlbumTracks);
        it++;
    }
}

void Albums::print() {
    JSONArray::print();
}
