#include "GameSetup.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "handleEvent.h"
#include "settings.h"
#include "backGroundManager.h"
#include "theme.h"
#include "SettingController.h"
#include "GameSetupController.h"
#include "musicManager.h"

using namespace Settings; 
HandleEvents events; 
GameSetupController* controller; 
music musS; 

void GameSetup::gameSetup()
{
	controller = new GameSetupController;
	int frameTime = 1000 / FPS; 
	int n = 1, s = 0;
	musS.create_sound("sounds/Broken Radiance.ogg"); 
	background.backGroundIMG(backGroundTheme_GameSetup(theme ));
	std::cout << "Game setup Page was Opened ! "<< std::endl;
	controller->Init();
	
	int deltaTime = 0; 
	musS.play_music(0);

	while (CurrentPage == Page::GameSetup)
	{
		uint32_t timeStart = SDL_GetTicks();
		events.handleEvent(); 

		controller->update(deltaTime/1000.0);
		
		controller->render(); 

		uint32_t timeEnd = SDL_GetTicks();
		deltaTime = timeEnd - timeStart;
		if (deltaTime < frameTime)
		{
			SDL_Delay(frameTime - deltaTime); 
		}
	}
	LastPage = Page::GameTOstart;

	std::cout << "Game setup Page was Closed ! " << std::endl;
	SDL_Delay(200);
	controller->clear();
	musS.Free();
	delete controller; 
	turn = baseTurn; 
}
