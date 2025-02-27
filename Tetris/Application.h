#pragma once

#ifndef TETRIS__APPLICATION__H
#define TETRIS__APPLICATION__H

#include <stdio.h>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
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

		const std::string VERSION = "0.10.0";

		Application(
			const int& windowWidth,
			const int& windowHeight);
		~Application();

		template<class T>
		void usePage(const std::string& key);

		void changePage(const std::string& key);
		void restartPage();
		void run(const std::string& startPage);

		void haltSound();
		void pauseMusic();
		void resumeMusic();
		void haltMusic();

		SDL_Renderer* getRenderer() const;
		float getDeltaTime() const;
		int getLastFrameTime() const;
		int getFps() const;
		int getWindowWidth() const;
		int getWindowHeight() const;
		bool getVSync() const;
		bool getColorBlocksOn() const;
		bool getMusicOn() const;
		bool getSoundEffectsOn() const;
		bool getIsRunning() const;

		void setFps(const int& value);
		void setVSync(const bool& value);
		void setColorBlocksOn(const bool& value);
		void setMusicOn(const bool& value);
		void setSoundEffectsOn(const bool& value);
		void setIsRunning(const bool& value);

	private:

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		std::map<std::string, Page*> pages;
		std::string currentLocation;
		std::string previousLocation;
		float deltaTime = 1;
		int lastFrameTime = 0;
		int fps = 0;
		int windowWidth = 0;
		int windowHeight = 0;
		bool vSync = false;
		bool colorBlocksOn = false;
		bool musicOn = false;
		bool soundEffectsOn = false;
		bool isRestartRequired = false;
		bool isRunning = false;

		static void getAppSettings(std::unordered_map<std::string, std::string>& data);
		static void saveAppSettings(const std::unordered_map<std::string, std::string>& data);
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
