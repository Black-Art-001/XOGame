# pragma once

struct Setting_Controller
{
	bool Something_Changed = false; 
	bool ButtonNOTUpdated = true; 
	bool isNeedToRestart = false;
	int timer = 0; 
	void Init(); 

	void update(float deltaTime);

	void render();

	void clear(); 
};