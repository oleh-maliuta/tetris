#include "TextButton.h"

Tetris::TextButton::TextButton(
	SDL_Renderer* renderer,
	const std::string& fontPath,
	const std::string& content,
	const int& fontSize,
	const float& width,
	const float& height,
	const float& x,
	const float& y,
	const SDL_Color& bodyColor,
	const SDL_Color& fontColor,
	const float& paddingLeft,
	const float& paddingRight)
	: Renderable(renderer)
{
	this->fontPath = fontPath;
	this->content = content;
	this->fontSize = fontSize;
	this->bodyWidth = width;
	this->bodyHeight = height;
	this->positionX = x;
	this->positionY = y;
	this->bodyColor = bodyColor;
	this->fontColor = fontColor;
	this->paddingLeft = paddingLeft;
	this->paddingRight = paddingRight;
}

Tetris::TextButton::~TextButton()
{
	this->destroy();
}

bool Tetris::TextButton::isCursorIn(
	const float& x,
	const float& y)
{
	return
		x >= this->positionX && x < this->positionX + this->bodyWidth &&
		y >= this->positionY && y < this->positionY + this->bodyHeight;
}

void Tetris::TextButton::init()
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

	Uint32 textWrap = static_cast<Uint32>(
		this->bodyWidth - this->paddingLeft - this->paddingRight);

	this->textTexture = Loader::getTextureFromUtf8Text(
		this->renderer,
		this->font,
		this->fontColor,
		this->content.c_str(),
		&textWrap,
		&this->textWidth,
		&this->textHeight);

	Renderable::init();
}

void Tetris::TextButton::render()
{
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	SDL_FRect body = { this->positionX, this->positionY, this->bodyWidth, this->bodyHeight };
	SDL_FRect textRectangle = {
		body.x + this->bodyWidth / 2 - this->textWidth / 2,
		body.y + this->bodyHeight / 2 - this->textHeight / 2,
		this->textWidth,
		this->textHeight
	};

	SDL_SetRenderDrawColor(this->renderer, this->bodyColor.r, this->bodyColor.g, this->bodyColor.b, this->bodyColor.a);
	SDL_RenderFillRectF(this->renderer, &body);
	SDL_RenderCopyF(this->renderer, this->textTexture, nullptr, &textRectangle);

	Renderable::render();
}

void Tetris::TextButton::destroy()
{
	if (!this->isInitialized) {
		return;
	}

	if (this->font != nullptr) {
		TTF_CloseFont(this->font);
		this->font = nullptr;
	}

	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	Renderable::destroy();
}

SDL_Color Tetris::TextButton::getBodyColor() const
{
	return this->bodyColor;
}

SDL_Color Tetris::TextButton::getFontColor() const
{
	return this->fontColor;
}

std::string Tetris::TextButton::getContent() const
{
	return this->content;
}

std::string Tetris::TextButton::getFontPath() const
{
	return this->fontPath;
}

int Tetris::TextButton::getFontSize() const
{
	return this->fontSize;
}

float Tetris::TextButton::getPositionX() const
{
	return this->positionX;
}

float Tetris::TextButton::getPositionY() const
{
	return this->positionY;
}

float Tetris::TextButton::getBodyWidth() const
{
	return this->bodyWidth;
}

float Tetris::TextButton::getBodyHeight() const
{
	return this->bodyHeight;
}

float Tetris::TextButton::getTextWidth() const
{
	return this->textWidth;
}

float Tetris::TextButton::getTextHeight() const
{
	return this->textHeight;
}

float Tetris::TextButton::getPaddingLeft() const
{
	return this->paddingLeft;
}

float Tetris::TextButton::getPaddingRight() const
{
	return this->paddingRight;
}

void Tetris::TextButton::setBodyColor(
	const SDL_Color& value)
{
	this->bodyColor = value;
}

void Tetris::TextButton::setFontColor(
	const SDL_Color& value)
{
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->fontColor = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void Tetris::TextButton::setContent(
	const std::string& value)
{
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->content = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void Tetris::TextButton::setFontPath(
	const std::string& value)
{
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->fontPath = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void Tetris::TextButton::setFontSize(
	const int& value)
{
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->fontSize = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void Tetris::TextButton::setPositionX(
	const float& value)
{
	this->positionX = value;
}

void Tetris::TextButton::setPositionY(
	const float& value)
{
	this->positionY = value;
}

void Tetris::TextButton::setBodyWidth(
	const float& value)
{
	this->bodyWidth = value;
}

void Tetris::TextButton::setBodyHeight(
	const float& value)
{
	this->bodyHeight = value;
}

void Tetris::TextButton::setPaddingLeft(
	const float& value)
{
	this->paddingLeft = value;
}

void Tetris::TextButton::setPaddingRight(
	const float& value)
{
	this->paddingRight = value;
}
