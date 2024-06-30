#pragma once

#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

class Loader
{
public:
	static SDL_Texture* loadTexture(SDL_Renderer*, const char*);
};

#endif
