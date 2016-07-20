# ASSUMPTIONS:
# /Library/Frameworks/ contains the SDL frameworks.


CC=g++
CFLAGS=-c
# Path to the SDL frameworks, and framework extension.
FP=/Library/Frameworks/
FE=.framework
FRAMEWORKS=-framework SDL2 SDL2_mixer SDL2_image
LDLIBS=-L/Frameworks 

all: aquest

aquest: main.o window_management.o
	$(CC) -o aquest main.o window_management.o -F/${FP} ${FRAMEWORKS}

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

window_management.o: window_management.cpp window_management.h
	$(CC) $(CFLAGS) window_management.cpp -o window_management.o

clean:
	rm *.o *.out aquest
