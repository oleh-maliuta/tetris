#pragma once

#ifndef PAGES_PLAYPAGE_H
#define PAGES_PLAYPAGE_H

#include <algorithm>
#include <format>
#include <random>
#include <array>
#include <vector>
#include <list>
#include "Page.h"
#include "../Loader.h"
#include "../renderables/Rectangle.h"
#include "../renderables/Text.h"
#include "../renderables/TextButton.h"
#include "../renderables/Texture.h"
#include "../renderables/Layout.h"
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
		std::list<TetrisCellPosition> blockMarkers;
		bool gridInfo[10][20];
		Uint32 blockFallingInterval = START_BLOCK_FALLING_INTERVAL;
		short int pieceRotationIndex = 0;
		unsigned int level = 1;
		unsigned int lines = 0;
		unsigned int score = 0;
		char* currentBlock = nullptr;
		bool isSoftDropOn = false;
		bool pause = false;
		bool gameOver = false;

		PlayPage(Application* app);

		virtual void init() override;
		virtual void clean() override;

		void updateBlockMarkers();
		void clearFilledGridRows();
		void saveGameOverResults();

		void rotatePiece(
			bool clockwise,
			bool shouldOffset);
		void rotateTile(
			TetrisBlockData& curBlock,
			TetrisCellPosition originPos,
			bool clockwise);
		bool offsetPiecePosition(
			int oldRotIndex,
			int newRotIndex);
		bool canMovePiece(
			TetrisCellPosition movement);
		bool canTileMove(
			TetrisBlockData& curBlock,
			TetrisCellPosition endPos) const;
		bool movePiece(
			TetrisCellPosition movement);

		static Uint32 gameProcessRegularEvent(
			Uint32 interval,
			void* param);

	protected:

		virtual void update() override;

	private:

		const SDL_Color DEFAULT_CELL_COLOR = { 35, 50, 79, 255 };

		std::map<char, TetrisPieceData> pieceData;
		Rectangle* cells[10][20];
		Rectangle* cellMarkers[10][20];
		Texture* nextBlockHint = nullptr;
		char* nextBlock = nullptr;

		void choosePiece();
		void initPauseMenu();
		void initGameOverMenu();
		void initKeyDownEvents();
		void initKeyUpEvents();
		void initRegularEvents();
	};
}

#endif
