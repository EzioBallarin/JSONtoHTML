 #
 #  File Name: Makefile
 #  Author: Ezio Ballarin 
 #  Student ID: 005633321
 #  Creation Date: 11-12-2017
 #  Last Modified: Mon 04 Dec 2017 10:14:04 PM PST
 #
 #  Description: Makefile for project 4.
 #

CFLAGS = -ggdb -Wall -std=c++11

parser.x: clean JSONArray.o JSONDataObject.o JSONDataItem.o Track.o Album.o Artist.o Tracks.o Albums.o Artists.o main.o 
	g++ $(CFLAGS) *.o -o parser.x

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -c -o main.o

Artists.o: Artists.cpp JSON*.o
	g++ $(CFLAGS) Artists.cpp -o Artists.o

Albums.o: Albums.cpp JSON*.o
	g++ $(CFLAGS) Albums.cpp -o Albums.o

Tracks.o: Tracks.cpp JSON*.o
	g++ $(CFLAGS) Tracks.cpp -o Tracks.o

Artist.o: Artist.cpp
	g++ $(CFLAGS) Artist.cpp -o Artist.o

Album.o: Album.cpp
	g++ $(CFLAGS) Album.cpp -o Album.o

Track.o: Track.cpp
	g++ $(CFLAGS) Track.cpp -o Track.o

JSONDataItem.o: JSONDataItem.cpp
	g++ $(CFLAGS) JSONDataItem.cpp -o JSONDataObject.o

JSONDataObject.o: JSONDataObject.cpp
	g++ $(CFLAGS) JSONDataObject.cpp -o JSONDataObject.o

JSONArray.o: JSONArray.cpp
	g++ $(CFLAGS) JSONArray.cpp -o JSONArray.o

clean:
	clear
	rm -f *.o *.x 
