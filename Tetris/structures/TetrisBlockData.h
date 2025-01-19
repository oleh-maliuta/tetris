#pragma once

#ifndef STRUCTURES_TETRIS_BLOCK_DATA_H
#define STRUCTURES_TETRIS_BLOCK_DATA_H

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
