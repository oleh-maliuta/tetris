#include "Loader.h"

SDL_Texture* Loader::loadTexture(SDL_Renderer* renderer, std::string path) {
	SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

	if (texture == NULL) {
		printf(
			"Unable to create texture from %s! SDL Error: %s\n",
			path.c_str(),
			IMG_GetError());
	}

	return texture;
}
