#pragma once

struct GameSetupController
{
	bool isPVPMod = true;
	void Init();
	void update(float deltaTime);
	void render();
	void clear();
};