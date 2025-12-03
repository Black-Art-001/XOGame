#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

struct Text
{
	TTF_Font* font; // like window ! 
	SDL_Surface* temp; // like calling image from device 
	SDL_Texture* texture; // like creating image !
	SDL_Color color; 
	SDL_Rect dst; 
	void textCreator(SDL_Rect dstR , int fillH , int fillW);
	SDL_Texture * textInit(std::string file_path, std::string massage, int size, SDL_Color COLOR);
	void textRender();
};