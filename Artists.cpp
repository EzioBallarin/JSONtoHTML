/**
 *  File Name: Artists.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Sun 03 Dec 2017 09:32:14 PM PST
 *
 *  Description: Implementation of Artists class
 *
 */

void Artists::loadArtistsFromFile(std::string artistsFileName)
{
    std::fstream artStream;
    artStream.open(artistsFileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}
