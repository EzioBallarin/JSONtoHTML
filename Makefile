 #
 #  File Name: Makefile
 #  Author: Ezio Ballarin 
 #  Student ID: 005633321
 #  Creation Date: 11-12-2017
 #  Last Modified: Mon 04 Dec 2017 06:06:18 PM PST
 #
 #  Description: Makefile for project 4.
 #

CFLAGS = -ggdb -Wall -std=c++11

parser.x: clean main.o Album.o Artist.o Track.o
	g++ $(CFLAGS) *.o -o parser.x

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -c -o main.o

Artists.o: Artists.cpp, JSON*.o
	g++ $(CFLAGS) Artists.cpp -o Artists.o

JSONDataItem.o: JSONDataItem.cpp
	g++ $(CFLAGS) JSONDataItem.cpp -o JSONDataObject.o

JSONDataObject.o: JSONDataObject.cpp
	g++ $(CFLAGS) JSONDataObject.cpp -o JSONDataObject.o

JSONArray.o: JSONArray.cpp
	g++ $(CFLAGS) JSONArray.cpp -o JSONArray.o

clean:
	clear
	rm -f *.o *.x 
