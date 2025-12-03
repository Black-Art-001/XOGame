#include "GameReferee.h"
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

#define fin isMatchEnded = true
#define situ Settings::situation
#define sit Settings::sit


Referee Check;
void Referee::CheckGame()
{
	bool iswin = false;
	bool enemyiswin = false; 
	// plyer check ! 
	for (int i = 1; i <= 3; i++)
	{
		if (XOGrid::Grid[0][0][i] == 3 || XOGrid::Grid[0][i][0] == 3)
		{
			iswin = true;
			break;
		}
		
	}
	if (XOGrid::Grid[0][4][0] == 3 || XOGrid::Grid[0][0][0] == 3)
	{
		iswin = true;
		
	}
	
	if (iswin)
	{
		sit = situ::Win;
		std::cout << "win page must load ! " << std::endl;
	}

	// enemy check ! 
	//////
	for (int i = 1; i <= 3; i++)
	{
		if (XOGrid::Grid[0][4][i] == 3 || XOGrid::Grid[0][i][4] == 3)
		{
			enemyiswin = true; 
			break; 
		}
	}
	if (XOGrid::Grid[0][0][4] == 3 || XOGrid::Grid[0][4][4] == 3)
	{
		enemyiswin = true; 
	}
	//////
	if (enemyiswin && Settings::GAMEMode == 0)
	{
		sit = situ::Win2; // win2 P2 winner 
		std::cout << "win 2 page must load ! " << std::endl;

	}
	else if (enemyiswin && Settings::GAMEMode == 1)
	{
		sit = situ::loss; // loss you loss aginst bot 
		std::cout << "loss page must load ! " << std::endl;

	}
	//////

	//////
	int sum = 0;
	for (int i = 1; i < 4; i++)
	{
		 sum += (XOGrid::Grid[0][i][0] + XOGrid::Grid[0][i][4]);
	}
	if (sum == 9 && !enemyiswin && !iswin)
	{
		sit = situ::even;
		Settings::LastGAMEMode = Settings::GAMEMode;
		Settings::GAMEMode = -1;
	}
	if (iswin || enemyiswin)
	{
		Settings::LastGAMEMode = Settings::GAMEMode;
		Settings::GAMEMode = -1;
	}

}
