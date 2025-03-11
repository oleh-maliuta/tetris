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
#include <nlohmann/json.hpp>
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

		/// <summary>
		/// Current version of the application.
		/// </summary>
		const std::string VERSION = "1.0.0";

		/// <summary>
		/// Initializes a new instance of the Application class.
		/// </summary>
		/// <param name="windowWidth">- window width of the application.</param>
		/// <param name="windowHeight">- window height of the application.</param>
		Application(
			const int& windowWidth,
			const int& windowHeight);
		~Application();

		/// <summary>
		/// Adds a using page to the application.
		/// </summary>
		/// <typeparam name="T">Type of the Page class.</typeparam>
		/// <param name="key">- the string that will identify the page.</param>
		template<class T>
		void usePage(const std::string& key);

		/// <summary>
		/// Changes the current page by the key.
		/// </summary>
		/// <param name="key">- the string that will identify the page.</param>
		void changePage(const std::string& key);
		/// <summary>
		/// Clears and then initializes the same current page.
		/// </summary>
		void restartPage();
		/// <summary>
		/// Runs the application.
		/// </summary>
		/// <param name="startPage">- the key of the page that the application will display on the start.</param>
		void run(const std::string& startPage);
		/// <summary>
		/// Shuts the application down.
		/// </summary>
		void shutDown();

		/// <summary>
		/// Halts all currently playing sound effects.
		/// </summary>
		void haltSound();
		/// <summary>
		/// Pauses the playing music of the current page.
		/// </summary>
		void pauseMusic();
		/// <summary>
		/// Resumes the paused music of the current page.
		/// </summary>
		void resumeMusic();
		/// <summary>
		/// Halts the playing music of the current page.
		/// </summary>
		void haltMusic();

		/// <returns>the SDL renderer of the application.</returns>
		SDL_Renderer* getRenderer() const;
		/// <returns>the current delta time of the current frame.</returns>
		float getDeltaTime() const;
		/// <returns>the current "frame per second" value.</returns>
		int getFps() const;
		/// <returns>the width of the application window.</returns>
		int getWindowWidth() const;
		/// <returns>the height of the application window.</returns>
		int getWindowHeight() const;
		/// <summary>
		/// Checks if the V-Sync is on.
		/// </summary>
		bool getVSync() const;
		/// <summary>
		/// Checks if the "color blocks" feature is on.
		/// </summary>
		bool getColorBlocksOn() const;
		/// <summary>
		/// Checks if the music is on.
		/// </summary>
		bool getMusicOn() const;
		/// <summary>
		/// Checks if the sound effects are on.
		/// </summary>
		bool getSoundEffectsOn() const;
		/// <summary>
		/// Checks if the application is running.
		/// </summary>
		bool getIsRunning() const;

		/// <summary>
		/// Enables the V-Sync mode.
		/// </summary>
		void setVSync(const bool& value);
		/// <summary>
		/// Enables the "color blocks" feature.
		/// </summary>
		void setColorBlocksOn(const bool& value);
		/// <summary>
		/// Enables the music.
		/// </summary>
		void setMusicOn(const bool& value);
		/// <summary>
		/// Enables the sound effects.
		/// </summary>
		void setSoundEffectsOn(const bool& value);

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

		/// <summary>
		/// Reads the app_settings.json file that stores the settings of the application.
		/// Sets default values if the file is not found or the json syntax error occurs.
		/// </summary>
		void getAppSettings();
		/// <summary>
		/// Saves the current application settings in the app_settings.json file.
		/// If the file does not exist, it will be created.
		/// </summary>
		void saveAppSettings();
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
