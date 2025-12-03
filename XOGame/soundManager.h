#pragma once
#include <string>
#include <SDL_mixer.h>

struct sound
{
	Mix_Chunk* soundTrack;
	void create_sound(std::string file_path);
	void play_sound(int i = 0);
	void Free(); 
};

