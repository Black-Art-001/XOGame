#include "soundManager.h"
#include <SDL_mixer.h>
#include <string>


void sound::create_sound(std::string file_path)
{
	if (soundTrack != nullptr)
	{
		//Mix_FreeChunk(soundTrack);
	}
	soundTrack = Mix_LoadWAV(file_path.c_str());
}

void sound::play_sound(int i)
{
	Mix_PlayChannel(-1, soundTrack, i - 1);
}

void sound::Free()
{
	Mix_FreeChunk(soundTrack);
}