#pragma once

namespace Game_State
{
	extern bool isGameRunning;
	struct mousePos
	{
		int x ; 
		int y ; 
	};
	struct windowSize
	{
		int height; 
		int width;
	};
	extern mousePos mouse; 
	extern windowSize window; 
	extern bool isLeftClick ; 
	extern bool isRightClick ; 
	extern bool InsidePage;
}