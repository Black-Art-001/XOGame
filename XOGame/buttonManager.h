#pragma once
#include <SDL.h>
#include <string>

struct ButtonManager 
{
	int frame;
	int frameDuration; 
	SDL_Texture * Texture; 
	SDL_Rect dst; 
	SDL_Rect src;
	SDL_Rect image; 
	SDL_Rect createButton(std::string file_path, int number_of_frame , int FrameDuration);
	int currentFrame = 0;
	int timer = 0;
	void updateButton(SDL_Rect size  , int animation , float DeltaTime  ,  bool isAnimated); 
	
	void renderButton(); 

};