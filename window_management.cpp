/********************************************************           
     window_management
 
     Author:  Daniel Couch, ...
 
     Description:
          Various functions involving the window,
    	   textures, and other SDL features.


    TO DO:
        - Remove globalization 
        -
/******************************************************************************************************/

#include "window_management.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// The window we work with.
extern SDL_Window *RunningWindow = NULL;
// Background to be displayed.
SDL_Surface *RunningBackground = NULL;
// ...
SDL_Surface *CurrentWindowSurface = NULL;
const char *title_file = "media/environments/menu.png";

/* Load background of window. */
SDL_Surface *LoadBackgroundSurface(const char *file_name){
	SDL_Surface *BackgroundSurface = NULL;
	SDL_Surface *LoadedSurface = IMG_Load(file_name);
	if (LoadedSurface == NULL){
		printf("Unable to load image %s! SDL_image Error: %s\n", file_name, IMG_GetError() );
	}
	BackgroundSurface = SDL_ConvertSurface(LoadedSurface, CurrentWindowSurface->format, NULL);
	SDL_FreeSurface(LoadedSurface);
	// our new background surface!
	return BackgroundSurface;
}






/* This is the very first window that is created. */
bool init_window(void){
    bool success = true;
    	int init_success = SDL_Init(SDL_INIT_VIDEO);
    	if (init_success < 0){
	printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    	}
	else{
	printf("INITIALIZATION SUCCESS!\n");
	}
	RunningWindow = SDL_CreateWindow("Game Menu",
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     WINDOW_WIDTH,
                                     WINDOW_HEIGHT,
                                     // additional properties of windo, joined by OR
                                     SDL_WINDOW_SHOWN);
    if (!RunningWindow){
        printf("Window not created: %s\n", SDL_GetError());
        success = false;
        }
	int image_type = IMG_INIT_PNG;
	IMG_Init(IMG_INIT_PNG);
    	CurrentWindowSurface = SDL_GetWindowSurface(RunningWindow);
	// Start by displaying the title menu.
    RunningBackground = IMG_Load(title_file);
	if( RunningBackground == NULL )
    	{
        printf( "Unable to load image %s! SDL_image Error: %s\n", title_file, IMG_GetError() );
    	}
	CurrentWindowSurface = SDL_GetWindowSurface(RunningWindow);
	// The title menu should now be displayed.
    SDL_BlitSurface(RunningBackground, NULL, CurrentWindowSurface, NULL );
	RunningBackground = LoadBackgroundSurface(title_file);
	running_window_loop();	
    return success;
}

// CREATE FUNCTION FOR INPUT!!!




void running_window_loop(){
	bool kill = false;
	while (!kill){
		SDL_BlitSurface(RunningBackground, NULL, CurrentWindowSurface, NULL);
		SDL_UpdateWindowSurface(RunningWindow);
	}
}

