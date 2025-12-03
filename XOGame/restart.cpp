#include "restart.h"
#include "XOGrid.h"
#include "settings.h"


void restart_grid()
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
	Settings::turn = Settings::baseTurn;
	Settings::gameIndex = 0; 
}
