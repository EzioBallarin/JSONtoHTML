/**
 *  File Name: Track.hpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-03-2017
 *  Last Modified: Sun 03 Dec 2017 09:12:51 PM PST
 *
 *  Description:Definition of class Track, subclass of JSONDataObject
 *
 */
class Track: public JSONDataObject {
    public:
        Track();
        ~Track();

        std::string title();
        std::string artist_name();
        std::string album_name();
        unsigned album_id();
        std::string duration();
        unsigned position();

    private:

};
