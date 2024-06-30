#include "Loader.h"

SDL_Texture* Loader::loadTexture(
	SDL_Renderer* renderer,
	const char* path
) {
	SDL_Texture* texture = IMG_LoadTexture(renderer, path);

	if (texture == nullptr) {
		printf(
			"Unable to create texture from %s! SDL Error: %s\n",
			path,
			IMG_GetError());
	}

	return texture;
}
