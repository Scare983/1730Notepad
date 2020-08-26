CC = g++
DEBUG = -g -O0 -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEUBUG)
LFLAGS = -Wall $(DEBUG)

all: 1730ed

1730ed: 1730ed.o Editor.o Menuscreen.o GUI.o
	$(CC) $(LFLAGS) -lncurses -o 1730ed 1730ed.o Editor.o Menuscreen.o GUI.o

1730ed.o: 1730ed.cpp 
	$(CC) $(CFLAGS) -lncurses 1730ed.cpp

Editor.o: Editor.cpp 
	$(CC) $(CFLAGS) -lncurses Editor.cpp

Menuscreen.o: Menuscreen.cpp
	$(CC) $(CFLAGS) -lncurses Menuscreen.cpp

GUI.o: GUI.cpp
	$(CC) $(CFLAGS) -lncurses GUI.cpp

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf 1730ed;
