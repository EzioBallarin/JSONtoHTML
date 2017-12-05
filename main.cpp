/**
 *  File Name: main.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 11-12-2017
 *  Last Modified: Mon 04 Dec 2017 11:26:18 PM PST
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
    artistsJSON.open("json_p4/artists/artists_small.json");
    while (artistsJSON.good()) {
        artistsJSON >> c;
        cout << c;
    }
    artistsJSON.close();
    
    return 0;
}
