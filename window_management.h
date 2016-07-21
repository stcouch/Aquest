#ifndef __aquest__window_functions__
#define __aquest__window_functions__


#include <iostream>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "audio.h"

/* FUNCTION DECLARATIONS */
bool init_window(void);
bool load_background(void);
int menu_input(int menu_type);
int running_window_loop(void);
int select_current_option(int menu_type, int current_option);


#endif
