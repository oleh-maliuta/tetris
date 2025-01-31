#pragma once

#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "./pages/Page.h"

namespace Tetris
{
	class Page;

	/// <summary>
	/// Represents an application that runs using SDL library.
	/// </summary>
	class Application
	{
	public:

		Application(
			const int& windowWidth,
			const int& windowHeight);
		~Application();

		template<class T>
		void usePage(const std::string& key);

		void changePage(const std::string& key);
		void restartPage();
		void run(const std::string& startPage);

		SDL_Renderer* getRenderer() const;
		std::string getVersion() const;
		float getDeltaTime() const;
		int getLastFrameTime() const;
		int getFps() const;
		int getWindowWidth() const;
		int getWindowHeight() const;
		bool getVSync() const;
		bool getIsRunning() const;

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
		bool isRestartRequired = false;
		bool isRunning = false;

		static bool getAppSettings(std::unordered_map<std::string, std::string>& data);
		static bool saveAppSettings(const std::unordered_map<std::string, std::string>& data);
	};

	template<class T>
	void Tetris::Application::usePage(
		const std::string& key)
	{
		if (!std::is_base_of<Page, T>::value) {
			return;
		}

		const auto it = this->pages.find(key);

		if (it != this->pages.end()) {
			delete it->second;
		}

		this->pages[key] = new T(this);
	}
}

#endif
