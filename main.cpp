/**
 *  File Name: main.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 11-12-2017
 *  Last Modified: Tue 05 Dec 2017 09:15:36 PM PST
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
    cout << "Parsing artists..." << endl;
    artistsJSON.open("inputJSONfiles/artists.json");

    if (!(artistsJSON >> c) || c != '[') {
        cout << "Improper JSON detected in Artists JSON." << endl;
        return -1;
    }

    int x = 1;
    while (artistsJSON.good()) {
        cout << "Called " << x << endl;
        a->parseJSONArray(artistsJSON);
        x++;
    }
    a->print();
    artistsJSON.close();
    
    return 0;
}
