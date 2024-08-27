#include "Text.h"

Text::Text(
	App* app,
	const std::string& fontPath,
	const std::string& content,
	const int& fontSize,
	const Uint32* wrapLength,
	const int& x,
	const int& y,
	const SDL_Color& fontColor,
	const SDL_RendererFlip& flip,
	const SDL_Point* rotationPoint,
	const double& angle)
	: Renderable(app) {
	this->fontPath = fontPath;
	this->content = content;
	this->wrapLength = wrapLength != nullptr ? new Uint32(*wrapLength) : nullptr;
	this->positionX = x;
	this->positionY = y;
	this->fontColor = fontColor;
	this->fontSize = fontSize;
	this->flip = flip;
	this->rotationPoint = rotationPoint != nullptr ? new SDL_Point(*rotationPoint) : nullptr;
	this->angle = angle;
}

Text::~Text() {
	this->destroy();
	delete this->wrapLength;
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
		this->app->setRunning(false);
	}

	this->texture = Loader::loadTextureFromSolidUtf8Text(
		renderer,
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);
}

void Text::render() {
	if (!this->visibility) {
		return;
	}

	SDL_Renderer* renderer = this->app->getRenderer();
	SDL_Rect dstRectangle = { this->positionX, this->positionY, this->width, this->height };

	SDL_RenderCopyEx(
		renderer,
		this->texture,
		nullptr,
		&dstRectangle,
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

SDL_Point* Text::getRotationPoint() const {
	return this->rotationPoint != nullptr ? new SDL_Point(*this->rotationPoint) : nullptr;
}

Uint32* Text::getWrapLength() const {
	return this->wrapLength != nullptr ? new Uint32(*this->wrapLength) : nullptr;
}

SDL_Color Text::getFontColor() const {
	return this->fontColor;
}

SDL_RendererFlip Text::getFlip() const {
	return this->flip;
}

std::string Text::getContent() const {
	return this->content;
}

std::string Text::getFontPath() const {
	return this->fontPath;
}

double Text::getAngle() const {
	return this->angle;
}

int Text::getFontSize() const {
	return this->fontSize;
}

int Text::getPositionX() const {
	return this->positionX;
}

int Text::getPositionY() const {
	return this->positionY;
}

int Text::getWidth() const {
	return this->width;
}

int Text::getHeight() const {
	return this->height;
}

void Text::setRotationPoint(const SDL_Point* value) {
	if (this->rotationPoint != nullptr) {
		delete this->rotationPoint;
	}

	if (value != nullptr) {
		this->rotationPoint = new SDL_Point(*value);
	}
	else {
		this->rotationPoint = nullptr;
	}
}

void Text::setWrapLength(const Uint32* value) {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	if (this->wrapLength != nullptr) {
		delete this->wrapLength;
	}

	if (value != nullptr) {
		this->wrapLength = new Uint32(*value);
	}
	else {
		this->wrapLength = nullptr;
	}

	this->texture = Loader::loadTextureFromSolidUtf8Text(
		this->app->getRenderer(),
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);
}

void Text::setFontColor(const SDL_Color& value) {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->fontColor = value;
	
	this->texture = Loader::loadTextureFromSolidUtf8Text(
		this->app->getRenderer(),
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);
}

void Text::setFlip(const SDL_RendererFlip& value) {
	this->flip = value;
}

void Text::setContent(const std::string& value) {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->content = value;
	
	this->texture = Loader::loadTextureFromSolidUtf8Text(
		this->app->getRenderer(),
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);
}

void Text::setFontPath(const std::string& value) {
	this->destroy();
	this->fontPath = value;
	this->init();
}

void Text::setAngle(const double& value) {
	this->angle = value;
}

void Text::setFontSize(const int& value) {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->fontSize = value;

	this->texture = Loader::loadTextureFromSolidUtf8Text(
		this->app->getRenderer(),
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);
}

void Text::setPositionX(const int& value) {
	this->positionX = value;
}

void Text::setPositionY(const int& value) {
	this->positionY = value;
}

void Text::setPosition(const int& x, const int& y) {
	this->positionX = x;
	this->positionY = y;
}
