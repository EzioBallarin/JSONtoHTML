/**
 *  File Name: Track.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 03:25:33 PM PST
 *
 *  Description: Implementation of the Track class
 *
 */

#include "Track.hpp"

Track::Track() {

}

Track::~Track() {

}

/**
 * Name: title()
 * 
 * Purpose: Get the title of the current track.
 * Parameters: None.
 * Return: The title of the current track.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise, 
 *        it returns the cached version of the attribute.
 */
std::string Track::title() {
    if (cachedTitle)
        return _title;
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
}

/**
 * Name: artistName()
 * 
 * Purpose: Get the artist for this track. 
 * Parameters: None.
 * Return: The artist of the current track.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise, 
 *        it returns the cached version of the attribute.
 */
std::string Track::artistName() {
    if (cachedArtistName)
        return _artist_name;
    cachedArtistName = true;
    return _artist_name = valueForStringAttribute("artist_name");
}

/**
 * Name: albumName()
 * 
 * Purpose: Get the album name which this track comes from. 
 * Parameters: None.
 * Return: The album name which this track comes from.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise, 
 *        it returns the cached version of the attribute.
 */
std::string Track::albumName() {
    if (cachedAlbumName)
        return _album_name;
    cachedAlbumName = true;
    return _album_name = valueForStringAttribute("album_name");
}

/**
 * Name: duration()
 * 
 * Purpose: Get the duration of this track. 
 * Parameters: None.
 * Return: The duration of this track. 
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise, 
 *        it returns the cached version of the attribute.
 */
std::string Track::duration() {
    if (cachedDuration)
        return _duration;
    cachedDuration = true;
    return _duration = valueForStringAttribute("duration");
}

/**
 * Name: position()
 * 
 * Purpose: Get the position of this track on its album.
 * Parameters: None.
 * Return: The position of this track on its album 
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise, 
 *        it returns the cached version of the attribute.
 */
std::string Track::position() {
    if (cachedPosition)
        return _position;
    cachedPosition = true;
    return _position = valueForStringAttribute("position");
}

/**
 * Name: albumID()
 * 
 * Purpose: Get the albumID which this track comes from 
 * Parameters: None.
 * Return: The album which this track comes from 
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise, 
 *        it returns the cached version of the attribute.
 */
unsigned Track::albumID() {
    if (cachedAlbumID)
        return _albumID;
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

void Track::print() {
    std::cout << "Track: " << std::endl;
    std::cout << "\tArtist: " << artistName() << std::endl;
    std::cout << "\tTitle: " << title() << std::endl;
    std::cout << "\tAlbum: " << albumName() << std::endl;
    std::cout << "\tDuration: " << duration() << std::endl;
    std::cout << "\tPosition: " << position() << std::endl;
    std::cout << "\tAlbum ID: " << albumID() << std::endl;
    std::cout << std::endl;
}
