#include "Loader.h"

SDL_Texture* Loader::loadTextureFromImage(
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

SDL_Texture* Loader::loadTextureFromSolidUtf8Text(
	SDL_Renderer* renderer,
	TTF_Font* font,
	SDL_Color color,
	const char* text,
	Uint32 wrapLength,
	int& widthRef,
	int& heightRef
) {
	SDL_Surface* textSurface = TTF_RenderUTF8_Solid_Wrapped(
		font, text, color, wrapLength);

	if (textSurface == nullptr)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n",
			TTF_GetError());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);

	if (texture == nullptr)
	{
		printf("Unable to create texture from rendered text! SDL Error: %s\n",
			SDL_GetError());
	}

	if (textSurface != nullptr) {
		widthRef = textSurface->w;
		heightRef = textSurface->h;
	}

	SDL_FreeSurface(textSurface);

	return texture;
}
