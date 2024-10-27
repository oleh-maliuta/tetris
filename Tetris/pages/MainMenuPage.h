#pragma once

#ifndef PAGES_MAINMENUPAGE_H
#define PAGES_MAINMENUPAGE_H

#include "Page.h"
#include "../Loader.h"
#include "../renderables/Texture.h"
#include "../renderables/Text.h"
#include "../renderables/TextButton.h"

namespace Tetris
{
	class MainMenuPage
		: public Page
	{
	public:

		MainMenuPage(Application* app);

		virtual void init() override;
		virtual void clean() override;

	protected:

		virtual void input() override;
		virtual void update() override;
		virtual void render() override;
	};
}

#endif
