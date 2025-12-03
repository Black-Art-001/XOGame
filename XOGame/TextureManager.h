#pragma once
#include <SDL.h>
#include <string>
struct TextureManager
{
	SDL_Texture* textureManager(std::string); 
};
extern TextureManager texture; 