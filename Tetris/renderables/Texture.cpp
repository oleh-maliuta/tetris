#include "Texture.h"

Texture::Texture(
	App* app,
	const char* path,
	SDL_Rect* srcrect,
	SDL_Rect* dstrect
) : Renderable(app) {
	this->filePath = path;
	this->srcrect = srcrect;
	this->dstrect = dstrect;
}

Texture::~Texture() {
	if (this->sdlTexture != nullptr) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = nullptr;
	}

	char* strToDel = new char[std::strlen(this->filePath) + 1];
	std::strcpy(strToDel, this->filePath);

	delete[] strToDel;
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
}

void Texture::destroy() {
	SDL_DestroyTexture(this->sdlTexture);
	this->sdlTexture = nullptr;
}
