#include "PvPcontroller.h"
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
#include "restart.h"

Massage *p1Turn; 
Massage* p2Turn;

using namespace Settings; 

ButtonController* back_B; 
ButtonController* restart_B;
ButtonController* redo;
ButtonController* undo;

void PvPController::Init()
{
	LastGAMEMode = GAMEMode; 
	p1Turn = new Massage; 
	p1Turn->textInit(MassagefontTheme_Game(theme), " Player 1 ", 512, fontMassageColor_Game(theme));
	p2Turn = new Massage; 
	p2Turn->textInit(MassagefontTheme_Game(theme), " Player 2 ", 512, fontMassageColor_Game(theme));
	back_B = new ButtonController;
	back_B->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "Back", fontColor_Game(theme), 12, 5, soundGH(theme), soundGC(theme));
	restart_B = new ButtonController;
	restart_B->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "Restart", fontColor_Game(theme), 12, 5, soundGH(theme), soundGC(theme));

	undo = new ButtonController;
	undo->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "undo", fontColor_Game(theme), 12, 5, soundGH(theme), soundGC(theme));

	redo = new ButtonController;
	redo->NEWButton(buttonTheme_Game(theme), fontTheme_Game(theme), "redo", fontColor_Game(theme), 12, 5, soundGH(theme), soundGC(theme));

}

void PvPController::update(float dT)
{
	int l = turn; 

	background.backGroundUpdate( dT	); 
	p1Turn->textCreator(15, 20, 0, 0  ,0.5); 
	p2Turn->textCreator(85, 20, 0, 0 , 0.5);
	
	Check.CheckGame();

	if (turn % 2 == 0)
	{
		gridMap.updateMap(dT, P1symbol ); // need to change ! 

	}
	else
	{
		gridMap.updateMap(dT, P2symbol );
	}
	
	back_B->UPDATEButton(15 , 5 , 1.2 , dT , 0.8 ,80 , 60 );
	restart_B->UPDATEButton(85, 5, 1.2, dT, 0.8, 80, 60);
	redo->UPDATEButton(62, 5, 1.2, dT, 0.8, 80, 60);
	undo->UPDATEButton(38, 5, 1.2, dT, 0.8, 80, 60);

	// undo button 
	if (undo->isButtonClicked)
	{
		if(gameIndex > 1)
		{
			turn--;
			gridMap.undo(--gameIndex);
		}
		Game_State::isLeftClick = false;
	}
	if (redo->isButtonClicked)
	{
		if (gridMap.redo(gameIndex))
		{
			gameIndex++; 
			turn++;
		}
		Game_State::isLeftClick = false;
	}
	if (back_B->isButtonClicked)
	{
		CurrentPage = Page::GameSetup;
	}
	// reset button action 
	if(restart_B->isButtonClicked)
	{
		restart_grid();
		Game_State::isLeftClick = false; 
		gridMap.loadGridMap();
	}

	// print in debug mode 
	if (l != turn)
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

void PvPController::render()
{
	SDL_RenderClear(Initialize::renderer);
	background.backGroundRender();
	if (turn % 2 == 0)
	{
		p1Turn->textRender();
	}
	else
	{
		p2Turn->textRender();
	}
	gridMap.RenderMap();
	restart_B->RenderButton();
	back_B->RenderButton();
	redo->RenderButton();
	undo->RenderButton();
	SDL_RenderPresent(Initialize::renderer);
}

void PvPController::clear()
{
	p1Turn->clear();
	p2Turn->clear();
	back_B->clear();
	restart_B->clear();
	gridMap.clear();
	delete p1Turn;
	delete p2Turn;
	delete back_B;
	delete restart_B;
	delete redo;
	delete undo;
}
