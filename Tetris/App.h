#pragma once

#ifndef APP_H
#define APP_H

class Page;

#include <stdio.h>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "./pages/Page.h"

class App
{
public:

	App(
		const int& windowWidth,
		const int& windowHeight);
	~App();

	template<class T>
	void usePage(const std::string& key);

	void changePage(const std::string& key);
	void run(const std::string& startPage);

	SDL_Renderer* getRenderer() const;
	std::string getVersion() const;
	float getDeltaTime() const;
	int getLastFrameTime() const;
	int getFps() const;
	int getWindowWidth() const;
	int getWindowHeight() const;
	bool getVSync() const;
	bool getRunning() const;

	void setFps(const int& value);
	void setVSync(const bool& value);
	void setRunning(const bool& value);

private:

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	std::map<std::string, Page*> pages;
	std::string currentLocation;
	std::string previousLocation;
	std::string version;
	float deltaTime = 1;
	int lastFrameTime = 0;
	int fps;
	int windowWidth;
	int windowHeight;
	bool vSync;
	bool isRunning = false;

	static bool getAppSettings(std::unordered_map<std::string, std::string>& data);
	static bool saveAppSettings(const std::unordered_map<std::string, std::string>& data);
};

template<class T>
void App::usePage(const std::string& key) {
	static_assert(std::is_base_of<Page, T>::value, "The class must be derived from Page class.");

	const auto it = this->pages.find(key);

	if (it != this->pages.end()) {
		delete it->second;
	}

	this->pages[key] = new T(this);
}

#endif
