/**
 *  File Name: Albums.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Wed 06 Dec 2017 04:18:01 PM PST
 *
 *  Description: Definition of Albums container class
 *
 */

#ifndef ALBUMS_H
#define ALBUMS_H

#include "JSONArray.hpp"
#include "Album.hpp"

class Albums: public JSONArray {

    public:
        Albums();
        ~Albums();
        JSONDataObject* jsonObjectNode() { return new Album(); }
        std::vector<Album*>* listOfAlbums() { return (std::vector<Album*>*) _listOfDataObjects; }

        // Collection info
        int numAlbums();

        // Element access
        Album* albumWithID(int aID);
    
        // Collection Modification
        void addAlbum(Album* album);
        
        // Parse the JSON array
        void loadAlbumsFromFile(std::string fileName);

        // HTML representation of collection
        std::string htmlString();

        // Print for debugging
        virtual void print();


};

#endif
