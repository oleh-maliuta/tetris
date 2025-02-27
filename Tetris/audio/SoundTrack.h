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
		void mute(
			const bool& value);

		bool isMuted() const;

	private:

		std::string path;
		Mix_Music* track = nullptr;
		bool muted = false;
		bool isInitialized = false;

		void init();
		void destroy();

		friend class Page;
	};
}

#endif
