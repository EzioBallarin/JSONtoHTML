 #
 #  File Name: Makefile
 #  Author: Ezio Ballarin 
 #  Student ID: 005633321
 #  Creation Date: 11-12-2017
 #  Last Modified: Tue 05 Dec 2017 02:37:12 PM PST
 #
 #  Description: Makefile for project 4.
 #

CFLAGS = -ggdb -Wall -std=c++11

parser.x: clean JSONArray.o Track.o Album.o Artist.o Tracks.o Albums.o Artists.o main.o 
	g++ $(CFLAGS) *.o -o parser.x

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o

Artists.o: Artists.cpp JSONArray.o
	g++ $(CFLAGS) -c Artists.cpp -o Artists.o

Albums.o: Albums.cpp JSONArray.o
	g++ $(CFLAGS) -c Albums.cpp -o Albums.o

Tracks.o: Tracks.cpp JSONArray.o 
	g++ $(CFLAGS) -c Tracks.cpp -o Tracks.o

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
