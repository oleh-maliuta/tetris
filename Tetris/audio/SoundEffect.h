#pragma once

#ifndef TETRIS__AUDIO__SOUND_EFFECT__H
#define TETRIS__AUDIO__SOUND_EFFECT__H

#include <string>
#include <SDL_mixer.h>

namespace Tetris
{
	/// <summary>
	/// Represents a sound effect used in a Page class.
	/// </summary>
	class SoundEffect
	{
	public:

		/// <summary>
		/// Initializes a new instance of the SoundEffect class.
		/// </summary>
		/// <param name="path">- path of an audio file.</param>
		SoundEffect(
			const std::string& path);
		~SoundEffect();

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
		Mix_Chunk* effect = nullptr;
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
