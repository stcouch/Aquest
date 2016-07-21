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

// Shut it down
void close_game(){
    // Idea: Create resource manager class so we can know what memory management needs to be done.
    
    
    // Question: Does this deal with all the resources we've created that come from SDL???
    SDL_Quit();
}

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
	// Enter main loop
//	running_window_loop(); 
    
    // Enter into main loop.
//        running_window_loop()
    close_game();
    return 0;
}


void close(SDL_Window *Window){
    
    SDL_DestroyWindow(Window);
}
