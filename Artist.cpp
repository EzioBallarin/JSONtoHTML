/**
 *  File Name: Artist.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 02:10:54 PM PST
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

std::string Artist::profile() {
    return valueForStringAttribute("profile");
}
std::string Artist::artistName() {
    return valueForStringAttribute("artist_name");
}
std::string Artist::realName() {
    return valueForStringAttribute("real_name");
}
std::string Artist::numImages() {
    return valueForStringAttribute("num_images");
}
unsigned Artist::artistID() {
    return valueForIntegerAttribute("artist_id");
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
