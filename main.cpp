/************************************************************************************************
 main
 
 Author:  Daniel Couch, ...
 
 Description:
    Main program, calls the main window through which the game is played.
 
 
 
 /******************************************************************************************************/



#include <iostream>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "window_management.h"

#define FAILURE -1

extern SDL_Window *RunningWindow;

int main(int argc, const char * argv[]){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return FAILURE;
	}
	init_window();
    	if (RunningWindow == NULL){
        	printf("Initialization failed. Error: $s\n", SDL_GetError());
        	return FAILURE;
    	}
    
    //  PROBABLY HAVE TO BOOT UP PROGRAM IN THE FUTURE HERE
    // init_program()
    
    
    // Enter into main loop.
//        running_window_loop()
    
		return 0;
}


void close(SDL_Window *Window){
    
    SDL_DestroyWindow(Window);
}
