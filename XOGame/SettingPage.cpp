#include "SettingPage.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "handleEvent.h"
#include "settings.h"
#include "backGroundManager.h"
#include "theme.h"
#include "SettingController.h"
#include "musicManager.h"

using namespace Settings ; 
Setting_Controller * controller; 
	
HandleEvents handle_events;
music muss;

void Setting_page::setting_page()
{
	muss.create_sound("sounds/Time Loop.ogg"); 
	controller = new Setting_Controller; 
	int frameTime = 1000 / FPS; // 16
	std::cout << "SettingPage Opened !" << std::endl;
	int n = 1, s = 0;
	background.backGroundIMG(backGroundTheme_Setting(Settings::theme));
	controller->Init();
	int deltaTime = 0; 
	muss.play_music(0); 
	while (CurrentPage == Page::Setting)
	{
		uint32_t timeStart = SDL_GetTicks(); 
		handle_events.handleEvent(); 

		controller->update(deltaTime/1000.0);
		

		controller->render(); 

		uint32_t timeEnd = SDL_GetTicks();
		deltaTime = timeEnd - timeStart; 
		if (deltaTime < frameTime)
		{
			SDL_Delay(frameTime - deltaTime);
		}
	}
	SDL_Delay(200);
	controller->clear(); 
	muss.Free();
	std::cout << "SettingPage Closed !" << std::endl;
	delete controller;
}
