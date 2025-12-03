#include "theme.h"
#include "settings.h"

theme_path theme_p; 

theme_path backGroundTheme(int x)
{
    switch (x)
    {
    case 0: theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back1.jpg";  break;
    case 1:  theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back2.jpg";  break;
    default: theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back2.jpg"; break;
    }
    return theme_p; 
}
theme_path backGroundTheme_Setting(int x)
{
    switch (x)
    {
    case 0: theme_p.n = 1; theme_p.s = 1; theme_p.file_path = "assets/backS1.jpg";  break;
    case 1:  theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/backS2.jpg";  break;
    default: theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back2S.jpg"; break;
    }
    return theme_p;

}
theme_path backGroundTheme_GameSetup(int x)
{
        switch (x)
        {
        case 0: theme_p.n = 1; theme_p.s = 1; theme_p.file_path = "assets/back1GS.jpg";  break;
        case 1:  theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back2GS.jpg";  break;
        default: theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back2S.jpg"; break;
        }
        return theme_p;
}
theme_path backGroundTheme_Game(int x)
{
    switch (x)
    {
    case 0: theme_p.n = 1; theme_p.s = 1; theme_p.file_path = "assets/back1G.jpg";  break;
    case 1:  theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back2G.jpg";  break;
    default: theme_p.n = 1; theme_p.s = 0; theme_p.file_path = "assets/back1.jpg"; break;
    }
    return theme_p;
}
theme_path backGroundTheme_EndPage(int situation)
{
    switch (situation)
    {
    case Settings::situation::even:
        theme_p.file_path = "assets/evenBack.jpg";
        break;
    case Settings::situation::loss:
        theme_p.file_path = "assets/lossBack.jpg";
        break;
    case Settings::situation::Win:
        if (Settings::LastGAMEMode == 0)
        {
            theme_p.file_path = "assets/winBack.jpg";
        }
        else
        {
            theme_p.file_path = "assets/winBack.jpg";
        }
        break;
    case Settings::situation::Win2:
        theme_p.file_path = "assets/winBack.jpg";
        break;
    }
    theme_p.n = 1; 
    theme_p.s = 1;

    return theme_p; 
}

std::string buttonTheme(int x )
{
    switch (x)
    {
    case 0: return "assets/button_green_1.png";
    case 1: return "assets/button_green_2.png";
    default:
        break;
    }
}
std::string buttonTheme_Setting(int x)
{
    switch (x)
    {
    case 0: return "assets/button_yellow_1.png";
    case 1: return "assets/button_greenDarken_1.png";
    default:
        break;
    }
}
std::string buttonTheme_GameSetup(int x)
{
    switch (x)
    {
    case 0: return "assets/button_blue_1.png";
    case 1: return "assets/button_green_2.png";
    default:
        break;
    }
}
std::string buttonTheme_Game(int x)
{
    switch (x)
    {
    case 0: return "assets/button_green_1.png";
    case 1: return "assets/button_green_2.png";
    default:
        break;
    }
}

std::string fontTheme(int x )
{
    switch (x)
    {
    case 0: return "assets/arial.ttf";
    case 1: return "assets/arial.ttf";
    }
}
std::string fontTheme_Setting(int x)
{
    switch (x)
    {
    case 0: return "assets/arial.ttf";
    case 1: return "assets/arial.ttf";
    default:
        break;
    }
}
std::string fontTheme_GameSetup(int x)
{
    switch (x)
    {
    case 0: return "assets/arial.ttf";
    case 1: return "assets/arial.ttf";
    default:
        break;
    }
}
std::string fontTheme_Game(int x)
{
    switch (x)
    {
    case 0: return "assets/arial.ttf";
    case 1: return "assets/arial.ttf";
    
    }
}

std::string MassagefontTheme(int x)
{
    switch (x)
    {
    case 0: return "assets/techno_hideo_bold.ttf";
    case 1: return "assets/techno_hideo_bold.ttf";
    }
}
std::string MassagefontTheme_Setting(int x)
{
    switch (x)
    {
    case 0: return "assets/techno_hideo_bold.ttf";
    case 1: return "assets/techno_hideo_bold.ttf";
    default:
        break;
    }
}
std::string MassagefontTheme_GameSetup(int x)
{
    switch (x)
    {
    case 0: return "assets/techno_hideo_bold.ttf";
    case 1: return "assets/techno_hideo_bold.ttf";
    default:
        break;
    }
}
std::string MassagefontTheme_Game(int x)
{
    switch (x)
    {
    case 0: return "assets/techno_hideo_bold.ttf";
    case 1: return "assets/techno_hideo_bold.ttf";

    }
}

