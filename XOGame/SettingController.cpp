#include "SettingController.h"
#include "backGroundManager.h"
#include "Initialize.h"
#include "buttonManager.h"
#include "theme.h"
#include "settings.h"
#include "buttonController.h"
#include <string>
#include <iostream>
#include "textMassage.h"
#include "state.h"

using namespace Settings; 

Massage* FPSMassage; 
Massage* renderMassage; 
Massage* themeMassage; 

ButtonController *backButton;
ButtonController* FPSButton;
ButtonController* RenderMod; 
ButtonController* Theme; 
void Setting_Controller::Init()
{
	renderMassage = new Massage; 
	renderMassage->textInit(fontTheme_Setting(theme), "Set Render Engine : ", 512, fontMassageColor_Setting(theme)); 
	themeMassage = new Massage; 
	themeMassage->textInit(fontTheme_Setting(theme), "Set Theme : ", 512, fontMassageColor_Setting(theme)); 
	std::string themeMod; 
	switch (theme)
	{
	case 0: themeMod = "Dark Mod"; break;
	case 1:themeMod = "Light Mod"; break; 
	}
	Theme = new ButtonController; 
	Theme->NEWButton(buttonTheme_Setting(theme), fontTheme_Setting(theme), themeMod, fontColor_Setting(theme), 12, 5 , soundSH(theme) , soundSC(theme));
	std::string fps = "to FPS:30Hz";
	switch (FPS)
	{
	case 30:  fps = "FPS:30Hz"; break;
	case 45:  fps = "FPS:45Hz"; break;
	case 60:  fps = "FPS:60Hz"; break;
	case 120: fps = "FPS:120Hz"; break;
	}
	// back button
	backButton = new ButtonController; 
	backButton->NEWButton(buttonTheme_Setting(theme),fontTheme_Setting(theme) , " Back " , fontColor_Setting(theme), 12, 3, soundSH(theme), soundSC(theme));
	// FPS massage 
	FPSMassage = new Massage;
	FPSMassage->textInit(fontTheme_Setting(theme), "Set FPS to the : ", 512,  fontMassageColor_Setting(theme));
	// FPS control button :
	FPSButton = new ButtonController; 
	FPSButton->NEWButton(buttonTheme_Setting(theme), fontTheme_Setting(theme), fps, fontColor_Setting(theme), 12, 5, soundSH(theme), soundSC(theme));
	std::string rendermassage; 
	switch (renderMod)
	{
	case 0:rendermassage = "Accelerated Rendering"; break;
	case 1:rendermassage = "Software Rendering"; break; 
	}
	RenderMod = new ButtonController;
	RenderMod->NEWButton(buttonTheme_Setting(theme), fontTheme(theme), rendermassage, fontColor_Setting(theme), 12, 5, soundSH(theme), soundSC(theme));
}

void Setting_Controller::update( float dT)
{
	int lastFPS = FPS; 
	background.backGroundUpdate( dT);
	backButton->UPDATEButton(15, 10, 1.2, dT, 1, 60, 70); 
	FPSButton->UPDATEButton(80, 50 , 1.5, dT, 1, 60, 80);
	RenderMod->UPDATEButton(80, 35, 1.5, dT, 1, 40, 90);
	Theme->UPDATEButton(80, 65, 1.5, dT, 1, 60, 70);
	FPSMassage->textCreator(40, 50, setRealW, setRealH, 0.8);
	renderMassage->textCreator(40, 35, setRealW, setRealH, 0.8); 
	themeMassage->textCreator(40, 65, setRealW, setRealH, 0.8);
	int Last_rendermod = renderMod; 
	// theme button
	int LastTheme = theme; 
	if (Theme->isButtonClicked )
	{
		if (theme == 0) theme = 1;
		else if (theme == 1) theme = 0; 
		Something_Changed = true; 
		std::cout << "theme has changed " << std::endl;
		Game_State::isLeftClick = false;
	}
	// theme button massage 
	if (theme != LastTheme)
	{
		std::string themeMod; 

		switch (theme)
		{
		case 0: themeMod = "Dark Mod"; break;
		case 1:themeMod = "Light Mod"; break;
		}
		Theme->text.textInit(fontTheme_Setting(theme), themeMod, 512, fontColor_Setting(theme));
	}
	// Render Mod Button
	int Lastrender = renderMod; 
	if (RenderMod->isButtonClicked )
	{
		if (renderMod == 0) renderMod = 1;
		else if (renderMod == 1) renderMod = 0; 
		Something_Changed = true; 
		isNeedToRestart = true;
		Game_State::isLeftClick = false;
	}
	// Render Mod Massage
	if (Last_rendermod != renderMod)
	{
		std::string renderMassage;

		switch (renderMod)
		{
		case 0:renderMassage = "Accelerated Rendering"; break;
		case 1:renderMassage = "Software Rendering"; break;
		}
		RenderMod->text.textInit(fontTheme_Setting(theme), renderMassage, 512, fontColor_Setting(theme));
	}
	// back Button 
	if (backButton->isButtonClicked && isNeedToRestart)
	{
		CurrentPage = Page::Initializing ;
	}
	else if (backButton->isButtonClicked)
	{
		CurrentPage = LastPage ;
	}
	//FPS Button
	if (FPSButton->isButtonClicked )
	{
		switch (FPS)
		{
		case 30: FPS = 45; break; 
		case 45: FPS = 60; break;
		case 60: FPS = 120; break;
		case 120:FPS = 30; break;
			std::cout << "FPS chenged to " << FPS << std::endl; 
		}
		Something_Changed = true; 
		Game_State::isLeftClick = false;
	}
	// FPS Button Massage 
	if (lastFPS != FPS)
	{
		lastFPS = FPS;
		std::string fps;
		switch (FPS)
		{
		case 30:  fps = "FPS:30Hz"; break;
		case 45:  fps = "FPS:45Hz"; break;
		case 60:  fps = "FPS:60Hz"; break;
		case 120: fps = "FPS:120Hz"; break;
		}
		FPSButton->text.textInit(fontTheme_Setting(theme), fps, 512, fontColor_Setting(theme)); 
		std::cout << FPS << std::endl; 
	}
	// Back Button Massage
	if (Something_Changed && ButtonNOTUpdated)
	{
		backButton->text.textInit(fontTheme_Setting(theme), "Save&Quit", 512, fontColor_Setting(theme)); 
		ButtonNOTUpdated = false; 
	}
}

void Setting_Controller::render()
{
	SDL_RenderClear(Initialize::renderer); 
	background.backGroundRender();
	backButton->RenderButton(); 
	FPSButton->RenderButton(); 
	Theme->RenderButton();
	FPSMassage->textRender();
	RenderMod->RenderButton(); 
	renderMassage->textRender();
	themeMassage->textRender(); 
	SDL_RenderPresent(Initialize::renderer); 
}

void Setting_Controller::clear()
{
	backButton->clear();
	FPSButton->clear(); 
	RenderMod->clear(); 
	Theme->clear(); 
	FPSMassage->clear(); 
	renderMassage->clear();
	themeMassage->clear(); 
	delete backButton; 
	delete FPSButton; 
	delete RenderMod;
	delete Theme; 
	delete FPSMassage; 
	delete renderMassage;
	delete themeMassage;
}
