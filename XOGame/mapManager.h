#pragma once
#include<SDL.h>
#include<string>


struct mapManager
{
	float smoothSelector = 0; 
	int Grid[3][3];
	SDL_Texture* x;
	SDL_Texture* o;
	SDL_Texture* Table;
	
	SDL_Texture* baseCell;
	SDL_Rect Cell; 
	SDL_Rect targetCell;
	bool isFound; 
	bool isFounded = false; 
	SDL_Rect dst; 
	bool isHover;
	
	int width;
	int height;
	int temp; 
	int gap;
	SDL_Rect table;

	void GridMap(std::string file_path_X_symbol , std::string file_path_O_symbol, std::string file_path_Grid , std::string file_path_BaseGrid1 , std::string file_path_BaseGrid2);
	void loadGridMap();
	void updateMap(float deltTime , int symbol );
	void RenderMap();
	bool redo(int &index); 
	void undo(int  index);
	void update_index();
	void control(int symbol , int l , int c , int add);
	void clear(); 
};
extern mapManager gridMap;