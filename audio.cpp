#include "audio.h"

Mix_Music *audio_init(void)
{
    Mix_Init( MIX_INIT_MP3 );
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    // first time audio inits, intro is played
	// filler music for now
    Mix_Music *music = load_audio_file("media/music/toccata_fugue.mp3");
    
    return music;
}

Mix_Music *load_audio_file(std::string audio_file)
{
    //Load the music
    Mix_Music *music = Mix_LoadMUS(audio_file.c_str());
    //If everything loaded fine
    return music;
}

void close_music(Mix_Music *music)
{
    //Free the music
    Mix_FreeMusic( music );
    
    Mix_Quit();
}
