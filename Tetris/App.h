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
		bool vSync,
		int windowWidth,
		int windowHeight,
		App::Location startLocation);
	~App();

	SDL_Renderer* getRenderer() const;
	App::Location getCurrentLocation() const;
	App::Location getPreviousLocation() const;
	std::string getVersion() const;
	float getDeltaTime() const;
	int getLastFrameTime() const;
	int getFps() const;
	int getWindowWidth() const;
	int getWindowHeight() const;
	bool getVSync() const;
	bool getRunning() const;

	void setCurrentLocation(const App::Location& value);
	void setPreviousLocation(const App::Location& value);
	void setDeltaTime(const float& value);
	void setLastFrameTime(const int& value);
	void setFps(const int& value);
	void setVSync(const bool& value);
	void setRunning(const bool& value);

private:

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	App::Location currentLocation;
	App::Location previousLocation;
	std::string version;
	float deltaTime = 1;
	int lastFrameTime = 0;
	int fps;
	int windowWidth;
	int windowHeight;
	bool vSync;
	bool isRunning = false;
};

#endif
