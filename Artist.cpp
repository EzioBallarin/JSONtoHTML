/**
 *  File Name: Artist.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Tue 05 Dec 2017 09:32:51 PM PST
 *
 *  Description:
 *
 */

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
    return valueForIntegerAttribute("artist_id:");
}

void Artist::print() {
    std::cout << "Name: " << artistName() << std::endl;
    std::cout << "RealName: " << realName() << std::endl;
    std::cout << "Profile: " << profile() << std::endl;
    std::cout << "Artist ID: " << artistID() << std::endl;
    std::cout << "Number of Images: " << numImages() << std::endl;
    std::cout << std::endl;
}
