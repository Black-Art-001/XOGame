#include "HomeController.h"
#include "settings.h"
#include "state.h"
#include "Initialize.h"
#include <SDL.h>
#include <iostream>
#include "backGroundManager.h"
#include "buttonController.h"
#include "theme.h"
#include "textMassage.h"
#include "soundManager.h"

#define theme Settings::theme

Massage* text1; 

ButtonController* start_button;
ButtonController* setting_button;
ButtonController* exit_button; 

void HomeController::Init()
{
	
	text1 = new Massage; 
	text1->textInit(MassagefontTheme(theme), "Welcome to the XO", 512, fontMassageColor(theme));

	start_button = new ButtonController;
	start_button->NEWButton( buttonTheme(theme), fontTheme(theme), " start ", fontColor(theme), 12, 5 , soundHH(theme) , soundHC(theme));
	setting_button = new ButtonController;
	setting_button->NEWButton(buttonTheme(theme), fontTheme(theme), " setting ", fontColor(theme) ,  12, 5, soundHH(theme), soundHC(theme));
	exit_button = new ButtonController;
	exit_button->NEWButton(buttonTheme(theme), fontTheme(theme), " Exit ", fontColor(theme), 12, 5, soundHH(theme), soundHC(theme));
}

void HomeController::Update( float deltaTime )
{
	text1->textCreator(50, 10, setRealW, setRealH, 1); 

	if (start_button->isButtonClicked)
	{
		Settings::CurrentPage = Settings::Page::GameSetup; 
	}
	else if (setting_button->isButtonClicked)
	{
		Settings::CurrentPage = Settings::Page::Setting;
	}
	else if (exit_button->isButtonClicked)
	{
		Game_State::isGameRunning = false;
		Settings::CurrentPage = Settings::Page::Exit;
	}
	background.backGroundUpdate( deltaTime);  
	start_button->UPDATEButton(50, 50 , 1.5f ,  deltaTime , 1 , 80 , 80);
	setting_button->UPDATEButton(50, 65, 1.2f, deltaTime, 0.8f, 80 , 90); 
	exit_button->UPDATEButton(50, 75, 1.2f, deltaTime, 0.8f, 80, 60);
}

void HomeController::Render()
{
	SDL_RenderClear(Initialize::renderer);


	background.backGroundRender();
	start_button->RenderButton();
	setting_button->RenderButton();
	exit_button->RenderButton();
	text1->textRender();

	SDL_RenderPresent(Initialize::renderer);
}

void HomeController::clear()
{
	background.clear(); 
	start_button->clear();
	setting_button->clear();
	exit_button->clear();
	text1->clear();
	delete text1;
	delete start_button;
	delete setting_button;
	delete exit_button;
}
