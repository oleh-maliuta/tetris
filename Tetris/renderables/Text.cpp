#include "Text.h"

Text::Text(
	SDL_Renderer* renderer,
	const std::string& fontPath,
	const std::string& content,
	const int& fontSize,
	const Uint32* wrapLength,
	const float& x,
	const float& y,
	const SDL_Color& fontColor,
	const SDL_RendererFlip& flip,
	const SDL_FPoint* rotationPoint,
	const double& angle)
	: Renderable(renderer) {
	this->fontPath = fontPath;
	this->content = content;
	this->wrapLength = wrapLength != nullptr ? new Uint32(*wrapLength) : nullptr;
	this->positionX = x;
	this->positionY = y;
	this->fontColor = fontColor;
	this->fontSize = fontSize;
	this->flip = flip;
	this->rotationPoint = rotationPoint != nullptr ? new SDL_FPoint(*rotationPoint) : nullptr;
	this->angle = angle;

	TTF_Font* testFont = TTF_OpenFont(
		this->fontPath.c_str(),
		this->fontSize);

	Loader::getUtf8TextSize(
		testFont,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);

	TTF_CloseFont(testFont);
}

Text::~Text() {
	this->destroy();
	delete this->wrapLength;
	delete this->rotationPoint;
}

bool Text::isCursorIn(
	const float& x,
	const float& y) {
	return
		x >= this->positionX && x < this->positionX + this->width &&
		y >= this->positionY && y < this->positionY + this->height;
}

void Text::init() {
	if (this->isInitialized) {
		return;
	}

	this->font = TTF_OpenFont(
		this->fontPath.c_str(),
		this->fontSize);

	if (this->font == nullptr)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n",
			TTF_GetError());
	}

	this->texture = Loader::getTextureFromSolidUtf8Text(
		this->renderer,
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);

	Renderable::init();
}

void Text::render() {
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	SDL_FRect dstRectangle = { this->positionX, this->positionY, this->width, this->height };

	SDL_RenderCopyExF(
		this->renderer,
		this->texture,
		nullptr,
		&dstRectangle,
		this->angle,
		this->rotationPoint,
		this->flip);

	Renderable::render();
}

void Text::destroy() {
	if (!this->isInitialized) {
		return;
	}

	if (this->font != nullptr) {
		TTF_CloseFont(this->font);
		this->font = nullptr;
	}

	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	Renderable::destroy();
}

SDL_FPoint* Text::getRotationPoint() const {
	return this->rotationPoint != nullptr ? new SDL_FPoint(*this->rotationPoint) : nullptr;
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

float Text::getPositionX() const {
	return this->positionX;
}

float Text::getPositionY() const {
	return this->positionY;
}

float Text::getWidth() const {
	return this->width;
}

float Text::getHeight() const {
	return this->height;
}

int Text::getFontSize() const {
	return this->fontSize;
}

void Text::setRotationPoint(const SDL_FPoint* value) {
	if (this->rotationPoint != nullptr) {
		delete this->rotationPoint;
	}

	if (value != nullptr) {
		this->rotationPoint = new SDL_FPoint(*value);
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

	if (this->isInitialized) {
		this->texture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
}

void Text::setFontColor(const SDL_Color& value) {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->fontColor = value;
	
	if (this->isInitialized) {
		this->texture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
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
	
	if (this->isInitialized) {
		this->texture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
}

void Text::setFontPath(const std::string& value) {
	this->destroy();
	this->fontPath = value;
	this->init();
}

void Text::setAngle(const double& value) {
	this->angle = value;
}

void Text::setPositionX(const float& value) {
	this->positionX = value;
}

void Text::setPositionY(const float& value) {
	this->positionY = value;
}

void Text::setFontSize(const int& value) {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->fontSize = value;

	if (this->isInitialized) {
		this->texture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
}
