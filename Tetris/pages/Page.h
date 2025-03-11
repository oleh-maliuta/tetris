#pragma once

#ifndef TETRIS__PAGES__PAGE__H
#define TETRIS__PAGES__PAGE__H

#include <utility>
#include <list>
#include <unordered_map>
#include <algorithm>
#include "../renderables/Renderable.h"
#include "../Application.h"
#include "../renderables/Layout.h"
#include "../structures/RecurringEventData.h"
#include "../audio/SoundTrack.h"
#include "../audio/SoundEffect.h"

namespace Tetris
{
	class Application;

	/// <summary>
	/// Represents a page for displaying SDL graphics and handling application logic.
	/// This class manages rendering, input handling, audio playback, and event scheduling.
	/// </summary>
	class Page
	{
	public:

		/// <summary>
		/// Initializes a new instance of the Page class.
		/// </summary>
		/// <param name="app">- SDL application class.</param>
		Page(Application* app);
		virtual ~Page();

		/// <summary>
		/// Retrieves a renderable object by its key.
		/// </summary>
		/// <typeparam name="T">- the type of the renderable object.</typeparam>
		/// <param name="key">- the identifier of the renderable.</param>
		/// <returns>- a pointer to the requested renderable object, or nullptr if not found.</returns>
		template<class T>
		T* getRenderable(
			const std::string& key) const;

		/// <summary>
		/// Sets a recurring event in the game loop.
		/// </summary>
		/// <param name="key">- the event identifier.</param>
		/// <param name="callback">- the function to be executed at regular intervals.</param>
		/// <param name="interval">- the interval in milliseconds between executions.</param>
		/// <param name="param">- a pointer to additional event data.</param>
		void setRecurringEvent(
			const std::string& key,
			std::function<Uint32(Uint32, void*)> callback,
			Uint32 interval,
			void* param);
		/// <summary>
		/// Removes a previously set recurring event.
		/// </summary>
		/// <param name="key">- the event identifier.</param>
		void removeRecurringEvent(
			const std::string& key);

		/// <summary>
		/// Gets the associated application instance.
		/// </summary>
		/// <returns>a pointer to the application.</returns>
		Application* getApp() const;

	protected:

		Application* app = nullptr;
		std::function<void()> onQuit;
		std::map<SDL_Keycode, std::function<void()>> keyDownEvents;
		std::map<SDL_Keycode, std::function<void()>> keyUpEvents;
		SDL_Color backgroundColor = { 255, 255, 255, 255 };
		bool isInitialized = false;

		/// <summary>
		/// Initializes the page allocating memory for the resources.
		/// </summary>
		virtual void init();
		/// <summary>
		/// Releases the allocated memory and cleans up resources.
		/// </summary>
		virtual void clean();
		/// <summary>
		/// Updates data every frame.
		/// </summary>
		virtual void update();

		void setRenderable(
			const std::string& key,
			Renderable* obj);
		SoundEffect* setSoundEffect(
			const std::string& key,
			const std::string& path);
		SoundEffect* getSoundEffect(
			const std::string& key);
		void muteAllSoundEffects(
			const bool& value);
		void setMusic(
			const std::string& path);
		void playMusic();
		void muteMusic(
			const bool& value);

	private:

		std::list<std::pair<std::string, Renderable*>> renderables;
		std::unordered_map<std::string, RecurringEventData> recurringEvents;
		std::map<std::string, SoundEffect*> soundEffects;
		SoundTrack* music = nullptr;

		void input();
		void render();
		void exec();
		void manageRegularEvents();

		friend class Application;
	};

	template<class T>
	T* Tetris::Page::getRenderable(
		const std::string& key) const
	{
		if (!std::is_base_of<Renderable, T>::value) {
			return nullptr;
		}

		for (const auto& el : this->renderables) {
			if (el.first == key) {
				return dynamic_cast<T*>(el.second);
			}
		}

		return nullptr;
	}
}

#endif
