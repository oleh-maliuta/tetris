#pragma once

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H

#include <map>
#include "../App.h"
#include "../renderables/Renderable.h"

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
	std::map<std::string, Renderable*> renderables;
	bool isInitialized = false;

	virtual void input();
	virtual void update();
	virtual void render();
};

#endif
