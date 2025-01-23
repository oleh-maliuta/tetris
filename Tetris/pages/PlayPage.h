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

		const Uint32 START_BLOCK_FALLING_INTERVAL = 1000;

		std::list<TetrisBlockData> fallingBlocks;
		std::list<TetrisBlockData> idleBlocks;
		bool cellInfo[10][20];
		Uint32 blockFallingInterval = START_BLOCK_FALLING_INTERVAL;
		bool isBlockFallingAccelerated = false;

		SDL_TimerCallback blockFallingTimerCallback();

		PlayPage(Application* app);

		virtual void init() override;
		virtual void clean() override;

		void updateBlockMarkers();

	protected:

		virtual void update() override;

	private:

		const SDL_Color DEFAULT_CELL_COLOR = { 35, 50, 79, 255 };

		std::map<char, std::vector<TetrisCellPosition>> shapeSpawnPositions;
		std::map<char, SDL_Color> shapeSpawnColors;
		std::list<TetrisCellPosition> blockMarkers;
		Texture* nextBlockHint = nullptr;
		char* currentBlock = nullptr;
		char* nextBlock = nullptr;
		unsigned int level = 1;
		unsigned int lines = 0;
		unsigned int score = 0;

		void chooseShape();
		void initKeyDownEvents();
		void initKeyUpEvents();
		void initRegularEvents();
	};
}

#endif
