 #
 #  File Name: Makefile
 #  Author: Ezio Ballarin 
 #  Student ID: 005633321
 #  Creation Date: 11-12-2017
 #  Last Modified: Thu 07 Dec 2017 04:43:01 PM PST
 #
 #  Description: Makefile for project 4.
 #

CFLAGS = -ggdb -Wall -std=c++11

parser.x: clean JSONArray.o Track.o Album.o Artist.o ArtistImage.o AlbumImage.o Tracks.o Albums.o Artists.o ArtistImages.o AlbumImages.o main.o 
	g++ $(CFLAGS) *.o -o parser.x

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o

AlbumImages.o: AlbumImages.cpp JSONArray.o
	g++ $(CFLAGS) -c AlbumImages.cpp -o AlbumImages.o

ArtistImages.o: ArtistImages.cpp JSONArray.o
	g++ $(CFLAGS) -c ArtistImages.cpp -o ArtistImages.o

Artists.o: Artists.cpp JSONArray.o
	g++ $(CFLAGS) -c Artists.cpp -o Artists.o

Albums.o: Albums.cpp JSONArray.o
	g++ $(CFLAGS) -c Albums.cpp -o Albums.o

Tracks.o: Tracks.cpp JSONArray.o 
	g++ $(CFLAGS) -c Tracks.cpp -o Tracks.o

AlbumImage.o: AlbumImage.cpp
	g++ $(CFLAGS) -c AlbumImage.cpp -o AlbumImage.o

ArtistImage.o: ArtistImage.cpp
	g++ $(CFLAGS) -c ArtistImage.cpp -o ArtistImage.o

Artist.o: Artist.cpp
	g++ $(CFLAGS) -c Artist.cpp -o Artist.o

Album.o: Album.cpp
	g++ $(CFLAGS) -c Album.cpp -o Album.o

Track.o: Track.cpp
	g++ $(CFLAGS) -c Track.cpp -o Track.o

JSONDataItem.o: JSONDataItem.cpp
	g++ $(CFLAGS) -c JSONDataItem.cpp -o JSONDataItem.o

JSONDataObject.o: JSONDataObject.cpp
	g++ $(CFLAGS) -c JSONDataObject.cpp -o JSONDataObject.o

JSONArray.o: JSONDataItem.o JSONDataObject.o JSONArray.cpp 
	g++ $(CFLAGS) -c JSONArray.cpp -o JSONArray.o

clean:
	clear
	rm -f *.o *.x 
