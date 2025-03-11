#pragma once

#ifndef TETRIS__AUDIO__SOUND_TRACK__H
#define TETRIS__AUDIO__SOUND_TRACK__H

#include <string>
#include <SDL_mixer.h>

namespace Tetris
{
	/// <summary>
	/// Represents a music used in a Page class.
	/// </summary>
	class SoundTrack
	{
	public:

		/// <summary>
		/// Initializes a new instance of the SoundTrack class.
		/// </summary>
		/// <param name="path">- path of an audio file.</param>
		SoundTrack(
			const std::string& path);
		~SoundTrack();

		/// <summary>
		/// Plays the audio.
		/// </summary>
		void play();
		/// <summary>
		/// Disables or enables playing the audio.
		/// </summary>
		/// <param name="value">- disable or enable.</param>
		void mute(
			const bool& value);

		/// <summary>
		/// Checks if playing the audio is enabled or disabled.
		/// </summary>
		bool isMuted() const;

	private:

		std::string path;
		Mix_Music* track = nullptr;
		bool muted = false;
		bool isInitialized = false;

		/// <summary>
		/// Allocates memory for the resources enabling playing the audio.
		/// </summary>
		void init();
		/// <summary>
		/// Releases the allocated memory and cleans up resources disabling playing the audio.
		/// </summary>
		void destroy();

		friend class Page;
	};
}

#endif
