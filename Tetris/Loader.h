#pragma once

#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace Tetris
{
	/// <summary>
	/// Includes tools to load some assets or get their properties.
	/// </summary>
	class Loader
	{
	public:

		static void getImageSize(
			const char* path,
			float* widthRef,
			float* heightRef);
		static void getUtf8TextSize(
			TTF_Font* font,
			const char* text,
			const Uint32* wrapLength,
			float* widthRef,
			float* heightRef);
		static SDL_Texture* getTextureOfImage(
			SDL_Renderer* renderer,
			const char* path);
		static SDL_Texture* getTextureOfUtf8Text(
			SDL_Renderer* renderer,
			TTF_Font* font,
			const SDL_Color& color,
			const char* text,
			const Uint32* wrapLength,
			float* widthRef,
			float* heightRef);
	};
}

#endif
