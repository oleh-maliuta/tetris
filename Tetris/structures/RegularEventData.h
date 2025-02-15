#pragma once

#ifndef TETRIS__STRUCTURES__REGULAR_EVENT_DATA__H
#define TETRIS__STRUCTURES__REGULAR_EVENT_DATA__H

#include <SDL.h>
#include <functional>

namespace Tetris
{
	struct RegularEventData
	{
		Uint32 startTime;
		Uint32 interval;
		void* param;
		std::function<Uint32(Uint32, void*)> callback;
	};
}

#endif
