/**
 *  File Name: Album.cpp
 *  Author: Ezio Ballarin 
 *  Student ID: 005633321
 *  Creation Date: 12-04-2017
 *  Last Modified: Thu 07 Dec 2017 04:00:33 PM PST
 *
 *  Description:
 *
 */

#include <sstream>
#include "Album.hpp"
#include "Artist.hpp"

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

std::string Album::htmlString() {
    std::string html = "\t\t<li>\n";
    html += "\t\t\t<p><strong>" + title() + "</strong></p>\n";
    html += "\t\t\t<table class=\"albumInfo\">\n";
    html += "\t\t\t\t<tbody>\n";
    html += "\t\t\t\t\t<tr><td class=\"aTitle\">" + title() + "</td></tr>\n";
    html += "\t\t\t\t\t<tr><td>Artist: " + artist()->artistName() + "</td></tr>\n";
    html += "\t\t\t\t\t<tr><td>Genres: "+ genres() + "</td></tr>\n";
    html += "\t\t\t\t\t<tr><td>Year: "+ year() + "</td></tr>\n";
    html += "\t\t\t\t</tbody>\n";
    html += "\t\t\t</table>\n";
    html += "\t\t</li>\n";
    html += tracks()->htmlString();
    makeHTMLPageForAlbum(html);
    return html;
}

void Album::makeHTMLPageForAlbum(std::string html) {
    std::fstream templateFile, htmlFile; 
    char c;
    std::string templateAttribute;
    int album = albumID();
   
    std::string fileName = "html_albums/" + std::to_string(album) +".html";
    htmlFile.open(fileName, std::fstream::out);
    templateFile.open("HTML_templateFiles/album_template.html", std::fstream::in);

    while (templateFile.good()) {
        c = templateFile.get();
        if (c == '<' && templateFile.peek() == '%') {
            c = templateFile.get();
            std::stringstream* s = new std::stringstream();
            while (c != '<') {
                s->put(c);
                c = templateFile.get();
            }
            if (s->str() == "\% album_name \%>") {
                htmlFile << title();
            } else { 
                htmlFile << html;
            }
            delete s;
        } 
        htmlFile << c;
    }

    htmlFile.close();
    templateFile.close();
}

void Album::print() {
    std::cout << "Album: " << std::endl;
    std::cout << "\tTitle: " << title() << std::endl;
    std::cout << "\tYear: " << year() << std::endl;
    std::cout << "\tGenres: " << genres() << std::endl;
    std::cout << "\tNum_tracks: " << numTracks() << std::endl;
    std::cout << "\tNum_images: " << numImages() << std::endl;
    std::cout << "\tAlbum_id: " << albumID() << std::endl;
    std::cout << "\tArtist_id: " << artistID() << std::endl;
    std::cout << "\tTracks:" << std::endl;
    tracks()->print();
    std::cout << std::endl;
}
