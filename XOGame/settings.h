#pragma once

namespace Settings {
	extern int FPS; 
	extern int theme; 
	extern int CurrentPage; 
	extern int LastPage;
	extern int renderMod; 
	extern int GameDifficulty; 
	extern int LastGameDifficulty;
	extern int gameIndex; 
	extern int GAMEMode; 
	extern int LastGAMEMode ;

	extern int turn; 
	extern int sit;
	extern int baseTurn;
	enum Page
	{
		Initializing, Home, Setting, GameSetup, Exit, GameTOstart , EndPage
	};
	enum situation
	{
		Win , Win2 , loss , even , inGame
	};
}