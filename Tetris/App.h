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
public:

	enum Location {
		MAIN_MENU,
		SETTINGS
	};

	App(
		std::string version,
		int fps,
		int windowWidth,
		int windowHeight);
	~App();

	SDL_Renderer* getRenderer() const;
	App::Location getCurrentLocation() const;
	App::Location getPreviousLocation() const;
	std::string getVersion() const;
	bool getRunning() const;
	int getLastFrameTime() const;
	int getFps() const;
	int getWindowWidth() const;
	int getWindowHeight() const;
	float getDeltaTime() const;

	void setCurrentLocation(App::Location value);
	void setPreviousLocation(App::Location value);
	void setRunning(bool value);
	void setLastFrameTime(int value);
	void setFps(int value);
	void setDeltaTime(float value);

private:

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	App::Location currentLocation = MAIN_MENU;
	App::Location previousLocation = MAIN_MENU;
	std::string version;
	bool isRunning = false;
	int lastFrameTime = 0;
	int fps;
	int windowWidth;
	int windowHeight;
	float deltaTime = 1;
};

#endif
