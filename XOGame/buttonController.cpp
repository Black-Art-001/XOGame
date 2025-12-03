#include "buttonController.h"
#include "buttonManager.h"
#include "TextManager.h"
#include "state.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "soundManager.h"

#define screenH Game_State::window.height
#define screenW Game_State::window.width
#define Mpx Game_State::mouse.x 
#define Mpy Game_State::mouse.y


void ButtonController::NEWButton(std::string file_path, std::string font_path,  std::string massage, SDL_Color color , int number_of_frame, int frameDuration , std::string sH , std::string sC)
{	
	click_sound = new sound; 
	click_sound->create_sound(sC);
	hover_sound = new sound;
	hover_sound->create_sound(sH);
	button = new ButtonManager;
	text.textInit(font_path, massage, 256, color);
	image = button->createButton(file_path , number_of_frame , frameDuration);  
}

void ButtonController::UPDATEButton(int x , int y  , float scale_change , float dT , float size  ,int fillx , int filly )
{
	isButtonClicked = false; 
	dst.x = firstPosX =  screenW * x / 100  ; 
	dst.y = firstPosY = screenH * y / 100  ;
	// set base scale 
	float baseScale = 1;
	if (screenW * screenH >= 1280*720) {
		baseScale = 3;
	}
	else if (screenW * screenH >=800 * 640) {
		baseScale = 2;
	}
	baseScale *= size; 
	// mouse checker 
	dst.w = image.w * baseScale;
	dst.h = image.h *baseScale;
	dst.x -= dst.w / 2;
	dst.y -= dst.h / 2;

	// set variable 
	float targetScale = baseScale;
	
	// is Hover : 
	bool isHover = ((Mpx > dst.x && Mpx < dst.x + dst.w) &&(Mpy > dst.y && Mpy < dst.y + dst.h)); 
	
	if (isHover)
	{
		if (!isSoundplyed)
		{
			hover_sound->play_sound(1);
			isSoundplyed = true;
		}
		targetScale  *= scale_change; // make it 120%
		if (Game_State::isLeftClick)
		{
			isButtonClicked = true; 
			click_sound->play_sound(1);
		}
	}
	else
	{
		if (isSoundplyed)
			isSoundplyed = false; 
	}
	
	// use delta time 
	float speed = 200; 

	smoothScaling += (targetScale - smoothScaling) * dT * speed; 
	dst.w = image.w * smoothScaling;
	dst.h = image.h * smoothScaling;
	dst.x = firstPosX - dst.w / 2;
	dst.y = firstPosY -  dst.h / 2;
	

	
	button->updateButton(dst , 0 , dT  , isHover); 
	text.textCreator(dst , fillx , filly ); 
}

void ButtonController::RenderButton()
{
	button->renderButton(); 
	text.textRender(); 
}

void ButtonController::clear()
{
	click_sound->Free();
	delete button; 
	delete click_sound;
	delete hover_sound;
}
