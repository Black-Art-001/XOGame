#include "handleEvent.h"
#include "state.h"
#include <SDL.h>
#include "settings.h"
#include "Initialize.h"

void HandleEvents::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT :
		Game_State::isGameRunning = false;
		Settings::CurrentPage = Settings::Page::Exit ;
		break; 
	case SDL_MOUSEBUTTONDOWN :
		switch (event.button.button)
		{
		case SDL_BUTTON_LEFT :
			Game_State::isLeftClick = true;
			break;
		case SDL_BUTTON_RIGHT :
			Game_State::isRightClick = true; 
			break; 
		}
		break;
	case SDL_MOUSEBUTTONUP :
		switch (event.button.button)
		{
		case SDL_BUTTON_LEFT :
			Game_State::isLeftClick = false;
			break;
		case SDL_BUTTON_RIGHT :
			Game_State::isRightClick = false;
			break;
		}
		break;
	case SDL_MOUSEMOTION :
		Game_State::mouse.x = event.motion.x;
		Game_State::mouse.y = event.motion.y;
		break;
	default:
		break;
	}

	SDL_GetWindowSize(Initialize::window, &Game_State::window.width, &Game_State::window.height); 
}
