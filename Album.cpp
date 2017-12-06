/**
 *  File Name: Album.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 02:59:04 PM PST
 *
 *  Description:
 *
 */

#include "Album.hpp"

Album::Album() {

}

Album::~Album() {

}

/**
 * Name: title()
 * 
 * Purpose: Get the title of the current album
 * Parameters: None.
 * Return: The album's title.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
std::string Album::title() {
    if (cachedTitle)
        return _title;
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
}

/**
 * Name: genres()
 * 
 * Purpose: Get the genres of the current album
 * Parameters: None.
 * Return: The album's genres.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
std::string Album::genres() {
    if (cachedGenres)
        return _genres;
    cachedGenres = true;
    return _genres = valueForStringAttribute("genres");
}

/**
 * Name: year()
 * 
 * Purpose: Get the year of release for the current album
 * Parameters: None.
 * Return: The album's year of release.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
std::string Album::year() {
    if (cachedYear)
        return _year;
    cachedYear = true;
    return _year = valueForStringAttribute("year");
}


/**
 * Name: albumID()
 * 
 * Purpose: Get the albumID of the current album
 * Parameters: None.
 * Return: The album's ID 
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
unsigned Album::albumID() {
    if (cachedAlbumID)
        return _album_id;
    cachedAlbumID = true;
    return _album_id = valueForIntegerAttribute("album_id");
}

/**
 * Name: artistID()
 * 
 * Purpose: Get the artistID of the current album
 * Parameters: None.
 * Return: The album's artist's ID
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
unsigned Album::artistID() {
    if (cachedArtistID)
        return _artist_id;
    cachedArtistID = true;
    return _artist_id = valueForIntegerAttribute("artist_id");
}

/**
 * Name: numImages()
 * 
 * Purpose: Get the number of images associated with the current album
 * Parameters: None.
 * Return: The number of images associated with this album.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
unsigned Album::numImages() {
    if (cachedNumImages)
        return _num_images;
    cachedNumImages = true;
    return _num_images = valueForIntegerAttribute("num_images");
}

/**
 * Name: numTracks()
 * 
 * Purpose: Get the number of tracks on the current album
 * Parameters: None.
 * Return: The number of tracks on this album.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
unsigned Album::numTracks() {
    if (cachedNumTracks)
        return _num_tracks;
    cachedNumTracks = true;
    return _num_tracks = valueForIntegerAttribute("num_tracks");
}
void Album::print() {
    JSONDataObject::print();
}
