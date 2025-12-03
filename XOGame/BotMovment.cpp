#include "BotMovment.h"
#include "XOGrid.h"
#include "settings.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>
 BotMovment::oneCell cell; 
	


void BotMovment::BotMove()
{
	// rendom setup
	if (srandInit)
	{
		srand(unsigned(time(NULL)));
		srandInit = false;
	}
	// attack 
	if (attack())
	{
		Update_Storge(cell.line, cell.column );
	}
	// defender
	else if (defend())
	{ 
		Update_Storge(cell.line, cell.column );
	}
	// Game movment 
	else if (Settings::GameDifficulty == 0)
	{
		if (RandomMove())
		{
			Update_Storge(cell.line, cell.column );
		}
	}
	else if (Settings::GameDifficulty == 1)
	{
		if (AiBaseValue()) {
			Update_Storge(cell.line, cell.column );
		}
	}
	else if(Settings::GameDifficulty == 2)
	{
		if (AdvanceAI())
		{
			Update_Storge(cell.line, cell.column );
		}
	}
}

void BotMovment::Update_Storge(int l , int c)
{
	if(XOGrid::Grid[0][l][c] == P2symbol)
	{
		XOGrid::Grid[1][l][c] = Settings::gameIndex++;
		XOGrid::Grid[0][l][4]++;
		XOGrid::Grid[0][4][c]++;
		if (l == c) {
			XOGrid::Grid[0][4][4]++;
		}
		if (l + c == 4)
		{
			XOGrid::Grid[0][0][4]++;
		}
	}
}

bool BotMovment::CounterCell(int symbol)
{
	int target = symbol == P1symbol ? 0 : 4;
	int oppsite = 4 - target ;
	
	// check lines 
	for (int line = 1; line < 4; line++)
	{
		if (XOGrid::Grid[0][line][target] == 2 && XOGrid::Grid[0][line][oppsite] == 0)
		{
				cell.line = line;
				// for finding column 
				for (int column = 1; column < 4; column++)
				{
					if (XOGrid::Grid[0][line][column] == 0)
					{
						cell.column = column;
						return true;
					}
				}
		}
	}
	// check column
	for (int column = 1 ; column < 4; column++)
	{
		if (XOGrid::Grid[0][target][column] == 2 && XOGrid::Grid[0][oppsite][column] == 0)
		{
			
				cell.column = column;
				// findding line 
				for (int line = 1; line < 4; line++)
				{
					if (XOGrid::Grid[0][line][column] == 0)
					{
						cell.line = line;
						return true;
					}
				}
			
		}
	}
	// check diagonals
	if (XOGrid::Grid[0][target][target] == 2 )
	{
		for (int i = 1; i < 4; i++)
		{
			if (XOGrid::Grid[0][i][i] == NOsymbol)
			{
				cell.column = cell.line = i;
				return true;
			}
		}
		
	}
	if (XOGrid::Grid[0][oppsite][target] == 2 )
	{
		for (int i = 1; i < 4; i++)
		{
			if (XOGrid::Grid[0][i][4 - i] == NOsymbol)
			{
				cell.column = 4 - i;
				cell.line = i;
				return true;
			}
		}
	}
	return false;	
}

bool BotMovment::attack()
{
	std::cout << "[Attack] Offense system activated .\n";
	if(CounterCell(P2symbol)) // set our value in critical cell 
	{
		std::cout << "[Attack] Opportunity detected ! Attempting to win .\n";
		XOGrid::Grid[0][cell.line][cell.column] = P2symbol;
		return true;
	}
	std::cout << "[Attack] No winning move available . Offense idle .\n";
	return false;
}

bool BotMovment::defend()
{
	std::cout << "[Defend] Defense system activated.\n";
	if (CounterCell(P1symbol))
	{
		std::cout << "[Defend] Threat detected! Blocking player move.\n";
		XOGrid::Grid[0][cell.line][cell.column] = P2symbol;
		return true;
	}
	std::cout << "[Defend] No immediate threat detected. Defense idle.\n";
	return false;
}

bool BotMovment::RandomMove()
{
	std::cout << "[Random] No threat or opportunity detected. Choosing random move.\n";

	int randomNumber = rand() % 10;
	// because in our grid is 5x5 and the game grid start from 1,1 to 3,3 ! result : we add one 
	
	int counter = 0; 
	do {
		int line = (randomNumber / 3) ;
		if (line == 0) line = 1;
		int column = (randomNumber % 3) + 1;
		if (XOGrid::Grid[0][line][column] == NOsymbol)
		{
			XOGrid::Grid[0][line][column] = P2symbol;
			cell.line = line;
			cell.column = column;
			std::cout << "[Random] Random move executed at (" << cell.line << ", " << cell.column << ").\n";

			return true;
		}
		randomNumber++; 
		if (randomNumber > 9) randomNumber = 0; 
	} while (++counter < 9);
	return false; 
	std::cout << "[Random] No empty cells found . Move skipped .\n";
}

