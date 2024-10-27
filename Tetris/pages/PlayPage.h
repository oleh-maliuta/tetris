#pragma once

#ifndef PAGE_PLAYPAGE_H
#define PAGE_PLAYPAGE_H

#include <format>
#include <random>
#include "Page.h"
#include "../Loader.h"
#include "../renderables/Rectangle.h"
#include "../renderables/Text.h"
#include "../renderables/Texture.h"
#include "../structures/Tetris_Cell.h"

namespace Tetris
{
	class PlayPage :
		public Page
	{
	public:

		PlayPage(Application* app);

		virtual void init() override;
		virtual void clean() override;

	protected:

		virtual void input() override;
		virtual void update() override;
		virtual void render() override;

	private:

		std::list<Tetris_Cell> cells;
		Texture* nextBlockHint = nullptr;
		double blockFallingDelay = 0;
		char currentBlock = 0;
		unsigned int level = 1;
		unsigned int lines = 0;
		unsigned int score = 0;
	};
}

#endif
