#pragma once
#include<string>
#include<SDL.h>

struct theme_path
{
	std::string file_path;
	int n; 
	int s;
};

theme_path backGroundTheme(int x);
theme_path backGroundTheme_Setting(int x);
theme_path backGroundTheme_GameSetup(int x);
theme_path backGroundTheme_Game(int x);
theme_path backGroundTheme_EndPage(int x);

std::string buttonTheme(int);
std::string buttonTheme_Setting(int x);
std::string buttonTheme_GameSetup(int x);
std::string buttonTheme_Game(int x);

std::string fontTheme(int); 
std::string fontTheme_Setting(int x);
std::string fontTheme_GameSetup(int x);
std::string fontTheme_Game(int x);

std::string MassagefontTheme(int x);
std::string MassagefontTheme_Setting(int x);
std::string MassagefontTheme_GameSetup(int x);
std::string MassagefontTheme_Game(int x);

SDL_Color fontColor(int); 
SDL_Color fontMassageColor(int);
SDL_Color fontColor_GameSetup(int);
SDL_Color fontColor_Game(int);

SDL_Color fontColor_Setting(int x);
SDL_Color fontMassageColor_Setting(int x);
SDL_Color fontMassageColor_GameSetup(int x);
SDL_Color fontMassageColor_Game(int x);


SDL_Color fontCustomizeColor(int r, int g, int b); 

std::string symbol1(int x);
std::string symbol2(int x);
std::string gridImage(int x);

std::string baseGrid1(int x);
std::string baseGrid2(int x);


std::string soundHH(int x);
std::string soundHC(int x);

std::string soundGsH(int x);
std::string soundGsC(int x);

std::string soundSH(int x);
std::string soundSC(int x);

std::string soundGH(int x);
std::string soundGC(int x);

std::string soundEH(int x);
std::string soundEC(int x);