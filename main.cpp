/**
 *  File Name: main.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 11-12-2017
 *  Last Modified: Thu 07 Dec 2017 01:02:48 AM PST
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
 * Purpose: Read input JSON files for artists, albums, and tracks,
 *          then create the master HTMl file for this project.
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
    a->loadArtistsFromFile("inputJSONfiles/artists.json");
    //a->print();
    cout << "Done parsing artists." << endl;
    /******************************************/


    /* PARSE ALBUMS */
    cout << "Parsing albums..." << endl;
    al->loadAlbumsFromFile("inputJSONfiles/albums.json");
    //al->print();
    cout << "Done parsing albums." << endl;
    /******************************************/

    
    /* PARSE TRACKS */
    cout << "Parsing tracks..." << endl;
    tracksJSON.open("inputJSONfiles/tracks.json");
    t->loadTracksFromFile("inputJSONfiles/tracks.json");

    //t->print();
    cout << "Done parsing tracks." << endl;
    /******************************************/

    /* ADD TRACKS TO ALBUMS */
    cout << "Adding Tracks to Albums..." << endl;
    al->setTracksForAlbums(t);
    //al->print();

    /* ADD ALBUMS TO ARTISTS */
    a->setAlbumsForArtists(al);
    //a->print();

    fstream artistsHTML;
    artistsHTML.open("artists.html", ios::out);
    artistsHTML << a->htmlString();
    artistsHTML.close();

    delete a;
    delete al;
    delete t;
    return 0;
}
