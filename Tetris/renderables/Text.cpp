#include "Text.h"

Tetris::Text::Text(
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
	: Renderable(renderer)
{
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

Tetris::Text::~Text()
{
	this->destroy();
	delete this->wrapLength;
	delete this->rotationPoint;
}

bool Tetris::Text::isCursorIn(
	const float& x,
	const float& y)
{
	return
		x >= this->positionX && x < this->positionX + this->width &&
		y >= this->positionY && y < this->positionY + this->height;
}

void Tetris::Text::init()
{
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

	this->texture = Loader::getTextureOfUtf8Text(
		this->renderer,
		this->font,
		this->fontColor,
		this->content.c_str(),
		this->wrapLength,
		&this->width,
		&this->height);

	Renderable::init();
}

void Tetris::Text::render()
{
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

void Tetris::Text::destroy()
{
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

SDL_FPoint* Tetris::Text::getRotationPoint() const
{
	return this->rotationPoint != nullptr ?
		new SDL_FPoint(*this->rotationPoint) :
		nullptr;
}

Uint32* Tetris::Text::getWrapLength() const
{
	return this->wrapLength != nullptr ?
		new Uint32(*this->wrapLength) :
		nullptr;
}

SDL_Color Tetris::Text::getFontColor() const
{
	return this->fontColor;
}

SDL_RendererFlip Tetris::Text::getFlip() const
{
	return this->flip;
}

std::string Tetris::Text::getContent() const
{
	return this->content;
}

std::string Tetris::Text::getFontPath() const
{
	return this->fontPath;
}

double Tetris::Text::getAngle() const
{
	return this->angle;
}

float Tetris::Text::getPositionX() const
{
	return this->positionX;
}

float Tetris::Text::getPositionY() const
{
	return this->positionY;
}

float Tetris::Text::getWidth() const
{
	return this->width;
}

float Tetris::Text::getHeight() const
{
	return this->height;
}

int Tetris::Text::getFontSize() const
{
	return this->fontSize;
}

void Tetris::Text::setRotationPoint(
	const SDL_FPoint* value)
{
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

void Tetris::Text::setWrapLength(
	const Uint32* value)
{
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
		this->texture = Loader::getTextureOfUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
}

void Tetris::Text::setFontColor(
	const SDL_Color& value)
{
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->fontColor = value;
	
	if (this->isInitialized) {
		this->texture = Loader::getTextureOfUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
}

void Tetris::Text::setFlip(
	const SDL_RendererFlip& value)
{
	this->flip = value;
}

void Tetris::Text::setContent(
	const std::string& value)
{
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->content = value;
	
	if (this->isInitialized) {
		this->texture = Loader::getTextureOfUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
}

void Tetris::Text::setFontPath(
	const std::string& value)
{
	this->destroy();
	this->fontPath = value;
	this->init();
}

void Tetris::Text::setAngle(
	const double& value)
{
	this->angle = value;
}

void Tetris::Text::setPositionX(
	const float& value)
{
	this->positionX = value;
}

void Tetris::Text::setPositionY(
	const float& value)
{
	this->positionY = value;
}

void Tetris::Text::setFontSize(
	const int& value)
{
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->fontSize = value;

	if (this->isInitialized) {
		this->texture = Loader::getTextureOfUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			this->wrapLength,
			&this->width,
			&this->height);
	}
}
