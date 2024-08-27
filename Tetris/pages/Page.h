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

	void exec();
	virtual void init();
	virtual void clean();
	virtual void input();
	virtual void update();
	virtual void render();

protected:
	App* app = nullptr;
	std::map<std::string, Renderable*> renderables;
	bool isInitialized = false;
};

#endif
