#pragma once

#ifndef RENDERABLES_RENDERABLE_H
#define RENDERABLES_RENDERABLE_H

#include "../App.h"

class Renderable
{
public:

	Renderable(App* app);
	virtual ~Renderable();

	virtual void init();
	virtual void render();
	virtual void destroy();

	bool getVisibility() const;

	void setVisibility(const bool& value);

protected:

	App* app = nullptr;
	bool visibility = true;
};

#endif
