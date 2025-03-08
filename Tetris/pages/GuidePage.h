#pragma once

#ifndef TETRIS__PAGES__GUIDE_PAGE__H
#define TETRIS__PAGES__GUIDE_PAGE__H

#include "Page.h"
#include "../Loader.h"
#include "../renderables/Texture.h"
#include "../renderables/Text.h"
#include "../renderables/TextButton.h"
#include "../renderables/ImageButton.h"

namespace Tetris
{
	class GuidePage
		: public Page
	{
	public:

		GuidePage(Application* app);

		virtual void init() override;
		virtual void clean() override;

	protected:

		virtual void update() override;

	private:

		void initKeyDownEvents();
	};
}

#endif
