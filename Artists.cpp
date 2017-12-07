/**
 *  File Name: Artists.cpp
 *  Author: Ali Kooshesh, Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Thu 07 Dec 2017 01:30:02 AM PST
 *
 *  Description: Implementation of Artists class
 *
 */

#include "Artists.hpp"

Artists::Artists() {

}

Artists::~Artists() {
    
}

/**
 * Name: numArtists()
 * 
 * Purpose: Get the number of Artist objects in this Artists collection.
 * Parameters: None.
 * Return: The number of Artist objects in the JSONArray
 * 
 */
int Artists::numArtists() {
    return numJSONObjects();
}

/**
 * Name: addArtist()
 * 
 * Purpose: Add an artist to this collection of Artists
 * Parameters: Artist* artist - pointer to the Artist object to add
 * Return: None.
 * 
 */
void Artists::addArtist(Artist *artist) {
    listOfArtists()->push_back(artist);
}

/**
 * Name: artistWithID()
 * 
 * Purpose: Return the Artist object of an artist with a given artist_id
 * Parameters: unsigned int aID - the artist_id to search for
 * Return: A pointer to the correct Artist object, or nullptr if no match.
 * 
 */
Artist* Artists::artistWithID(int aID) {

    // Iterate over the entire collection, stop when a matching
    // Artist with artist_id equal to aID is found, 
    // or if the end of the collection is reach.
    std::vector<Artist*>::iterator it = listOfArtists()->begin();
    int cur_id = (*it)->valueForIntegerAttribute("artist_id");
    while (cur_id != aID && it != listOfArtists()->end()) { 
        it++;
        if (it == listOfArtists()->end())
            break;
        cur_id = (*it)->valueForIntegerAttribute("artist_id");
    }

    // If the iterator has reached the end of the list,
    // and the last ID found was not equal to the parameter,
    // return nullptr
    if (it == listOfArtists()->end() && cur_id != aID)
        return nullptr;

    // Else dereference the iterator, which returns a pointer
    // to the Artist object which has artist_id equal to aID
    return (*it);
}

/**
 * Name: loadArtistsFromFile()
 * 
 * Purpose: Load a new Artists collection with Artist objects
 *          parsed from a JSON Array file.
 * Parameters: std::string artistsFileName - the file name of the
 *             JSONArray json file.
 * Return: None.
 * 
 */
void Artists::loadArtistsFromFile(std::string artistsFileName) {
    std::fstream artStream;
    artStream.open(artistsFileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}
/**
 * Name: htmlString()
 * 
 * Purpose: Produce a formatted HTML string which represents
 *          each Artist in this collection.
 * Parameters: None.
 * Return: A formatted HTML list.
 * 
 */
std::string Artists::htmlString() {
    std::string html = "";
    std::vector<Artist*>::iterator it = listOfArtists()->begin();
    while (it != listOfArtists()->end()) {
        html += (*it)->htmlString();
        it++;
    }
    return html;
}

/**
 * Name: setAlbumsForArtists()
 * 
 * Purpose: Assign the proper Album objects form an Albums collection
 *          to the corresponding Artist within this Artists collection.
 * Parameters: Albums* albums - the full list of albums to assign
 * Return: None.
 * 
 */
void Artists::setAlbumsForArtists(Albums* albums) {
    std::vector<Artist*>::iterator it = listOfArtists()->begin();
    Artist* curArtist;
    int curArtistID;
    while (it != listOfArtists()->end()) {
        curArtist = (*it);
        curArtistID = curArtist->valueForIntegerAttribute("artist_id");
        Albums* curArtistAlbums = albums->albumsForArtistWithID(curArtistID);
        curArtist->setAlbums(curArtistAlbums);
        it++;
    }
}

void Artists::print() {
    std::cout << "ARTIST PRINTING" << std::endl;
    std::cout << "Num artists: " << numArtists() << std::endl;
    JSONArray::print();
}
