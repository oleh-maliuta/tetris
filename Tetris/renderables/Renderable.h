#pragma once

#include "../App.h"

class Renderable
{
protected:
	App* app = nullptr;
public:
	Renderable(App*);
	virtual void init();
	virtual void render();
	virtual void destroy();
};

