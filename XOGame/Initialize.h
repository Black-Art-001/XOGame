#pragma once
#include <string>
#include <SDL.h>
struct Initialize
{
	static SDL_Window* window; 
	static SDL_Renderer* renderer;

	void InitGame(std::string , int , int , int);
};