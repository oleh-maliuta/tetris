#pragma once

#ifndef TETRIS__LOADER__H
#define TETRIS__LOADER__H

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

		/// <summary>
		/// Returns the real size of the image file by the path.
		/// </summary>
		/// <param name="path">- image path.</param>
		/// <param name="widthRef">- width result.</param>
		/// <param name="heightRef">- height result.</param>
		static void getImageSize(
			const char* path,
			float* widthRef,
			float* heightRef);
		/// <summary>
		/// Returns the size of the text texture by its parameters.
		/// </summary>
		/// <param name="font">- SDL font.</param>
		/// <param name="text">- content.</param>
		/// <param name="wrapLength">- maximum line length.</param>
		/// <param name="widthRef">- width result.</param>
		/// <param name="heightRef">- height result.</param>
		static void getUtf8TextSize(
			TTF_Font* font,
			const char* text,
			const Uint32* wrapLength,
			float* widthRef,
			float* heightRef);
		/// <summary>
		/// Returns the texture of the image file by the path.
		/// </summary>
		/// <param name="renderer">- renderer of the SDL application.</param>
		/// <param name="path">- path of the image.</param>
		/// <returns>image texture.</returns>
		static SDL_Texture* getTextureOfImage(
			SDL_Renderer* renderer,
			const char* path);
		/// <summary>
		/// Generates a texture of a UTF-8 text according to the parameters and returns the size of the texture.
		/// </summary>
		/// <param name="renderer">- renderer of the SDL application.</param>
		/// <param name="font">- SDL font.</param>
		/// <param name="color">- text color.</param>
		/// <param name="text">- content.</param>
		/// <param name="wrapLength">- maximum line length.</param>
		/// <param name="widthRef">- width result.</param>
		/// <param name="heightRef">- height result.</param>
		/// <returns>texture of the text.</returns>
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
