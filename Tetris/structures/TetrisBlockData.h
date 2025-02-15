#pragma once

#ifndef TETRIS__STRUCTURES__TETRIS_BLOCK_DATA__H
#define TETRIS__STRUCTURES__TETRIS_BLOCK_DATA__H

#include <cstdint>

namespace Tetris
{
	struct TetrisBlockData
	{
		int x, y;
		std::uint8_t r, g, b, a;
	};
}

#endif
