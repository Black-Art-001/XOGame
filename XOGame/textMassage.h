#pragma once 
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define setRealW 0 
#define setRealH 0 

struct Massage
{
	int height , width;
	SDL_Rect dst; 
	SDL_Texture* texture; 
	SDL_Surface* temp; 
	SDL_Texture* textInit(std::string file_path, std::string massage, int size, SDL_Color color);
	void textCreator(int x, int y, int w, int h , float size);

	void textRender();

	void clear();
};