#pragma once

#include <string>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

class Loader
{
public:
	static SDL_Texture* loadTexture(SDL_Renderer*, std::string);
};
