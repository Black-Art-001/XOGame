#include<iostream>
#include <conio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_mixer.h>
#include "settings.h"
#include "state.h"

#include "HomePage.h"
#include "Initialize.h"
#include "settingPage.h"
#include "GameSetup.h"
#include "GameMode.h"
#include "StartScene.h"

using namespace std; 

Mode* gameMODE; 
Setting_page* settingpage; 
Home_Page* homePage; 
Initialize* Starter; 
GameSetup* game_setup; 
Scene scene; 
int  main()
{
	Starter = new Initialize;
	Starter->InitGame("XO GAME", 800, 640, 0);

	scene.pages("assets/black art/0001.jpg" , "sounds/logo.ogg", 117, 240);
	scene.pages("assets/ba/0001.jpg", "sounds/logo.ogg  ", 130, 240);
	while (Game_State::isGameRunning)
	{
		if(Settings::CurrentPage == Settings::Page::Initializing)
		{
			SDL_DestroyRenderer(Initialize::renderer); 
			SDL_DestroyWindow(Initialize::window); 
			Starter->InitGame("XO GAME", 800, 640, Settings::renderMod);
			Settings::CurrentPage = Settings::Page::Home; 
		}
		else if (Settings::CurrentPage == Settings::Page::Home)
		{
			homePage = new Home_Page;
			homePage->HomePage(); 
			delete homePage; 

			Game_State::isLeftClick = false; 
		}
		else if (Settings::CurrentPage == Settings::Page::Setting)
		{
			settingpage = new Setting_page;
			settingpage->setting_page();
			delete settingpage;
			Game_State::isLeftClick = false;
		}
		else if (Settings::CurrentPage == Settings::Page::GameSetup)
		{
			game_setup = new GameSetup; 
			game_setup->gameSetup();
			delete game_setup; 
			Game_State::isLeftClick = false;
		}
		else if (Settings::CurrentPage == Settings::Page::GameTOstart)
		{
			gameMODE = new Mode; 
			gameMODE->GameModeChecker();
			delete gameMODE; 
			Game_State::isLeftClick = false;
		}
	}
	Mix_CloseAudio();
	SDL_DestroyRenderer(Initialize::renderer);
	SDL_DestroyWindow(Initialize::window);
	SDL_Quit();
	std::cout << "Game closed ! ";
	return 0; 
}