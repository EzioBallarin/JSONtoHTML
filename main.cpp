/**
 *  File Name: main.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 11-12-2017
 *  Last Modified: Thu 07 Dec 2017 05:04:54 PM PST
 *
 *  Description: Main driver for parsing our JSON files
 *
 */

#include <fstream> 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Artists.hpp"
#include "Albums.hpp"
#include "Tracks.hpp"
#include "ArtistImages.hpp"
#include "AlbumImages.hpp"

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

    Artists* a = new Artists();
    Albums* al = new Albums();
    Tracks* t = new Tracks();
    ArtistImages* ai = new ArtistImages();
    AlbumImages* ali = new AlbumImages();

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
    t->loadTracksFromFile("inputJSONfiles/tracks.json");
    //t->print();
    cout << "Done parsing tracks." << endl;
    /******************************************/

    cout << "Parsing artist images.." << endl;
    ai->loadImagesFromFile("inputJSONfiles/artistImages.json");
    //ai->print();
    cout << "Done parsing artist images." << endl;

    cout << "Parsing album images.." << endl;
    ali->loadImagesFromFile("inputJSONfiles/albumImages.json");
    ali->print();
    cout << "Done parsing album images." << endl;

    /* ADD TRACKS TO ALBUMS */
    cout << "Adding tracks to albums..." << endl;
    al->setTracksForAlbums(t);
    //al->print();
    
    /* ADD IMAGES TO ALBUMS */
    cout << "Adding images to albums..." << endl;
    al->setImagesForAlbums(ali);

    al->print();

    /* ADD ALBUMS TO ARTISTS */
    a->setAlbumsForArtists(al);
    //a->print();
    
    

    fstream artistsHTML;
    artistsHTML.open("artists.html", ios::out);
    artistsHTML << "<html>\n<body>\n";
    artistsHTML << a->htmlString();
    artistsHTML << "</body>\n</html>\n";
    artistsHTML.close();

    delete a;
    delete al;
    delete t;
    return 0;
}
