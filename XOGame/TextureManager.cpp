#include <SDL.h>
#include <string>
#include <SDL_image.h>

#include "TextureManager.h"
#include "Initialize.h"

TextureManager texture;

SDL_Texture* TextureManager::textureManager(std::string file_path)
{
	SDL_Surface* temp = IMG_Load(file_path.c_str()); 
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Initialize::renderer, temp);
	SDL_FreeSurface(temp); 
	return tex;
}