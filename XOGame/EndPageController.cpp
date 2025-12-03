#include "EndPageController.h"
#include "settings.h"
#include "state.h"
#include "Initialize.h"
#include <SDL.h>
#include <iostream>
#include "backGroundManager.h"
#include "buttonController.h"
#include "theme.h"
#include "textMassage.h"
#include "mapManager.h"
#include "XOGrid.h"

using namespace Settings;

Massage* notification;

ButtonController* reset;
ButtonController* giveup;
void EndPageController::Init()
{
	std::string massage; 
	switch (sit)
	{
	case situation::even :
		massage = "No one wins";
		break;
	case situation::loss :
		massage = "You Loss";
		break;
	case situation::Win :
		if (LastGAMEMode == 1)
		{
			massage = "you win"; 
		}
		else
		{
			massage = "Player 1 won"; 		}
		break;
	case situation::Win2 :
		massage = "Player 2 won ";
		break;
	}
	reset = new ButtonController;
	reset->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "RESTART", fontColor_Game(theme), 12, 5 , soundEH(theme) , soundEC(theme));
	giveup = new ButtonController;
	giveup->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "BACK to HOME", fontColor_Game(theme), 12, 5, soundEH(theme), soundEC(theme));
	//massage
	notification = new Massage;
	notification->textInit(MassagefontTheme_Game(theme) , massage, 512, fontMassageColor_Game(theme));
}

void EndPageController::update(float dT)
{
	// clear game grid
	for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					XOGrid::Grid[i][j][k] = 0;
				}
			}
		}
	background.backGroundUpdate(dT);
	notification->textCreator(50, 35, 0, 0, 1);
	reset->UPDATEButton(50, 50, 1.5, dT, 1, 80, 70);
	giveup->UPDATEButton(50, 65, 1.5, dT, 1, 70, 90);
	if (reset->isButtonClicked)
	{
		std::cout << "Game Mod : " << GAMEMode << std::endl;
		GAMEMode = LastGAMEMode; 
		std::cout << "Game Mod : " << GAMEMode << std::endl;
		std::cout << "last Difficaulty : " << GameDifficulty << std::endl;
		LastGAMEMode = -1;
		turn = baseTurn;
		Game_State::isLeftClick = false;
	}
	if (giveup->isButtonClicked)
	{
		CurrentPage = Page::Home; 
		LastGAMEMode = -1;
	}
}

void EndPageController::render()
{
	SDL_RenderClear(Initialize::renderer);
	background.backGroundRender();
	notification->textRender();
	reset->RenderButton();
	giveup->RenderButton();
	SDL_RenderPresent(Initialize::renderer);
}

void EndPageController::clear()
{
	notification->clear(); 
	reset->clear();
	giveup->clear();
	delete notification; 
	delete reset;
	delete giveup;
}