SDL_Color fontColor(int x )
{
    SDL_Color color; 
    switch (x)
    {
    case 0:
        color.r = 25;
        color.g = 10;
        color.b = 50; 
        color.a = 255; 
        break; 
    case 1 : 
        color.r = 200;
        color.g = 250;
        color.b = 250;
        color.a = 255;
        break;
    }
    return color;
}
SDL_Color fontColor_GameSetup(int x)
{
    SDL_Color c;
    switch (x)
    {
    case 0:
        c.r = 10;
        c.g = 10;
        c.b = 10;
        c.a = 255;
        break;
    case 1:
        c.r = 200;
        c.g = 230;
        c.b = 255;
        c.a = 255;
        break;
    }
    return c;
}
SDL_Color fontColor_Game(int x)
{
    SDL_Color c;
    switch (x)
    {
    case 0:
        c.r = 100;
        c.g = 200;
        c.b = 200;
        c.a = 255;
        break;
    case 1:
        c.r = 200;
        c.g = 250;
        c.b = 20;
        c.a = 255;
        break;
    }
    return c;
}
SDL_Color fontColor_Setting(int x)
{
    SDL_Color color;
    switch (x)
    {
    case 0:
        color.r = 40;
        color.g = 50;
        color.b = 50;
        color.a = 255; 
        break;
    case 1 : 
        color.r = 180;
        color.g = 20;
        color.b = 40;
        color.a = 255;
        break;
    default:
        break;
    }
    return color;
}

SDL_Color fontMassageColor(int x )
{
    SDL_Color c;
    switch (x)
    {
    case 0 : 
        c.r = 255; 
        c.g = 200; 
        c.b = 150;
        c.a = 255;
        break; 
    case 1 : 
        c.r = 220;
        c.g = 255;
        c.b = 255;
        c.a = 255;
        break;
    }
    return c;
}
SDL_Color fontMassageColor_Setting(int x)
{
    SDL_Color c;
    switch (x)
    {
    case 0:
        c.r = 250;
        c.g = 240;
        c.b = 100;
        c.a = 255;
        break;
    case 1 : 
        c.r = 210;
        c.g = 50;
        c.b = 10;
        c.a = 255;
        break;
    }
    return c;
}
SDL_Color fontMassageColor_GameSetup(int x)
{
    SDL_Color c;
    switch (x)
    {
    case 0:
        c.r = 250;
        c.g = 240;
        c.b = 50;
        c.a = 255;
        break;
    case 1:
        c.r = 50;
        c.g = 200;
        c.b = 250;
        c.a = 255;
        break;
    }
    return c;
}
SDL_Color fontMassageColor_Game(int x)
{
    SDL_Color c;
    switch (x)
    {
    case 0:
        c.r = 100;
        c.g = 200;
        c.b = 200;
        c.a = 255;
        break;
    case 1:
        c.r = 250;
        c.g = 250;
        c.b = 100;
        c.a = 255;
        break;
    }
    return c;
}


SDL_Color fontCustomizeColor(int r, int g, int b)
{
    SDL_Color color; 
    color.r = r; 
    color.g = g;
    color.b = b;
    return color;
}

std::string symbol1(int x)
{
    switch (x)
    {
    case 0: return "assets/cross1.png";
    case 1:return "assets/cross2.png";
    }
}

std::string symbol2(int x)
{
    switch (x)
    {
    case 0: return "assets/circle1.png";
    case 1:return "assets/circle2.png";
    }
}

std::string gridImage(int x)
{
    switch (x)
    {
    case 0: return "assets/Grid.png";
    case 1:return "assets/Grid.png";
    }
}

std::string baseGrid1(int x)
{
    switch (x)
    {
    case 0: return "assets/baseGrid1.png";
    case 1:return "assets/baseGrid2.png";
    }
}

std::string baseGrid2(int x)
{
    switch (x)
    {
    case 0: return "assets/baseGrid2.png";
    case 1:return "assets/baseGrid2.png";
    }
}

std::string soundHH(int x)
{
    switch (x)
    {
    case 0: return "sounds/button-27.wav";
    case 1:return "sounds/button-27.wav";
    }
}

std::string soundHC(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-30.wav";
    }
}

std::string soundGsH(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-27.wav";
    }
}

std::string soundGsC(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-30.wav";
    }
}

std::string soundSH(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-27.wav";
    }
}

std::string soundSC(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-30.wav";
    }
}

std::string soundGH(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-27.wav";
    }
}

std::string soundGC(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-30.wav";
    }
}

std::string soundEH(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-27.wav";
    }
}

std::string soundEC(int x)
{
    switch (x)
    {
    default:
        return "sounds/button-30.wav";
    }
}

