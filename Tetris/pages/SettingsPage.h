#pragma once

#ifndef TETRIS__PAGES__SETTINGS_PAGE__H
#define TETRIS__PAGES__SETTINGS_PAGE__H

#include "Page.h"
#include "../Loader.h"
#include "../renderables/Texture.h"
#include "../renderables/Text.h"
#include "../renderables/TextButton.h"
#include "../renderables/ImageButton.h"

namespace Tetris
{
	class SettingsPage
		: public Page
	{
	public:

		SettingsPage(Application* app);

		virtual void init() override;
		virtual void clean() override;

		bool getVSync() const;

		void setVSync(const bool& value);

	protected:

		virtual void update() override;

	private:

		bool vSync = false;
	};
}

#endif
