.PHONY: all clean install uninstall

CC=g++

all: game

game: game.o module.o
	$(CC) -o game game.o module.o

game.o: game.cpp
	$(CC) -c -o game.o game.cpp

module.o: module.cpp
	$(CC) -c -o module.o module.cpp

clean:
	rm -rf game *.o

install:
	install ./game /usr/local/bin

uninstall:
	-rm -rf /usr/local/bin/game

