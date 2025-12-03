#include "PvC.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "handleEvent.h"
#include "settings.h"
#include "backGroundManager.h"
#include "theme.h"
#include "SettingController.h"
#include "state.h"
#include "mapManager.h"
#include "PvCcontroller.h"
#include "musicManager.h"

using namespace Settings;
HandleEvents* events_pvc;
music muspvc; 
PvCController* controller;

void PvCPage::PvcPage()
{
	muspvc.create_sound("sounds/Waves Coming.ogg");
	controller = new PvCController;
	int frameTime = 1000 / FPS;
	std::cout << "PvC page was opened ! " << std::endl;
	int n = 1, s = 0;
	background.backGroundIMG(backGroundTheme_Game(theme ));
	gridMap.GridMap(symbol1(theme), symbol2(theme), gridImage(theme), baseGrid1(theme), baseGrid2(theme));
	controller->Init();
	int deltaTime = 0;
	int timeInPage = 0;
	muspvc.play_music(0);
	while (GAMEMode == 1 && CurrentPage == Page::GameTOstart)
	{
		uint32_t startTime = SDL_GetTicks();
		events_pvc->handleEvent();

		controller->update(deltaTime / 1000.0);
		controller->render();
		uint32_t endTime = SDL_GetTicks();
		deltaTime = endTime - startTime;
		if (frameTime > deltaTime)
		{
			SDL_Delay(frameTime - deltaTime);
		}

	}
	std::cout << "PvC page was closed ! " << std::endl;
	SDL_Delay(1000); 
	muspvc.Free();
	controller->clear(); 
	Game_State::InsidePage = false;
	delete controller;
}

