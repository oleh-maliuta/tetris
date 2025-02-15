#pragma once

#ifndef TETRIS__PAGES__MAIN_MENU_PAGE__H
#define TETRIS__PAGES__MAIN_MENU_PAGE__H

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

		virtual void update() override;
	};
}

#endif
