/********************************************************           
     window_management
 
     Author:  Daniel Couch, ...
 
     Description:
          Various functions involving the window,
    	   textures, and other SDL features.



/******************************************************************************************************/

#include "window_management.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern SDL_Window *RunningWindow = NULL;
SDL_Surface *RunningBackground = NULL;
const char *title_file = "media/environments/title.png";

/* Load background of window. */
bool load_background(void){
    
    return true;
}






/* This is the very first window that is created. */
bool init_window(void){
	bool success = true;
    	SDL_Init(SDL_INIT_VIDEO);
    	RunningWindow = SDL_CreateWindow("Game Menu",
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     WINDOW_WIDTH,
                                     WINDOW_HEIGHT,
                                     // additional properties of windo, joined by OR
                                     SDL_WINDOW_RESIZABLE || SDL_WINDOW_MINIMIZED);
    
    	if (!RunningWindow){
        	success = false;
    	}
    	// Start by displaying the title menu.
    	RunningBackground = SDL_LoadIMG(title_file);
	SDL_UpdateWindowSurface(RunningWindow);
    	return success;
}

//void running_window_loop(){
//}

