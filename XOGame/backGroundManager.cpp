#include <SDL.h>
#include <string> 
#include <iostream>
#include "backGroundManager.h"
#include "TextureManager.h"
#include "state.h"
#include "Initialize.h"
#include "theme.h"

backGround background;

void backGround::backGroundIMG(theme_path x)
{
	FrameDuration = x.s == 0 ? 0 : 100.0 / x.s; // get framme duration in initialize
	numberOfFrame = x.n; 
	image = new SDL_Texture * [x.n];
	std::cout << "source file path : " << x.file_path << '\n';
	if(x.n == 1)
	{
		image[0] = texture.textureManager(x.file_path);
	}
	else
	{
		std::string first_file_path = x.file_path;
		int first = first_file_path.find_first_of("0123456789");
		int last = first_file_path.find('.');
		int len = last - first;
		int frame = std::stoi(first_file_path.substr(first, len));
		for (int i = 0; i < x.n; i++)
		{
			std::string strnumber = std::to_string(frame++);
			std::string mark(len - strnumber.length(), '0');
			mark.append(strnumber);
			first_file_path.replace(first, len, mark );
			image[i] = texture.textureManager(first_file_path);
			std::cout << "loaded : " << first_file_path << '\n';
		}
	}
	
	if (image[0])
		std::cout << "texture loaded\n";
	SDL_QueryTexture(image[0], nullptr, nullptr, &srcW, &srcH);
	
	dstRect.h = srcH;
	dstRect.w = srcW;
}

void backGround::backGroundUpdate( float dT)
{
	deltaTime = dT; // we get delta Time in upadte function
	windowRatio = Game_State::window.width / static_cast<float>(Game_State::window.height);
	imageRatio = srcW / static_cast<float>(srcH);

	if (windowRatio < imageRatio)
	{
		dstRect.h = Game_State::window.height;
		dstRect.w = static_cast<int>(srcW * (static_cast<float>(Game_State::window.height) / static_cast<float>(srcH)));
	}
	else 
	{
		dstRect.w = Game_State::window.width; 
		dstRect.h = static_cast<int>(srcH * (static_cast<float>(Game_State::window.width) / static_cast<float>(srcW)));
	}
	dstRect.x = static_cast<int>(Game_State::window.width - dstRect.w)/2;
	dstRect.y = static_cast<int>(Game_State::window.height - dstRect.h)/2;

}

bool backGround::backGroundRender()
{
	//static int frameIndex = 0; 
	//static int Timer = 0;
	if(FrameDuration != 0)
	{
		Timer += deltaTime * 1000;
		if (Timer > FrameDuration)
		{
			Timer = 0;
			if (++frameIndex == numberOfFrame) frameIndex = 0;
		}
	}
	//if(image[frameIndex] != nullptr)
	SDL_RenderCopy(Initialize::renderer, image[frameIndex], NULL, &dstRect);
	if (FrameDuration != 0 && frameIndex == numberOfFrame - 1) return false; 
	return true;
}

void backGround::clear()
{
	Timer = 0; 
	frameIndex = 0; 
}



