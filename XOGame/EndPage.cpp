#include "EndPage.h"
#include "XOGrid.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "handleEvent.h"
#include "settings.h"
#include "backGroundManager.h"
#include "theme.h"
#include "buttonController.h"
#include "Initialize.h"
#include "state.h"
#include "textMassage.h"
#include "EndPageController.h"
#include "musicManager.h"
using namespace Settings;

HandleEvents lasthandle;

music musE; 
EndPageController* controllerE;
GameEnd gameEndPage;

void GameEnd::GameENDPage()
{ 
	std::string massage; 
	switch (sit)
	{
	case situation::even:
		massage = "sounds/Cruelty.ogg";
		break;
	case situation::loss:
		massage = "sounds/Intro.ogg";
		break;
	case situation::Win:
		if (LastGAMEMode == 0)
		{
			massage = "sounds/Root x.ogg";
		}
		else
		{
			massage = "sounds/Root x.ogg";
		}
		break;
	case situation::Win2:
		massage = "sounds/Root x.ogg";
		break;
	}
	musE.create_sound(massage);
	int frameTime = 1000 / FPS; // 16
	std::cout << "Massage Page Opened !" << std::endl;
	background.backGroundIMG(backGroundTheme_EndPage(sit));

	controllerE->Init();
	int deltaTime = 0;
	musE.play_music(0); 
	while (GAMEMode == -1 && CurrentPage == Page::GameTOstart)
	{
		uint32_t timeStart = SDL_GetTicks();

		// handle events
		lasthandle.handleEvent();

		// game uppdate
		controllerE->update(deltaTime / 1000.0); 

		// game render 
		controllerE->render();

		uint32_t timeEnd = SDL_GetTicks();

		// set FPS
		deltaTime = timeEnd - timeStart;
		if (deltaTime < frameTime)
		{
			SDL_Delay(frameTime - deltaTime);
		}
	}
	LastPage = Page::GameTOstart ;
	std::cout << "Massage Page Closed !" << std::endl;
	SDL_Delay(200);
	musE.Free();
	controllerE->clear(); 
	Game_State::isLeftClick = false;
	delete controllerE; 
}