#include "window_management.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// This is the very first window that is created.
SDL_Window* init_window(void){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* RunningWindow = NULL;
	RunningWindow = SDL_CreateWindow("Game Menu",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				WINDOW_WIDTH,
				WINDOW_HEIGHT,
				// additional properties of windo, joined by OR
				SDL_WINDOW_RESIZABLE || SDL_WINDOW_MINIMIZED);
	return RunningWindow;
}
