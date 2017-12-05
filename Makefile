 #
 #  File Name: Makefile
 #  Author: Ezio Ballarin 
 #  Student ID: 005633321
 #  Creation Date: 11-12-2017
 #  Last Modified: Sat 18 Nov 2017 11:18:06 PM PST
 #
 #  Description: Makefile for project 4.
 #

CFLAGS = -ggdb -Wall -std=c++11

parser.x: clean main.o Album.o Artist.o Track.o
	g++ $(CFLAGS) *.o -o parser.x

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -c -o main.o

Album.o: Album.cpp
	g++ $(CFLAGS) Album.cpp -c -o Album.o

Artist.o: Artist.cpp
	g++ $(CFLAGS) Artist.cpp -c -o Artist.o

Track.o: Track.cpp
	g++ $(CFLAGS) Track.cpp -c -o Track.o

clean:
	clear
	rm -f *.o *.x 
