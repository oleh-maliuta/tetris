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
		void mute(
			const bool& value);

		bool isMuted() const;

	private:

		std::string path;
		Mix_Chunk* effect = nullptr;
		bool muted = false;
		bool isInitialized = false;

		void init();
		void destroy();

		friend class Page;
	};
}

#endif
