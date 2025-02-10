#pragma once

#ifndef STRUCTURES_REGULAR_EVENT_DATA_H
#define STRUCTURES_REGULAR_EVENT_DATA_H

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
