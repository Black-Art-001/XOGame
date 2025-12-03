#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "HomePage.h"
#include "handleEvent.h"
#include "settings.h"
#include "HomeController.h"
#include "backGroundManager.h"
#include "theme.h"
#include "soundManager.h"
#include "musicManager.h"

using namespace Settings;

HandleEvents handle;
HomeController *controller; 
music musH; 

void Home_Page::HomePage()
{
	controller = new HomeController;
	int frameTime = 1000 / FPS; // 16
	std::cout << "HomePage Opened !"<< std::endl; 

	musH.create_sound("sounds/A Sea Change.ogg");
	background.backGroundIMG(backGroundTheme(Settings::theme)); 

	controller->Init();

	int deltaTime = 0; 
	musH.play_music(0); 
	while (CurrentPage == Page::Home)
	{
		uint32_t timeStart = SDL_GetTicks(); 

		handle.handleEvent(); 
		
		controller->Update(deltaTime / 1000.0);
		
		controller->Render(); 

		uint32_t timeEnd = SDL_GetTicks();
		deltaTime = timeEnd - timeStart; 
		if (deltaTime < frameTime)
		{
			SDL_Delay(frameTime - deltaTime); 
		}
	}
	LastPage = Page::Home; 
	std::cout << "HomePage Closed !" << std::endl;
	SDL_Delay(200);
	musH.Free();
	controller->clear();
	delete controller; 
}