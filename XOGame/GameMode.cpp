#include "GameMode.h"
#include <iostream>
#include "settings.h"
#include "PvP.h"
#include "EndPage.h"
#include "PvC.h"
#define level Settings::GameDifficulty
#define MODE Settings::GAMEMode

PvPPage* page_for_pvpmode;
PvCPage* page_for_pvcmode;
void Mode::GameModeChecker()
{
	page_for_pvpmode = new PvPPage; 
	page_for_pvcmode = new PvCPage;

	while(Settings::CurrentPage == Settings::Page::GameTOstart)
	if (MODE == 0) // PvP
	{
		page_for_pvpmode->PvpPage();
	}
	else if (MODE == 1) // PvC
	{
		page_for_pvcmode->PvcPage();
	}
	else // End page
	{
		gameEndPage.GameENDPage();
	}
	delete page_for_pvpmode;
	delete page_for_pvcmode;

}
