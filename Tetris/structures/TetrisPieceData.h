#pragma once

#ifndef TETRIS__STRUCTURES__TETRIS_PIECE_DATA__H
#define TETRIS__STRUCTURES__TETRIS_PIECE_DATA__H

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
