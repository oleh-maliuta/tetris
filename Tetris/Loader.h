#pragma once

#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Loader
{
public:

	static SDL_Texture* loadTextureFromImage(
		SDL_Renderer* renderer,
		const char* path);
	static SDL_Texture* loadTextureFromSolidUtf8Text(
		SDL_Renderer* renderer,
		TTF_Font* font,
		const SDL_Color& color,
		const char* text,
		const Uint32* wrapLength,
		int* widthRef,
		int* heightRef);
};

#endif
