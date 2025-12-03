#pragma once
#include <SDL_mixer.h>
#include <string>

struct music
{
	Mix_Music* Music;
	void create_sound(std::string file_path);
	void play_music(int i);
	void Free();
};