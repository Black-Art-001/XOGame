#include "PvP.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "handleEvent.h"
#include "settings.h"
#include "backGroundManager.h"
#include "theme.h"
#include "SettingController.h"
#include "PvPcontroller.h"
#include "state.h"
#include "mapManager.h"
#include "musicManager.h" 

using namespace Settings; 
HandleEvents* events; 
PvPController* controller;
music muspvp; 
void PvPPage::PvpPage()
{
	muspvp.create_sound("sounds/Waves Coming.ogg");
	controller = new PvPController; 
	int frameTime = 1000 / FPS;
	std::cout << "PvP page was opened ! " << std::endl; 
	int n = 1, s = 0;
	background.backGroundIMG(backGroundTheme_Game(theme ));
	gridMap.GridMap(symbol1(theme), symbol2(theme) , gridImage(theme), baseGrid1(theme) , baseGrid2(theme));
	controller->Init(); 
	int deltaTime = 0; 
	int timeInPage = 0; 
	muspvp.play_music(0);
	while (GAMEMode == 0 && CurrentPage == Page::GameTOstart)
	{
		uint32_t startTime = SDL_GetTicks();
		events->handleEvent();
		
		controller->update(deltaTime/1000.0);
		controller->render();
		uint32_t endTime = SDL_GetTicks();
		deltaTime = endTime - startTime; 
		if (frameTime > deltaTime)
		{
			SDL_Delay(frameTime - deltaTime); 
		}
		
	}
	std::cout << "PvP page was closed ! " << std::endl;
	SDL_Delay(1000);
	muspvp.Free();
	controller->clear();
	Game_State::InsidePage = false;
	delete controller;
}
