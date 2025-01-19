#pragma once

#ifndef PAGE_PLAYPAGE_H
#define PAGE_PLAYPAGE_H

#include <algorithm>
#include <format>
#include <random>
#include <array>
#include <list>
#include "Page.h"
#include "../Loader.h"
#include "../renderables/Rectangle.h"
#include "../renderables/Text.h"
#include "../renderables/Texture.h"
#include "../structures/TetrisCellPosition.h"
#include "../structures/TetrisBlockData.h"

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

		virtual void update() override;

	private:

		const SDL_Color DEFAULT_CELL_COLOR = { 35, 50, 79, 255 };
		const Uint32 START_BLOCK_FALLING_INTERVAL = 1000;

		std::map<char, std::vector<TetrisCellPosition>> shapeSpawnPositions;
		std::map<char, SDL_Color> shapeSpawnColors;
		std::list<TetrisBlockData> movingBlocks;
		std::list<TetrisBlockData> idleBlocks;
		std::array<std::array<bool, 20>, 10> cellInfo = {};
		Texture* nextBlockHint = nullptr;
		Uint32 blockFallingInterval = 1000;
		Uint32 lastTimerState = 0;
		char* currentBlock = nullptr;
		char* nextBlock = nullptr;
		unsigned int level = 1;
		unsigned int lines = 0;
		unsigned int score = 0;

		void chooseShape();
	};
}

#endif
