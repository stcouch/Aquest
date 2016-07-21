#ifndef __aquest__audio__
#define __aquest__audio__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <string>

Mix_Music *load_audio_file(std::string audio_file);
Mix_Music *audio_init();

#endif /* __aquest__audio__ */
