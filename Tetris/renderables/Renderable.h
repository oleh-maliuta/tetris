#pragma once

#ifndef RENDERABLES_RENDERABLE_H
#define RENDERABLES_RENDERABLE_H

#include <functional>
#include <SDL.h>

namespace Tetris
{
	class Renderable
	{
	public:

		Renderable(SDL_Renderer* renderer);
		virtual ~Renderable();

		virtual bool isCursorIn(
			const float& x,
			const float& y);
		virtual void init();
		virtual void render();
		virtual void destroy();

		bool getVisibility() const;
		std::function<void()> getOnRelease() const;

		void setVisibility(const bool& value);
		void setOnRelease(const std::function<void()>& value);

	protected:

		SDL_Renderer* renderer = nullptr;
		bool visibility = true;
		bool isInitialized = false;

		std::function<void()> onRelease = [] {};
	};
}

#endif
