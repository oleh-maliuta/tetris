#pragma once

#ifndef TETRIS__AUDIO__SOUND_EFFECT__H
#define TETRIS__AUDIO__SOUND_EFFECT__H

#include <string>
#include <SDL_mixer.h>

namespace Tetris {
	class SoundEffect
	{
	public:

		SoundEffect(
			const std::string& path);
		~SoundEffect();

		void play();

	private:

		std::string path;
		Mix_Chunk* effect = nullptr;
		bool isInitialized = false;

		void init();
		void destroy();

		friend class Page;
	};
}

#endif
