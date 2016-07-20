// Main program.

#include <iostream>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "window_management.h"

int main(int argc, const char * argv[]){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    		printf("SDL_Init failed: %s\n", SDL_GetError());
	}
	SDL_Window *RunningWindow = init_window();	
	if (RunningWindow == NULL){
		printf("ERROR\n");
	}
	return 0;
}
