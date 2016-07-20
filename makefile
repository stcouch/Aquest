# Author: Daniel Couch, ...
# I'm sure this is crappy, since I'm bad at writing makefiles.
# Could surely be written better.

# ASSUMPTIONS:
# /Library/Frameworks/ contains the SDL frameworks.


CC=g++
CFLAGS=-c
# Path to the SDL frameworks, and framework extension.
FP=/Library/Frameworks/
FE=.framework
FRAMEWORKS=-framework SDL2 -framework SDL2_image 
LDLIBS=-L/Frameworks

all: aquest

aquest: main.o window_management.o
	$(CC) main.o window_management.o -F${FP} -framework SDL2 -F${FP} -framework SDL2_image -o aquest

window_management.o: window_management.cpp
	$(CC) $(CFLAGS) window_management.cpp -o window_management.o

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm *.o *.out aquest
