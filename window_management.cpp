#include "window_managment.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// This is the very first window that is created.
bool init_window(){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* RunningWindow = NULL;
	bool success = true;
	RunningWindow = SDL_CreateWindow("Game Menu",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				WINDOW_WIDTH,
				WINDOW_HEIGHT,
				// additional properties of windo, joined by OR
				SDL_WINDOW_RESIZABLE || SDL_WINDOW_MINIMIZED);
	if (RunningWindow == NULL){
		printf("Initialization failed. Error: $s\n", SDL_GetError());
		return false;
	}
	return success;
}
