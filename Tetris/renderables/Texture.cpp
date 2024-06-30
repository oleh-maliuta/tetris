#include "Texture.h"

Texture::Texture(
	App* app,
	const char* path,
	SDL_Rect* srcrect,
	SDL_Rect* dstrect
) : Renderable(app) {
	char* strToSet = new char[std::strlen(path) + 1];
	std::strcpy(strToSet, path);

	this->filePath = strToSet;
	this->srcrect = srcrect;
	this->dstrect = dstrect;
}

Texture::~Texture() {
	if (this->sdlTexture != nullptr) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = nullptr;
	}

	delete[] this->filePath;
	delete this->srcrect;
	delete this->dstrect;
}

void Texture::init() {
	SDL_Renderer* renderer = this->app->getRenderer();

	this->sdlTexture = Loader::loadTexture(
		renderer,
		this->filePath);
}

void Texture::render() {
	SDL_RenderCopy(
		this->app->getRenderer(),
		this->sdlTexture,
		this->srcrect,
		this->dstrect);

	SDL_SetTextureColorMod(
		this->sdlTexture,
		this->moduleRed,
		this->moduleGreen,
		this->moduleBlue);
}

void Texture::destroy() {
	SDL_DestroyTexture(this->sdlTexture);
	this->sdlTexture = nullptr;
}
