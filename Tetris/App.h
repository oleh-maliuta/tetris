#pragma once

#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

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

	const char* version;
	int windowWidth;
	int windowHeight;
	bool isRunning = false;
	int fps = 60;
	int lastFrameTime = 0;
	float deltaTime = 1;
	Location currentLocation = MAIN_MENU;
	Location previousLocation = MAIN_MENU;
	App(
		const char* version,
		int windowWidth,
		int windowHeight);
	~App();
	SDL_Renderer* getRenderer();
};

#endif
