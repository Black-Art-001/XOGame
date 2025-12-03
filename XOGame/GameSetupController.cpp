#include "GameSetupController.h"
#include "backGroundManager.h"
#include "Initialize.h"
#include "buttonManager.h"
#include "theme.h"
#include "settings.h"
#include "buttonController.h"
#include <string>
#include <iostream>
#include "textMassage.h"
#include "state.h"
#include "XOGrid.h"
#include "restart.h"

using namespace Settings; 
ButtonController* back_button; 
ButtonController* gameMode_button;
ButtonController* game_level_button;
ButtonController* game_turn_button;
ButtonController* start_button_setup;
ButtonController* continue_button_setup;

void GameSetupController::Init()
{
	GameDifficulty = 0; 
	GAMEMode = 0; 
	// back button
	back_button = new ButtonController; 
	back_button->NEWButton(buttonTheme_GameSetup(theme), fontTheme_GameSetup(theme) , "back" , fontColor_GameSetup(theme), 12, 5 , soundGsH(theme) , soundGsC(theme));
	// game mode button
	gameMode_button = new ButtonController;
	gameMode_button->NEWButton(buttonTheme_GameSetup(theme), fontTheme_GameSetup(theme), "PvP", fontColor_GameSetup(theme), 12, 5, soundGsH(theme), soundGsC(theme));
	// game difficulty 
	game_level_button = new ButtonController;
	game_level_button->NEWButton(buttonTheme_GameSetup(theme), fontTheme_GameSetup(theme), "Easy", fontColor_GameSetup(theme), 12, 5, soundGsH(theme), soundGsC(theme));
	// game turn 
	game_turn_button = new ButtonController;
	game_turn_button->NEWButton(buttonTheme_GameSetup(theme), fontTheme_GameSetup(theme), "Player 1", fontColor_GameSetup(theme), 12, 5, soundGsH(theme), soundGsC(theme));
	// start
	start_button_setup = new ButtonController;
	start_button_setup->NEWButton(buttonTheme_GameSetup(theme), fontTheme_GameSetup(theme), "New Game", fontColor_GameSetup(theme), 12, 5, soundGsH(theme), soundGsC(theme));
	std::cout << "Game setup Init! "<< std::endl;
	// countinue 
	continue_button_setup = new ButtonController;
	continue_button_setup->NEWButton(buttonTheme_GameSetup(theme), fontTheme_GameSetup(theme), "Continue", fontColor_GameSetup(theme), 12, 5, soundGsH(theme), soundGsC(theme));
	
}

void GameSetupController::update(float deltaTime)
{
	background.backGroundUpdate(deltaTime);
	int one, two, three, four , five; 
	int h1 = 50; 
	switch (GAMEMode)
	{
	case 0: 
	case 2:
		one = 20; // start
		two = 40;  // game mode
		three = 60; // game level
		five = 60;
		four = 80; // back
		break;
	case 1 : 
		one = 20; // start
		two = 35;  // game mode
		three = 50; // game level
		five = 65;
		four = 80; // back
		break;

	}

	int temp1 = 50; 
	if (GameDifficulty == 1) temp1 = 80;
	if (GAMEMode == 1)
	{
	game_level_button->UPDATEButton(50, three, 1.5, deltaTime, 1, 80, temp1);
	}
	if (LastGAMEMode == 0 ||LastGAMEMode == 1)
	{
		continue_button_setup->UPDATEButton(65, one, 1.5, deltaTime, 1, 80, 80);
		h1 = 35;
	}
	back_button->UPDATEButton(50, four , 1.5, deltaTime, 1, 80, 50);
	gameMode_button->UPDATEButton(50, two, 1.5, deltaTime, 1, 80, 50);
	game_turn_button->UPDATEButton(50, five , 1.5, deltaTime, 1, 80, 80);
	start_button_setup->UPDATEButton(h1, one, 1.5, deltaTime, 1, 80, 80);

	// back button 
	if (back_button->isButtonClicked)
	{
		CurrentPage = Page::Home; 
	}
	// game mode
	int lastGameMode = GAMEMode; 
	if (gameMode_button->isButtonClicked )
	{
		if (GAMEMode == 0) GAMEMode = 1;
		else if (GAMEMode == 1) GAMEMode = 0;
		Game_State::isLeftClick = false;
	}
	if (lastGameMode != GAMEMode)
	{
		std::string m; 
		switch (GAMEMode)
		{
		case 0: m = "PvP"; break; 
		case 1: m = "PvC"; break;
		}
		gameMode_button->text.textInit(fontTheme_GameSetup(theme), m, 512, fontColor_GameSetup(theme));
	}
	// game difficulty 
	int last_level = GameDifficulty; 
	if (game_level_button->isButtonClicked )
	{
		if (GameDifficulty == 0) GameDifficulty = 1; 
		else if (GameDifficulty == 1) GameDifficulty = 2;
		else if (GameDifficulty == 2) GameDifficulty = 0;
		std::cout << "Game difficulty has changed to : " << GameDifficulty << std::endl; 
		Game_State::isLeftClick = false;

	}
	if (last_level != GameDifficulty)
	{
		std::string m; 
		switch (GameDifficulty)
		{
		case 0: m = "Easy"; break; 
		case 1:m = "Medium"; break;
		case 2:m = "Hard"; break;
		}
		game_level_button->text.textInit(fontTheme_GameSetup(theme), m, 512, fontColor_GameSetup(theme));
	}
	// start
	if (start_button_setup->isButtonClicked)
	{
		restart_grid();
		CurrentPage = GameTOstart; 
	}
	// couninue 
	if (continue_button_setup->isButtonClicked)
	{
		CurrentPage = Page::GameTOstart;
	}
	// game trun 
	std::string text_massage;
	int lastTurn = baseTurn;
	if (game_turn_button->isButtonClicked)
	{
		if (baseTurn == 0) baseTurn = 1;
		else baseTurn = 0; 
		Game_State::isLeftClick = false; 
		std::cout << "Game Mode : " << GAMEMode << std::endl;
		std::cout << "Game Turn : " << baseTurn << std::endl;
	}
	
	
	if (GAMEMode == 0)
	{
		if (baseTurn == 0) text_massage = "Player 1";
		else text_massage = "Player 2";
	}
	else
	{
		if (baseTurn == 0) text_massage = "  YOU  ";
		else text_massage = "  BOT  ";
	}
	if (lastGameMode != GAMEMode || lastTurn != baseTurn)
	{
		game_turn_button->text.textInit(fontTheme_GameSetup(theme), text_massage, 512, fontColor_GameSetup(theme));
	}
	
}

void GameSetupController::render()
{
	SDL_RenderClear(Initialize::renderer); 

	background.backGroundRender();

	back_button->RenderButton();
	gameMode_button->RenderButton();
	if(GAMEMode == 1)
	game_level_button->RenderButton();
	game_turn_button->RenderButton();
	start_button_setup->RenderButton();
	if (LastGAMEMode == 1 || LastGAMEMode == 0);
	continue_button_setup->RenderButton();
	SDL_RenderPresent(Initialize::renderer);
}

void GameSetupController::clear()
{
	back_button->clear();
	gameMode_button->clear();
	game_level_button->clear();
	game_turn_button->clear();
	delete back_button;
	delete gameMode_button; 
	delete game_level_button;
	delete game_turn_button;
}
