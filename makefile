# ASSUMPTIONS:
# /Library/Frameworks/ contains the SDL frameworks.


CC=g++
CFLAGS=-c
# Path to the SDL frameworks, and framework extension.
FP=/Library/Frameworks/
FE=.framework
FRAMEWORKS=-framework ${FP}SDL2${FE} ${FP}SDL2_mixer${FE} ${FP}SDL2_image${FE}


all: aquest

aquest: main.o
	$(CC) main.o -o aquest

main.o: main.cpp
	$(CC) $(CFLAGS) $(FRAMEWORKS) main.cpp -o main.o

window_management.o: window_management.cpp
	$(CC) $(CFLAGS) $(FRAMEWORKS) window_management.cpp -o window_management.o

clean:
	rm *o aquest
