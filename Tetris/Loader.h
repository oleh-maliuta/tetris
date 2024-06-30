#pragma once

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#ifndef LOADER_H
#define LOADER_H

class Loader
{
public:
	static SDL_Texture* loadTexture(SDL_Renderer*, const char*);
};

#endif // LOADER_H
