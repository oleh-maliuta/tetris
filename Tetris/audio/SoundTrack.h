#pragma once

#ifndef TETRIS__AUDIO__SOUND_TRACK__H
#define TETRIS__AUDIO__SOUND_TRACK__H

#include <string>
#include <SDL_mixer.h>

namespace Tetris {
	class SoundTrack
	{
	public:

		SoundTrack(
			const std::string& path);
		~SoundTrack();

		void play();

	private:

		std::string path;
		Mix_Music* track = nullptr;
		bool isInitialized = false;

		void init();
		void destroy();

		friend class Page;
	};
}

#endif
