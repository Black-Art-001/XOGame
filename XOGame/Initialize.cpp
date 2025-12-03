#include <iostream>
#include <SDL.h>
#include "Initialize.h"
#include "state.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

SDL_Renderer * Initialize::renderer = nullptr; 
SDL_Window* Initialize::window = nullptr;

void Initialize::InitGame(std::string NameOfGame , int width , int height , int flags)
{
	uint32_t rendering = 0;
	if (TTF_Init() == 0)
	{
		std::cout << "the text Initialization successful !" << std::endl;
	}

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(NameOfGame.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width , height , SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE ); 
	
	if (window)
	{
		std::cout << "the window creation successful !" << std::endl; 
	}
	else
	{
		std::cout << "Error : the window creation failed !" << SDL_GetError() << std::endl; 
		Game_State::isGameRunning = false; 
	}
	if (flags == 1)
	{
		rendering = SDL_RENDERER_ACCELERATED; 
	}

	renderer = SDL_CreateRenderer(window, -1, rendering);
	
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	if (renderer)
	{
		std::cout << "the renderer creation successful !" << std::endl; 
	}
	else if (!renderer && rendering)
	{
		std::cout << "the renderer (accelerated) creation failed !" << SDL_GetError() << std::endl;
		std::cout << "Try again in software renderer" << SDL_GetError() << std::endl; 
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "the renderer (software) creation successful !" << std::endl;
		}
	}
	if (!renderer)
	{
		std::cout << "the renderer creation failed !" << std::endl;
		Game_State::isGameRunning = false; 
	}
	
}