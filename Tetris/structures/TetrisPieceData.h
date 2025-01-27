#pragma once

#ifndef STRUCTURES_TETRIS_PIECE_DATA_H
#define STRUCTURES_TETRIS_PIECE_DATA_H

#include <cstdint>

namespace Tetris
{
	struct TetrisPieceData
	{
		TetrisCellPosition startBlockPositions[4];
		std::uint8_t r, g, b, a;
	};
}

#endif
