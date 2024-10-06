#pragma once

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H

class App;

#include <utility>
#include <list>
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
	std::map<SDL_Keycode, std::function<void()>> keyDownEvents;
	std::map<SDL_Keycode, std::function<void()>> keyUpEvents;
	SDL_Color backgroundColor = { 255, 255, 255, 255 };
	bool isInitialized = false;

	virtual void input();
	virtual void update();
	virtual void render();

	void addRenderable(
		const std::string& key,
		Renderable* obj);
	Renderable* getRenderable(const std::string& key);

private:

	std::list<std::pair<std::string, Renderable*>> renderables;
};

#endif
