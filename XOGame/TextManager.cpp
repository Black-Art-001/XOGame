#include "TextManager.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Initialize.h"

void Text::textCreator(SDL_Rect dstR , int fillH , int fillW)
{
	dst = dstR; 
	dst.w = dstR.w * fillW /100 ;
	dst.h = dstR.h * fillH / 100; 
	dst.x += (dstR.w - dst.w)/2;
	dst.y += (dstR.h - dst.h) / 2;
}

SDL_Texture* Text::textInit(std::string file_path , std::string massage, int size , SDL_Color COLOR )
{
	font = TTF_OpenFont(file_path.c_str(), size); // like create window 
	color = COLOR; 
	temp = TTF_RenderText_Solid(font, massage.c_str(), color);
	texture = SDL_CreateTextureFromSurface(Initialize::renderer, temp);
	SDL_FreeSurface(temp); 
	return texture; 
}


void Text::textRender()
{

	SDL_RenderCopy(Initialize::renderer, texture, NULL, &dst);
}
