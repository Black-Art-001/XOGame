#include "settings.h"
#include <iostream>

namespace Settings {
	int FPS = 30 ; 
	int theme = 0; 
	int renderMod = 0; 
	int GAMEMode = 0;
	int LastGAMEMode = 2;
	int GameDifficulty = 0; 
	int LastGameDifficulty = 0;
	int turn = 0; 
	int gameIndex = 1; 
	int baseTurn; 
	int CurrentPage = Page::Home ;
	int LastPage = Page::Home;
	int sit = situation::inGame; 
	uint32_t renderMode = 0 ;
	uint32_t fullScreenMode = 0; 
}