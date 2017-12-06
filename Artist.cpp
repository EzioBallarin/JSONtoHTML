/**
 *  File Name: Artist.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 02:38:54 PM PST
 *
 *  Description:
 *
 */

#include <string>
#include "Artist.hpp"

Artist::Artist() {

}

Artist::~Artist() {

}

/**
 * Name: profile() 
 * 
 * Purpose: Get the profile of the current artist.
 * Parameters: None.
 * Return: The artist's profile.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
std::string Artist::profile() {
    if (cachedProfile)
        return _profile;
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");
}

/**
 * Name: artistName() 
 * 
 * Purpose: Get the artist name of the current artist.
 * Parameters: None.
 * Return: The artist's name.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
std::string Artist::artistName() {
    if (cachedName)
        return _name;
    cachedName = true;
    return _name = valueForStringAttribute("artist_name");
}

/**
 * Name: realName() 
 * 
 * Purpose: Get the artist's real name of the current artist.
 * Parameters: None.
 * Return: The artist's real name.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
std::string Artist::realName() {
    if (cachedRealName)
        return _realName;
    cachedRealName = true;
    return _realName = valueForStringAttribute("real_name");
}

/**
 * Name: numImages() 
 * 
 * Purpose: Get the number of images associated with the current artist. 
 * Parameters: None.
 * Return: The number of images associated with the current artist.
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
std::string Artist::numImages() {
    if (cachedNumImages)
        return _numImages;
    cachedNumImages = true;
    return _numImages = valueForStringAttribute("num_images");
}

/**
 * Name: artistID()
 * 
 * Purpose: Get the current artist's artist ID 
 * Parameters: None.
 * Return: The current artist's ID 
 * 
 * Notes: Only searches the JSONDataItem vector if the value
 *        has never been sought after before. Otherwise,
 *        it returns the cached version of the attribute.
 */
unsigned Artist::artistID() {
    if (cachedArtistID)
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

/**
 * Name: htmlString()
 * 
 * Purpose: Produce a formatted HTML string representing this Artist.
 * Parameters: None.
 * Return: A formatted HTML list item.
 * 
 */
std::string Artist::htmlString() {
    std::string html = "";
    return html;
}

void Artist::print() {
    std::cout << "Artist: " << std::endl;
    std::cout << "\tName: " << artistName() << std::endl;
    std::cout << "\tRealName: " << realName() << std::endl;
    std::cout << "\tProfile: " << profile() << std::endl;
    std::cout << "\tArtist ID: " << artistID() << std::endl;
    std::cout << "\tNumber of Images: " << numImages() << std::endl;
    std::cout << std::endl;
}
