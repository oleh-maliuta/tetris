#pragma once

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

class App
{
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
public:
	enum Location {
		MAIN_MENU,
		GAME_PROCESS,
		GAME_OVER,
		SETTINGS
	};

	static const int APP_WINDOW_WIDTH = 440;
	static const int APP_WINDOW_HEIGHT = 640;
	bool isRunning = false;
	int fps = 60;
	int lastFrameTime = 0;
	Location currentLocation = MAIN_MENU;
	App();
	SDL_Renderer* getRenderer();
	void destroy();
};

