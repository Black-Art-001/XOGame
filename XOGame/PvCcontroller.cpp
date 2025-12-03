#include "PvCcontroller.h"
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
#include "GameReferee.h"
#include "BotMovment.h"

BotMovment* bot;
Massage* p1Turnc;
Massage* p2Turnc;

using namespace Settings;

ButtonController* back_Bc;
ButtonController* restart_Bc;
ButtonController* Redo;
ButtonController* Undo;

void PvCController::Init()
{
	Undo = new ButtonController;
	Undo->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "undo", fontColor_Game(theme), 12, 5, soundGH(theme), soundGC(theme));

	Redo = new ButtonController;
	Redo->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "redo", fontColor_Game(theme), 12, 5, soundGH(theme), soundGC(theme));

	LastGAMEMode = GAMEMode;
	p1Turnc = new Massage;
	p1Turnc->textInit(MassagefontTheme_Game(theme), " You ", 512, fontMassageColor_Game(theme));
	p2Turnc = new Massage;
	p2Turnc->textInit(MassagefontTheme_Game(theme), " Bot ", 512, fontMassageColor_Game(theme));
	back_Bc = new ButtonController;
	back_Bc->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "Back", fontColor_Game(theme), 12, 5 , soundGH(theme) , soundGC(theme));
	restart_Bc = new ButtonController;
	restart_Bc->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "Restart", fontColor_Game(theme), 12, 5, soundGH(theme), soundGC(theme));
	bot = new BotMovment;
}

void PvCController::update(float dT)
{
	int lastturn = turn;
	
	background.backGroundUpdate(dT);
	p1Turnc->textCreator(15, 20, 0, 0, 0.5);
	p2Turnc->textCreator(85, 20, 0, 0, 0.5);
	Redo->UPDATEButton(62, 5, 1.2, dT, 0.8, 80, 60);
	Undo->UPDATEButton(38, 5, 1.2, dT, 0.8, 80, 60);
	Check.CheckGame();

	
	if (turn % 2 == 0)
	{
		gridMap.updateMap(dT, P1symbol); // need to change ! 
	}
	else 
	{
			bot->BotMove();
			turn++;
			gridMap.loadGridMap();
	}

	back_Bc->UPDATEButton(15, 5, 1.2, dT, 0.8, 80, 60);
	restart_Bc->UPDATEButton(85, 5, 1.2, dT, 0.8, 80, 60);
	if (back_Bc->isButtonClicked)
	{
		CurrentPage = Page::GameSetup;
	}
	
	// undo 
	if (Undo->isButtonClicked)
	{
		if (gameIndex > 0)
		{
			turn--;
			gridMap.undo(--gameIndex);
			if (turn % 2 == 1)
			{
				turn--;
				gridMap.undo(--gameIndex);
			}
		}
		Game_State::isLeftClick = false;
	}
	//redo
	if (Redo->isButtonClicked)
	{
		
		if (gridMap.redo(gameIndex))
		{
			gameIndex++;
			turn++;
			if (turn % 2 == 1)
			{
				gridMap.redo(gameIndex);
				gameIndex++;
				turn++;
			}
		}
		Game_State::isLeftClick = false;
	}
	
	// reset button action 
	if (restart_Bc->isButtonClicked)
	{
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
		turn = baseTurn;
		Game_State::isLeftClick = false;
		gridMap.loadGridMap();
	}
	
	if (lastturn != turn)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cout << XOGrid::Grid[1][i + 1][j + 1] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "^^^ game index ^^^\n";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				std::cout << XOGrid::Grid[0][i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "^^^ game cells ^^^\n";

	}
}

void PvCController::render()
{
	SDL_RenderClear(Initialize::renderer);
	background.backGroundRender();
	if (turn % 2 == 0)
	{
		p1Turnc->textRender();
	}
	else
	{
		p2Turnc->textRender();
	}
	gridMap.RenderMap();
	restart_Bc->RenderButton();
	back_Bc->RenderButton();
	Redo->RenderButton();
	Undo->RenderButton();
	SDL_RenderPresent(Initialize::renderer);
}

void PvCController::clear()
{
	p1Turnc->clear();
	p2Turnc->clear();
	back_Bc->clear();
	restart_Bc->clear();
	gridMap.clear();
	delete p1Turnc;
	delete p2Turnc;
	delete back_Bc;
	delete restart_Bc;
}
