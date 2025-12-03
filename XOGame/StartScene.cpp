#include "StartScene.h"
#include "backGroundManager.h"
#include <SDL.h>
#include "theme.h"
#include <string>
#include "settings.h"
#include "Initialize.h"
#include "handleEvent.h"
#include <iostream>
#include "musicManager.h"

theme_path new_theme; 
HandleEvents handler; 
music* Mus; 

void Scene::pages(std::string file_path, std::string file_path_music , int number_of_frame, int speed)
{
	new_theme.file_path = file_path; 
	new_theme.n = number_of_frame; 
	new_theme.s = speed;
	Mus = new music; 
	Mus->create_sound(file_path_music); 
	background.backGroundIMG(new_theme);
	int frameDuration = 1000 / Settings::FPS; 
	int timer = 0; // set time in millisecond 
	float deltaT = 0;
	int counterF = 0; 
	bool isLoopRunning = true;
	Mus->play_music(0);
	while (isLoopRunning)
	{
		std::cout << counterF++ << '\n'; 
		uint32_t first_time = SDL_GetTicks();
		handler.handleEvent(); 
		background.backGroundUpdate(deltaT / 1000.0);
		SDL_RenderClear(Initialize::renderer); 
		isLoopRunning = background.backGroundRender();
		SDL_RenderPresent(Initialize::renderer); 
		uint32_t last_time = SDL_GetTicks();
		deltaT = last_time - first_time; 
		if (frameDuration > deltaT)
		{
			SDL_Delay(frameDuration - deltaT);
		}
	}
	Mus->Free(); 
	delete Mus; 
	background.clear(); 
}
