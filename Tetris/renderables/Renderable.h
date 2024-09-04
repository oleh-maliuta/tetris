#pragma once

#ifndef RENDERABLES_RENDERABLE_H
#define RENDERABLES_RENDERABLE_H

#include <functional>
#include "../App.h"

class Renderable
{
public:

	Renderable(App* app);
	virtual ~Renderable();

	virtual bool isCursorIn(int x, int y);
	virtual void init();
	virtual void render();
	virtual void destroy();

	bool getVisibility() const;
	std::function<void()> getOnRelease() const;

	void setVisibility(const bool& value);
	void setOnRelease(const std::function<void()>& value);

protected:

	App* app = nullptr;
	bool visibility = true;

	std::function<void()> onRelease = [] {};
};

#endif
