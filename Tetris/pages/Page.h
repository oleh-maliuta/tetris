#pragma once

#ifndef PAGES_PAGE_H
#define PAGES_PAGE_H

#include "../App.h"

class Page
{
protected:
	bool initialized = false;
	App* app = nullptr;
public:
	Page(App*);
	void exec();
	virtual void init();
	virtual void clean();
	virtual void input();
	virtual void update();
	virtual void render();
};

#endif
