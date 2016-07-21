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
#define MAIN_MENU 3
#define GAME_MENU 5
#define EXIT_CODE -1
#define GOOD_END 0
#define DEBUG TRUE

/* Keyboard presses*/
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};


// The window we work with. Probably don't want this to be global.
extern SDL_Window *RunningWindow = NULL;
// Background to be displayed.
SDL_Surface *RunningBackground = NULL;
// ...
SDL_Surface *CurrentWindowSurface = NULL;
const char *title_file = "media/environments/menu.png";
// Images of key presses.
SDL_Surface *KeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];




/* Load background of window. */
SDL_Surface *LoadBackgroundSurface(const char *file_name)
{
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
bool init_window(void)
{
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


/*************************************************************************************************
Menus
 - Possibly put this in different source file.
 - Create menu class.
*************************************************************************************/




// menu_type:  integer equal to the number of options - 1 for offset.
// probably replace menu_type with a menu class as we get further in the program.
int menu_input(int menu_type){
    printf("HERE\n");
    int current_option = 0;
    SDL_Event event;
    bool kill;
    // use modulo {menu_type} to deal with boundaries.
    while (!kill) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_DOWN:
                            current_option = (current_option + 1) % menu_type;
                            break;
                        case SDLK_UP:
                            // {menu_type - 1} congruent to -1 {mod menu_type} so we're subtracting here.
                            current_option = (current_option + (menu_type - 1)) % menu_type;
                            break;
                        case SDLK_SPACE:
                            // Need to implement this program.
                            int result;
                            result = select_current_option(MAIN_MENU, current_option);
                            return result;
                            break;
                        default:
                            // nothing.
                            break;
                    }
                default:
                break;
            }
        }
        SDL_BlitSurface(RunningBackground, NULL, CurrentWindowSurface, NULL);
        SDL_UpdateWindowSurface(RunningWindow);
    }
}


// This is to be included in a menu class. Just testing it now.
int select_current_option(int menu_type, int current_option){
    // This will, of course, have to be generalized based on type of menu.
    switch (current_option) {
        case 0:
            // we'll say 0 => play game for now.
            printf("You selected to play the game.\n");
            break;
        case 1:
            break;
        case 2:
            printf("You have selected to exit the game.\n");
            return EXIT_CODE;
            break;
        default:
            break;
    }
}


/* Game main menu. With three choices:
    1. New game
    2. Load game
    3. Exit game
 */
//void main_menu(){
//    int current_option;
//    SDL_Event event;
//    while(SDL_PollEvent(&event))
//    {
//        switch (event.type) {
//            case SDL_KEYDOWN:
//                switch (event.key.keysym.sym) {
//                    case SDLK_DOWN:
//                        current_option++;
//                        break;
//                        
//                    default:
//                        break;
//                }
//                break;
//                
//            default:
//                break;
//        }
//    }
//}

// CREATE FUNCTION FOR INPUT!!!


// Menu - pause game, wait for button to be pressed.
//void menu_event()
//{
//    // 1. Pause game.
//    // 2. Load menu screen.
//    // 3. Wait on user input.
//    // 4. Respond to user input.
//    // 5. Repeat 3->5 until user pushes resume putton. (or exiting button)
//    
//}

/* User input, render, etc. */
//void update_game(int status){
//}


/*************************************************************************************************
 Main running window of program
 - Find best way to structure this.
 - 
 *************************************************************************************/


int running_window_loop(void)
{
    int main_menu_result = menu_input(MAIN_MENU);
    if (main_menu_result == -1) {
        return GOOD_END;
    }
	bool kill = false;
	SDL_Event e;
	CurrentWindowSurface = KeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
	Mix_Music *music = audio_init();
    	Mix_PlayMusic(music, -1);
    	Mix_VolumeMusic(128);
	while (!kill)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				kill = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_UP:
                        CurrentWindowSurface = KeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                        break;
					default:
                        CurrentWindowSurface = KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                        break;
				}
			}
		}
        SDL_BlitSurface(RunningBackground, NULL, CurrentWindowSurface, NULL);
        SDL_UpdateWindowSurface(RunningWindow);
	}
    return GOOD_END;
}

