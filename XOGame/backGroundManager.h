#pragma once
#include <string>
#include <SDL.h>
#include "theme.h"
struct backGround
{
	int frameIndex = 0;
	int Timer = 0;
	SDL_Texture** image; 
	SDL_Rect dstRect; 
	SDL_Rect srcRect; 
	int srcW; 
	int srcH;
	float windowRatio, imageRatio; 
	void backGroundIMG(theme_path themePath);
	void backGroundUpdate( float deltaTime );
	bool backGroundRender();
	void clear(); 
	float deltaTime;
	float FrameDuration; 
	int numberOfFrame; 
};

extern backGround background; 