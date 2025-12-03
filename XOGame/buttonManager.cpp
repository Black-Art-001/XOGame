#include "buttonManager.h"
#include "Initialize.h"
#include <SDL.h>
#include <SDL_image.h>
#include "textureManager.h"
#include <string>
#include "settings.h"


SDL_Rect ButtonManager::createButton(std::string file_Path, int Frames , int FrameDuration)
{
	frameDuration = FrameDuration ;
	Texture = texture.textureManager(file_Path);
	SDL_QueryTexture(Texture, NULL, NULL, & image.w, & image.h);
	image.x = image.w; // in this case i use image.x for saving width of original image 
	image.w /= Frames; 
	frame = Frames; 
	return image ; 
}

void ButtonManager::updateButton(SDL_Rect dstR , int animation , float deltaTime  , bool isAnimated  )
{
	dst = dstR; // we set dst 
	
	src.h = image.h; // get image height 
	src.w = image.w; // gey image width 
	src.y = 0; // by default it is in zero 
	deltaTime *= 10; 
	 
	int target; 
	deltaTime *= 1000; 
	if (isAnimated) // that means if mouse on button 
	{
		target = frame; // that is updated with last frame
		timer +=  deltaTime;
		if (timer > frameDuration && currentFrame <  target - 1)
		{
			currentFrame++; 
			timer %= frameDuration ; 
			
		}
	}
	else
	{
		target = 0; // that is updated with last frame
		timer += deltaTime; // control the time 
		if (timer > frameDuration && currentFrame > 0)
		{
			currentFrame--;
			timer %= frameDuration;
		}
	}
	src.x = image.w * currentFrame;
}

void ButtonManager::renderButton()
{
	SDL_RenderCopy(Initialize::renderer, Texture, &src, &dst); 
}
