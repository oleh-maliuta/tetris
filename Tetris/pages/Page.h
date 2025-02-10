#pragma once

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H

#include <utility>
#include <list>
#include <unordered_map>
#include <algorithm>
#include "../renderables/Renderable.h"
#include "../Application.h"
#include "../renderables/Layout.h"
#include "../structures/RegularEventData.h"

namespace Tetris
{
	class Application;

	class Page
	{
	public:

		Page(Application* app);
		virtual ~Page();

		template<class T>
		T* getRenderable(
			const std::string& key);

		void setRegularEvent(
			const std::string& key,
			std::function<Uint32(Uint32, void*)> callback,
			Uint32 interval,
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

		virtual void init();
		virtual void clean();
		virtual void update();

		void addRenderable(
			const std::string& key,
			Renderable* obj);

	private:

		std::unordered_map<std::string, RegularEventData> regularEvents;
		std::list<std::pair<std::string, Renderable*>> renderables;

		void input();
		void render();
		void exec();
		void manageRegularEvents();

		friend class Application;
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
