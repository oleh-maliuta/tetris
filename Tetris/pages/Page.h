#pragma once

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H

class App;

#include "../renderables/Renderable.h"
#include "../App.h"

class Page
{
public:

	Page(App* app);
	virtual ~Page();

	virtual void init();
	virtual void clean();

	void exec();

protected:

	App* app = nullptr;
	std::unordered_map<std::string, Renderable*> renderables;
	std::map<SDL_Keycode, std::function<void()>> keyDownEvents;
	std::map<SDL_Keycode, std::function<void()>> keyUpEvents;
	SDL_Color backgroundColor = { 255, 255, 255, 255 };
	bool isInitialized = false;

	virtual void input();
	virtual void update();
	virtual void render();
};

#endif
