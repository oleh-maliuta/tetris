#pragma once

#ifndef TETRIS__PAGES__SCORE_VALUES_PAGE__H
#define TETRIS__PAGES__SCORE_VALUES_PAGE__H

#include "Page.h"
#include "../renderables/Texture.h"
#include "../renderables/Text.h"
#include "../renderables/ImageButton.h"

namespace Tetris
{
	class ScoreValuesPage
		: public Page
	{
	public:

		ScoreValuesPage(Application* app);

		virtual void init() override;
		virtual void clean() override;

	protected:

		virtual void update() override;

	private:

		void initKeyDownEvents();
	};
}

#endif
