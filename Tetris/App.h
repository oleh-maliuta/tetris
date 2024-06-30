#pragma once

#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

class App
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
public:
	enum Location {
		MAIN_MENU,
		SETTINGS
	};

	static const int APP_WINDOW_WIDTH = 440;
	static const int APP_WINDOW_HEIGHT = 640;
	bool isRunning = false;
	int fps = 60;
	int lastFrameTime = 0;
	Location currentLocation = MAIN_MENU;
	Location previousLocation = MAIN_MENU;
	App();
	~App();
	SDL_Renderer* getRenderer();
};

#endif
