#include "Loader.h"

void Tetris::Loader::getImageSize(
	const char* path,
	float* widthRef,
	float* heightRef)
{
	SDL_Surface* surface = IMG_Load(path);

	if (surface == nullptr) {
		printf("Unable to load image %s! SDL_image Error: %s\n",
			path,
			IMG_GetError());

		if (widthRef != nullptr) {
			*widthRef = 0;
		}
		if (heightRef != nullptr) {
			*heightRef = 0;
		}

		return;
	}

	if (widthRef != nullptr) {
		*widthRef = static_cast<float>(surface->w);
	}
	if (heightRef != nullptr) {
		*heightRef = static_cast<float>(surface->h);
	}
}

void Tetris::Loader::getUtf8TextSize(
	TTF_Font* font,
	const char* text,
	const Uint32* wrapLength,
	float* widthRef,
	float* heightRef)
{
	SDL_Surface* textSurface = wrapLength != nullptr ?
		TTF_RenderUTF8_Solid_Wrapped(font, text, {}, *wrapLength) :
		TTF_RenderUTF8_Solid(font, text, {});

	if (textSurface == nullptr)
	{
		printf("Unable to render a text surface! SDL_ttf Error: %s\n",
			TTF_GetError());
	}

	if (textSurface != nullptr) {
		if (widthRef != nullptr) {
			*widthRef = static_cast<float>(textSurface->w);
		}
		if (heightRef != nullptr) {
			*heightRef = static_cast<float>(textSurface->h);
		}
	}

	SDL_FreeSurface(textSurface);
}

SDL_Texture* Tetris::Loader::getTextureFromImage(
	SDL_Renderer* renderer,
	const char* path) 
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, path);

	if (texture == nullptr) {
		printf(
			"Unable to create a texture from %s! SDL Error: %s\n",
			path,
			IMG_GetError());
	}

	return texture;
}

SDL_Texture* Tetris::Loader::getTextureFromUtf8Text(
	SDL_Renderer* renderer,
	TTF_Font* font,
	const SDL_Color& color,
	const char* text,
	const Uint32* wrapLength,
	float* widthRef,
	float* heightRef)
{
	SDL_Surface* textSurface = wrapLength != nullptr ?
		TTF_RenderUTF8_Blended_Wrapped(font, text, color, *wrapLength) :
		TTF_RenderUTF8_Blended(font, text, color);

	if (textSurface == nullptr)
	{
		printf("Unable to render a text surface! SDL_ttf Error: %s\n",
			TTF_GetError());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);

	if (texture == nullptr)
	{
		printf("Unable to create a texture from rendered text! SDL Error: %s\n",
			SDL_GetError());
	}

	if (textSurface != nullptr) {
		if (widthRef != nullptr) {
			*widthRef = static_cast<float>(textSurface->w);
		}
		if (heightRef != nullptr) {
			*heightRef = static_cast<float>(textSurface->h);
		}
	}

	SDL_FreeSurface(textSurface);

	return texture;
}
