#pragma once



struct BotMovment
{
	bool srandInit = true;

	int value[3][3] = {
		{2 , 1 , 2} ,
		{1 , 3 , 1} ,
		{2 , 1 , 2}
	};
	
	struct oneCell
	{
		int line; 
		int column;
	};
	enum special_moveMent {
		fork , lastWay
	};
	int temp = -1 ; 

	void BotMove();
	void Update_Storge(int line , int column);
	bool CounterCell(int symbol );
	bool attack();
	bool defend();
	bool RandomMove();// easy
	bool AiBaseValue(); // meduime 
	bool AdvanceAI(); // hard
	bool special_move();
	bool isSame(bool[][3]);
};