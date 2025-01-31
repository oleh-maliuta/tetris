#pragma once

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H

#include <utility>
#include <list>
#include <unordered_map>
#include "../renderables/Renderable.h"
#include "../Application.h"
#include "../renderables/Layout.h"

namespace Tetris
{
	class Application;

	class Page
	{
	public:

		Page(Application* app);
		virtual ~Page();

		virtual void init();
		virtual void clean();

		template<class T>
		T* getRenderable(
			const std::string& key);

		void exec();

		void addRegularEvent(
			const std::string& key,
			Uint32 interval,
			SDL_TimerCallback callback,
			void* param);
		void removeRegularEvent(
			const std::string& key);

		Application* getApp() const;

	protected:

		Application* app = nullptr;
		std::map<SDL_Keycode, std::function<void()>> keyDownEvents;
		std::map<SDL_Keycode, std::function<void()>> keyUpEvents;
		SDL_Color backgroundColor = { 255, 255, 255, 255 };
		bool isInitialized = false;

		virtual void update();

		void addRenderable(
			const std::string& key,
			Renderable* obj);

	private:

		std::unordered_map<std::string, SDL_TimerID> regularEvents;
		std::list<std::pair<std::string, Renderable*>> renderables;

		void input();
		void render();
	};

	template<class T>
	T* Tetris::Page::getRenderable(
		const std::string& key)
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
