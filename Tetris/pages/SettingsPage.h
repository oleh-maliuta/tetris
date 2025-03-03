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

		bool getMusicOn() const;
		bool getSoundEffectsOn() const;
		bool getColorBlocksOn() const;
		bool getVSync() const;

		void setMusicOn(const bool& value);
		void setSoundEffectsOn(const bool& value);
		void setColorBlocksOn(const bool& value);
		void setVSync(const bool& value);

	protected:

		virtual void update() override;

	private:

		bool musicOn = false;
		bool soundEffectsOn = false;
		bool colorBlocksOn = false;
		bool vSync = false;

		void initKeyDownEvents();
	};
}

#endif
