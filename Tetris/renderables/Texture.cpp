#include "Texture.h"

Texture::Texture(
	App* app,
	std::string path
) : Renderable(app) {
	this->filePath = path;
}

Texture::~Texture() {
	this->destroy();
	delete this->srcrect;
	delete this->dstrect;
	delete this->rotationPoint;
}

void Texture::init() {
	SDL_Renderer* renderer = this->app->getRenderer();

	this->sdlTexture = Loader::loadTextureFromImage(
		renderer,
		this->filePath.c_str());
}

void Texture::render() {
	SDL_RenderCopyEx(
		this->app->getRenderer(),
		this->sdlTexture,
		this->srcrect,
		this->dstrect,
		this->angle,
		this->rotationPoint,
		this->flip);

	SDL_SetTextureColorMod(
		this->sdlTexture,
		this->moduleRed,
		this->moduleGreen,
		this->moduleBlue);
}

void Texture::destroy() {
	if (this->sdlTexture != nullptr) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = nullptr;
	}
}
