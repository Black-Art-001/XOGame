#include "mapManager.h"
#include <SDL.h>
#include "TextureManager.h"
#include <string>
#include "XOGrid.h"
#include "Initialize.h"
#include "state.h"
#include "settings.h"
#include <iostream>
#include "soundManager.h"

using namespace Game_State;

sound H; 
sound C;

mapManager gridMap;

void mapManager::GridMap(std::string file_path_X, std::string file_path_O , std::string file_path_G , std::string file_path_B1 , std::string file_path_B2)
{
	x = texture.textureManager(file_path_X);
	o = texture.textureManager(file_path_O);
	Table = texture.textureManager(file_path_G);
	baseCell = texture.textureManager(file_path_B1);
	C.create_sound("sounds/button-35.wav");
	H.create_sound("sounds/button-19.wav");
	loadGridMap();
}


void mapManager::loadGridMap( )
{
	for (int line = 0; line < 3; line++)
	{
		for (int cell = 0; cell < 3; cell++)
		{
			Grid[line][cell] = XOGrid::Grid[0][line + 1][cell + 1];
		}
	}
}

void mapManager::updateMap(float dT , int symbol )
{
	//height = window.height * 20 / 100; 
	//width = window.width * 20 / 100;
	float Ratio = window.width / static_cast<float>(window.height);
	if (Ratio >= 1)
	{
		height = width = window.height * 20 / 100;
	}
	else
	{
		width = height = window.width * 20 / 100;
	}
	gap = width / 5;

	dst.x = 0;
	dst.y = 0;
	dst.w = width;
	dst.h = height;
	int totalX = 3 * width + 2 * gap;
	int totalY = 3 * height + 2 * gap;

	temp = (window.width - totalX) / 2;
	dst.x = temp;
	dst.y = (window.height - totalY) / 2;
	
	// first animation for table 
	static float smoothScaling = 0; 
	const float targetScaling = 1;
	int speed = 250; 
	smoothScaling += (targetScaling - smoothScaling) * dT * speed;
	
	table.w = (totalX + gap)*smoothScaling;
	table.h = (totalY + gap)*smoothScaling;

	table.x = (window.width - table.w) / 2;
	table.y = (window.height - table.h) / 2;
	// for Hover :
	isHover = false;
	Cell.x = dst.x;
	Cell.y = dst.y;
	Cell.w = width;
	Cell.h = height; 
	int counter_line = 0;
	int counter_cell = 0;
	
	for (int line = 0; line < 3; line++)
	{
		isFound = false; 
		Cell.x = temp;
		for (int cell = 0; cell < 3; cell++)
		{
			isHover =  (mouse.x > Cell.x && mouse.x < Cell.x + dst.w && mouse.y > Cell.y && mouse.y < Cell.y + dst.h);
			if (isHover)
			{
				isFound = true; 
				break;
			}
			
			Cell.x += width;
			Cell.x += gap;// for Grid
			counter_cell++;

		}
		if (isFound)
		{
			break; 
		}
		counter_cell = 0; 
		Cell.y += height;
		Cell.y += gap; // for Grid
		counter_line++;
	}
	 // select by click ! 
	if (isFound && isLeftClick && (Grid[counter_line][counter_cell] == 0))
	{

		C.play_sound(1);
		XOGrid::Grid[0][counter_line + 1][counter_cell +1] = symbol; 
		Settings::turn++; 
		isLeftClick = false;
		if (symbol == P1symbol)
		{
			XOGrid::Grid[0][counter_line+1][0]++;
			XOGrid::Grid[0][0][counter_cell+1]++;
			if (counter_cell == counter_line)
				XOGrid::Grid[0][0][0]++;
			if (2  == counter_line + counter_cell)
				XOGrid::Grid[0][4][0]++;
		}
		else if (symbol == P2symbol)
		{
			XOGrid::Grid[0][counter_line+1][4]++;
			XOGrid::Grid[0][4][counter_cell+1]++;
			if (counter_cell == counter_line)
				XOGrid::Grid[0][4][4]++;
			if (counter_line+ counter_cell ==2 )
				XOGrid::Grid[0][0][4]++;
		}
		update_index();
		XOGrid::Grid[1][counter_line + 1][counter_cell + 1] = Settings::gameIndex ++; 	
	}
	loadGridMap();
	float targetSelector = 1; 
	
	if (isFound && (targetCell.x != Cell.x || targetCell.y != Cell.y))
	{
		H.play_sound(1);
		smoothSelector = 0;
		isFounded = true;
	}
	targetCell = Cell;
	smoothSelector += (targetSelector - smoothSelector) * dT * 300;
	
	Cell.w = width*smoothSelector;
	Cell.h = height*smoothSelector;
	
	Cell.x += (width - Cell.w) / 2;
	Cell.y += (height - Cell.h) / 2;
	
}

void mapManager::RenderMap()
{
	
	SDL_RenderCopy(Initialize::renderer, Table, NULL, &table);
	if (isFound) {
		SDL_RenderCopy(Initialize::renderer, baseCell, NULL, &Cell); 
	}
	
	for (int line = 0; line < 3; line++)
	{
		dst.x = temp;
		for (int cell = 0; cell < 3; cell++)
		{
			if( Grid[line][cell] == P1symbol)
			{
				SDL_RenderCopy(Initialize::renderer, x, NULL, &dst);
			}
			else if (Grid[line][cell] == P2symbol)
			{
				SDL_RenderCopy(Initialize::renderer, o, NULL, &dst);
			}
			dst.x += width; 
			dst.x += gap;// for Grid
		}
		dst.y += height; 
		dst.y += gap; // for Grid
	}
}

void mapManager::undo(int index)
{
	for(int i = 1 ; i <= 3 ; i ++)
		for (int j = 1; j <= 3; j++)
		{
			if (XOGrid::Grid[1][i][j] == index)
			{
				control(XOGrid::Grid[0][i][j] , i, j, -1);
				XOGrid::Grid[0][i][j] = NOsymbol;
			}
		}
	loadGridMap();
}

bool mapManager::redo(int & index)
{
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if (XOGrid::Grid[1][i][j] == index)
			{
				if (Settings::turn % 2 == 0)
				{
					XOGrid::Grid[0][i][j] = P1symbol;
				}
				else
				{
					XOGrid::Grid[0][i][j] = P2symbol;
				}
				control(XOGrid::Grid[0][i][j], i, j, +1);
				loadGridMap();
				 
				return true; 
			}
		}
	return false; 
}

void mapManager::update_index()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (XOGrid::Grid[1][i][j] >= Settings::gameIndex)
			{
				XOGrid::Grid[1][i][j] = 0;
			}
		}
	}
}

void mapManager::control(int symbol , int l, int c , int add)
{
	if (symbol == NOsymbol) return; 

	if (symbol == P1symbol)
	{
		XOGrid::Grid[0][l][0] += add;
		XOGrid::Grid[0][0][c] += add;
		if (l == c)
		{
			XOGrid::Grid[0][0][0] += add;
		}
		if (l + c == 4)
		{
			XOGrid::Grid[0][4][0] += add;
		}
	}
	else
	{
		XOGrid::Grid[0][l][4] += add;
		XOGrid::Grid[0][4][c] += add;
		if (l == c)
		{
			XOGrid::Grid[0][4][4] += add;
		}
		if (l + c == 4)
		{
			XOGrid::Grid[0][0][4] += add;
		}
	}
}

void mapManager::clear()
{
	C.Free();
	H.Free();
}
