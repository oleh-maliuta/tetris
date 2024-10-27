#pragma once

#ifndef TETRIS_CELL_H
#define TETRIS_CELL_H

#include <cstdint>

namespace Tetris
{
	struct Tetris_Cell
	{
		std::int8_t x, y;
		std::uint8_t r, g, b;
	};
}

#endif
