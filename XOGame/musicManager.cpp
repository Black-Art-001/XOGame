#include "musicManager.h"
#include <iostream>

void music::create_sound(std::string file_path)
{
	Music = Mix_LoadMUS(file_path.c_str()); 
	if (Music)
	{
		std::cout << "music was loaded : " << file_path << std::endl; 
	}
	else
	{
		std::cout << "No music loaded ! \n";
	}
}

void music::play_music(int i)
{
	Mix_PlayMusic(Music, i - 1); 
}

void music::Free()
{
	Mix_FreeMusic(Music); 
}
