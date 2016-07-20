# ASSUMPTIONS:
# /Library/Frameworks/ contains the SDL frameworks.


CC=g++
CFLAGS=-c
# Path to the SDL frameworks, and framework extension.
FP=/Library/Frameworks/
FE=.framework
FRAMEWORKS=-framework ${FP}SDL2${FE} ${FP}SDL2_mixer${FE} ${FP}SDL2_image${FE}
LDLIBS=-L/Frameworks 

all: aquest

aquest: main.o window_management.o
	$(CC) -o aquest main.o window_management.o -F/${FP} -framework SDL2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

window_management.o: window_management.cpp window_management.h
	$(CC) $(CFLAGS) window_management.cpp -o window_management.o

clean:
	rm *.o *.out aquest