bool BotMovment::AiBaseValue()
{
	std::cout << "[Strategy] Evaluating bord for optimal Move.\n";
	for(int v = 3 ; v > 0 ; v--)
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (value[i][j] == v)
			{
				if(XOGrid::Grid[0][i+1][j+1] == NOsymbol)
				{
					cell.line = i + 1;
					cell.column = j + 1;
					XOGrid::Grid[0][i + 1][j + 1] = P2symbol;
					std::cout << "[Strategy] Strategic move placed at [" << cell.line << ", " << cell.column << "]\n";
					return true;
				}
			}
		}
	}
	std::cout << "[Strategy] No strategic move found. Falling back.\n";
	return false;
}

namespace special_situations 
{
	bool s1[3][3] = {
		{1 , 0 , 0} ,
		{0 , 0 , 0} ,
		{0 , 0 , 1}
	};
	bool s2[3][3] = {
		{0 , 0 , 1} ,
		{0 , 0 , 0} ,
		{1 , 0 , 0}
	};

}

bool BotMovment::AdvanceAI()
{
	std::cout << "ai started\n";

	// values 
	int values[3][3] = {
		{2 , 1 , 2} ,
		{1 , 3 , 1} ,
		{2 , 1 , 2}
	};

	// special situation
	if (special_move()) return true; 
	std::cout << "ai scape of special move\n";
	// increase value 
	const int enemyWin_destroyer_score = 8;
	const int weCanWin = 10; 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (XOGrid::Grid[0][i + 1][j + 1] == NOsymbol)
			{
				// line ! 
				if (XOGrid::Grid[0][i + 1][0] == 0) 
				{
					values[i][j] += XOGrid::Grid[0][i + 1][4] * weCanWin;
				}
				else if (XOGrid::Grid[0][i + 1][4] == 0)
				{
					values[i][j] += XOGrid::Grid[0][i + 1][0] * enemyWin_destroyer_score;
				}
				// diagonal  
				if (XOGrid::Grid[0][0][0] == 0 && i == j)
				{
					values[i][j] += XOGrid::Grid[0][4][4] * weCanWin;
				}
				else if (XOGrid::Grid[0][4][4] == 0 && i == j)
				{
					values[i][j] += XOGrid::Grid[0][0][0] * enemyWin_destroyer_score;
				}
				// anti diagonal 
				if (XOGrid::Grid[0][4][0] == 0 && i + j == 2) {
					values[i][j] += XOGrid::Grid[0][0][4] * weCanWin;
				}
				else if (XOGrid::Grid[0][0][4] == 0 && i + j == 2)
				{
					values[i][j] += XOGrid::Grid[0][4][0] * enemyWin_destroyer_score;
				}
				// column ! 
				if (XOGrid::Grid[0][0][j + 1] == 0) 
				{
					values[i][j] += XOGrid::Grid[0][4][j + 1] * weCanWin;
				}
				else if (XOGrid::Grid[0][4][j + 1] == 0)
				{
					values[i][j] += XOGrid::Grid[0][0][j + 1] * enemyWin_destroyer_score;
				}
			}
			else
			{
				values[i][j] = 0; 
			}
		}
	}

	std::cout << "ai set values move\n";

	// debuger
	std::cout <<  "value table\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << values[i][j] << '\n';
		}
		std::cout << std::endl;
	}

	std::cout << "ai pritn debug table move\n";

	// finding biggest value
	int biggest = 0 ; 
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (values[i][j] > biggest)
				{
					cell.column = j + 1;
					cell.line = i + 1; 
					biggest = values[i][j]; 
				}
			}
		}
		XOGrid::Grid[0][cell.line][cell.column] = P2symbol;
		return true;
	std::cout << "ai does not select any cell !\n"; 
	return false; 

}

bool BotMovment::special_move()
{
	if(isSame(special_situations::s1) || isSame(special_situations::s2))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (XOGrid::Grid[0][i + 1][j + 1] == NOsymbol && (i + j == 1 || i + j == 3))
				{
					XOGrid::Grid[0][i + 1][j + 1] = P2symbol;
					cell.line = i + 1;
					cell.column = j + 1; 
					return true;
				}
			}
		}
	}

	return false; 
}

bool BotMovment::isSame(bool special[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (special[i][j] != (XOGrid::Grid[0][i + 1][j + 1] == P1symbol))
			{
				return false;
			}
		}
	}
	return true;
}

