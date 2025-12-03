#pragma once
#include <SDL.h>
#include<string>
#include "TextManager.h"
#include"buttonManager.h"
#include "soundManager.h"

struct ButtonController
{
	SDL_Rect dst  ;
	SDL_Rect image ;
	int scale; 
	int firstPosX, firstPosY; 
	Text text;
	ButtonManager* button = nullptr;
	float baseScale = 1;

	bool isSoundplyed = false;

	sound *click_sound;
	sound* hover_sound;
	float smoothScaling = baseScale;

	void NEWButton(std::string file_path , std::string font_path, std::string massage , SDL_Color color ,int number_of_frame , int frameDuration , std::string soundHover , std::string soundClick);

	void UPDATEButton(int x , int y , float scale_change, float deltaTime, float size , int fill_Y , int fill_X );

	void RenderButton(); 
	bool isButtonClicked = false ;
	
	void clear();
};