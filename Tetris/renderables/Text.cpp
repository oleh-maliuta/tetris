#include "Text.h"

Text::Text(
	App* app,
	std::string fontPath,
	std::string content,
	SDL_Color fontColor,
	int fontSize,
	Uint32 wrapLength)
	: Renderable(app) {
	this->fontPath = fontPath;
	this->content = content;
	this->fontColor = fontColor;
	this->fontSize = fontSize;
	this->wrapLength = wrapLength;
}

Text::~Text() {
	this->destroy();
	delete this->rotationPoint;
}

void Text::init() {
	SDL_Renderer* renderer = this->app->getRenderer();

	this->font = TTF_OpenFont(
		this->fontPath.c_str(),
		this->fontSize);

	if (this->font == nullptr)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n",
			TTF_GetError());
		this->app->isRunning = false;
	}

	this->texture = Loader::loadTextureFromSolidUtf8Text(
		renderer,
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		this->width,
		this->height);
}

void Text::render() {
	SDL_Rect srcRect = { this->x, this->y, this->width, this->height };

	SDL_RenderCopyEx(
		this->app->getRenderer(),
		this->texture,
		nullptr,
		&srcRect,
		this->angle,
		this->rotationPoint,
		this->flip);
}

void Text::destroy() {
	if (this->font != nullptr) {
		TTF_CloseFont(this->font);
		this->font = nullptr;
	}

	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}
}
