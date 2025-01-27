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
#include "../structures/TetrisPieceData.h"

namespace Tetris
{
	class PlayPage :
		public Page
	{
	public:

		const TetrisCellPosition J_L_S_T_Z_OFFSET_DATA[5][4] = {
			{
				{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
			},
			{
				{ 0, 0 }, { 1, 0 }, { 0, 0 }, { -1, 0 }
			},
			{
				{ 0, 0 }, { 1, -1 }, { 0, 0 }, { -1, -1 }
			},
			{
				{ 0, 0 }, { 0, 2 }, { 0, 0 }, { 0, 2 }
			},
			{
				{ 0, 0 }, { 1, 2 }, { 0, 0 }, { -1, 2 }
			}
		};
		const TetrisCellPosition I_OFFSET_DATA[5][4] = {
			{
				{ 0, 0 }, { -1, 0 }, { -1, 1 }, { 0, 1 }
			},
			{
				{ -1, 0 }, { 0, 0 }, { 1, 1 }, { 0, 1 }
			},
			{
				{ 2, 0 }, { 0, 0 }, { -2, 1 }, { 0, 1 }
			},
			{
				{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }
			},
			{
				{ 2, 0 }, { 0, -2 }, { -2, 0 }, { 0, 2 }
			}
		};
		const Uint32 START_BLOCK_FALLING_INTERVAL = 1000;

		std::list<TetrisBlockData> fallingBlocks;
		std::list<TetrisBlockData> idleBlocks;
		bool cellInfo[10][20];
		Uint32 blockFallingInterval = START_BLOCK_FALLING_INTERVAL;
		short int pieceRotationIndex = 0;
		char* currentBlock = nullptr;
		bool isBlockFallingAccelerated = false;

		SDL_TimerCallback blockFallingTimerCallback();

		PlayPage(Application* app);

		virtual void init() override;
		virtual void clean() override;

		void updateBlockMarkers();

		void test_rotatePiece(
			bool clockwise,
			bool shouldOffset);
		int test_mod(
			int x,
			int m);
		void test_rotateTile(
			TetrisBlockData& curBlock,
			TetrisCellPosition originPos,
			bool clockwise);
		bool test_offset(
			int oldRotIndex,
			int newRotIndex);
		bool test_canMovePiece(
			TetrisCellPosition movement);
		bool test_canTileMove(
			TetrisBlockData& curBlock,
			TetrisCellPosition endPos);
		bool test_isInBounds(
			TetrisCellPosition coordToTest);
		bool test_isPosEmpty(
			TetrisCellPosition coordToTest);
		bool test_movePiece(
			TetrisCellPosition movement);

	protected:

		virtual void update() override;

	private:

		const SDL_Color DEFAULT_CELL_COLOR = { 35, 50, 79, 255 };

		std::map<char, TetrisPieceData> pieceData;
		std::list<TetrisCellPosition> blockMarkers;
		Texture* nextBlockHint = nullptr;
		char* nextBlock = nullptr;
		unsigned int level = 1;
		unsigned int lines = 0;
		unsigned int score = 0;

		void choosePiece();
		void initKeyDownEvents();
		void initKeyUpEvents();
		void initRegularEvents();
	};
}

#endif
