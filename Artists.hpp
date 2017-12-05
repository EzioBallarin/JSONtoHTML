/**
 *  File Name: Artists.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Sun 03 Dec 2017 09:31:18 PM PST
 *
 *  Description: Definition of the Artists class, a subclass of JSONArray
 *
 */

class Artists: public JSONArray
{
    public:
    Artists();
    ~Artists();

    int numArtists();
    void addArtist(Artist *artist);
    Artist *artistWithID(unsigned int aID);
    void loadArtistsFromFile(std::string fileName);
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Artist();  }
    void setAlbumsForArtists(Albums *albums);
    void setImagesForArtists(ArtistImages *);
    std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.
};
