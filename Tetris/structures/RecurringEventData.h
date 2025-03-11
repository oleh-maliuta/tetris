#pragma once

#ifndef TETRIS__STRUCTURES__RECURRING_EVENT_DATA__H
#define TETRIS__STRUCTURES__RECURRING_EVENT_DATA__H

#include <functional>
#include <SDL.h>

namespace Tetris
{
	/// <summary>
	/// Stores data for managing the recurring events of a Page.
	/// </summary>
	struct RecurringEventData
	{
		Uint32 startTime;
		Uint32 interval;
		void* param;
		std::function<Uint32(Uint32, void*)> callback;
	};
}

#endif
