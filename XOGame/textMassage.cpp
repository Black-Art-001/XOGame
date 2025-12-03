#include "textMassage.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Initialize.h"
#include "state.h"
#include "iostream"

SDL_Texture* Massage::textInit(std::string file_path, std::string massage, int size, SDL_Color color )
{
    TTF_Font* font = TTF_OpenFont(file_path.c_str(), size);
    temp = TTF_RenderText_Solid(font, massage.c_str(), color);
    texture = SDL_CreateTextureFromSurface(Initialize::renderer, temp);
    SDL_QueryTexture(texture, NULL, NULL, &width, &height); 
    SDL_FreeSurface(temp);
    return texture; 

}

void Massage::textCreator(int x, int y, int w, int h , float size)
{
    if (h == setRealH)
    {
        h = height; 
    }
    if (w == setRealW)
    {
        w = width; 
    }
    float scaling = 1; 
    if (Game_State::window.height * Game_State::window.width > 800 * 640)
    {
        scaling = 1.5;
    }
    else if (Game_State::window.height * Game_State::window.width > 1280 * 720)
    {
        scaling = 2; 
    }

    scaling *= (size / 10);

    dst.x = Game_State::window.width * x / 100;
    dst.y = Game_State::window.height * y / 100;
    dst.w = w * scaling; 
    dst.h = h * scaling; 
    dst.x -= (dst.w / 2);
    dst.y -= (dst.h / 2);
}
 
void Massage::textRender()
{
    SDL_RenderCopy(Initialize::renderer, texture, NULL, &dst);
}

void Massage::clear()
{
    //delete temp; 
    //delete texture;
}
