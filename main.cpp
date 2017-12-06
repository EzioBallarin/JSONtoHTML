/**
 *  File Name: main.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 11-12-2017
 *  Last Modified: Tue 05 Dec 2017 11:34:51 PM PST
 *
 *  Description: Main driver for parsing our JSON files
 *
 */

#include <fstream> 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "JSONDataItem.hpp"
#include "JSONDataObject.hpp"
#include "JSONArray.hpp"
#include "Artist.hpp"
#include "Artists.hpp"
#include "Album.hpp"
#include "Albums.hpp"
#include "ArtistImage.hpp"
#include "ArtistImages.hpp"
#include "AlbumImage.hpp"
#include "AlbumImages.hpp"
#include "Track.hpp"
#include "Tracks.hpp"

using namespace std;

/**
 * Name: main()
 * 
 * Purpose: Read input files, and begin the JSON parsing.
 * Parameters: None.
 * Return: -1 if an error occurred, 0 otherwise.
 * 
 */
int main() {

    char c;
    fstream artistsJSON, albumsJSON, tracksJSON;
    Artists* a = new Artists();
    Albums* al = new Albums();
    Tracks* t = new Tracks();

    /* PARSE ARTISTS */
    cout << "Parsing artists..." << endl;
    artistsJSON.open("inputJSONfiles/artists.json");

    if (!(artistsJSON >> c) || c != '[') {
        cout << "Improper JSON detected in Artists JSON." << endl;
        return -1;
    }

    while (artistsJSON.good()) {
        a->parseJSONArray(artistsJSON);
    }
    artistsJSON.close();
    cout << "Done parsing artists." << endl;
    /******************************************/


    /* PARSE ALBUMS */
    cout << "Parsing albums..." << endl;
    albumsJSON.open("inputJSONfiles/albums.json");

    if (!(albumsJSON >> c) || c != '[') {
        cout << "Improper JSON detected in Artists JSON." << endl;
        return -1;
    }

    while (albumsJSON.good()) {
        al->parseJSONArray(albumsJSON);
    }
    albumsJSON.close();
    cout << "Done parsing albums." << endl;
    /******************************************/


    /* PARSE TRACKS */
    cout << "Parsing tracks..." << endl;
    tracksJSON.open("inputJSONfiles/tracks.json");

    if (!(tracksJSON >> c) || c != '[') {
        cout << "Improper JSON detected in Artists JSON." << endl;
        return -1;
    }

    while (tracksJSON.good()) {
        t->parseJSONArray(tracksJSON);
    }
    tracksJSON.close();
    cout << "Done parsing tracks." << endl;
    /******************************************/

    delete a;
    delete al;
    delete t;
    return 0;
}
