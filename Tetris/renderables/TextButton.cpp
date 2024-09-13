#include "TextButton.h"

TextButton::TextButton(
	SDL_Renderer* renderer,
	const std::string& fontPath,
	const std::string& content,
	const int& fontSize,
	const int& width,
	const int& height,
	const int& x,
	const int& y,
	const SDL_Color& bodyColor,
	const SDL_Color& fontColor,
	const int& paddingLeft,
	const int& paddingRight)
	: Renderable(renderer) {
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

TextButton::~TextButton() {
	this->destroy();
}

bool TextButton::isCursorIn(int x, int y) {
	return
		x >= this->positionX && x < this->positionX + this->bodyWidth &&
		y >= this->positionY && y < this->positionY + this->bodyHeight;
}

void TextButton::init() {
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

	this->textTexture = Loader::getTextureFromSolidUtf8Text(
		this->renderer,
		this->font,
		this->fontColor,
		this->content.c_str(),
		&textWrap,
		&this->textWidth,
		&this->textHeight);

	Renderable::init();
}

void TextButton::render() {
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	SDL_Rect body = { this->positionX, this->positionY, this->bodyWidth, this->bodyHeight };
	SDL_Rect textRectangle = {
		this->bodyWidth / 2 - this->textWidth / 2,
		this->bodyHeight / 2 - this->textHeight / 2,
		this->textWidth,
		this->textHeight
	};

	SDL_SetRenderDrawColor(this->renderer, this->bodyColor.r, this->bodyColor.g, this->bodyColor.b, this->bodyColor.a);
	SDL_RenderSetViewport(this->renderer, &body);
	SDL_RenderFillRect(this->renderer, nullptr);
	SDL_RenderCopy(this->renderer, this->textTexture, nullptr, &textRectangle);
	SDL_RenderSetViewport(this->renderer, nullptr);

	Renderable::render();
}

void TextButton::destroy() {
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

SDL_Color TextButton::getBodyColor() const {
	return this->bodyColor;
}

SDL_Color TextButton::getFontColor() const {
	return this->fontColor;
}

std::string TextButton::getContent() const {
	return this->content;
}

std::string TextButton::getFontPath() const {
	return this->fontPath;
}

int TextButton::getFontSize() const {
	return this->fontSize;
}

int TextButton::getPositionX() const {
	return this->positionX;
}

int TextButton::getPositionY() const {
	return this->positionY;
}

int TextButton::getBodyWidth() const {
	return this->bodyWidth;
}

int TextButton::getBodyHeight() const {
	return this->bodyHeight;
}

int TextButton::getTextWidth() const {
	return this->textWidth;
}

int TextButton::getTextHeight() const {
	return this->textHeight;
}

int TextButton::getPaddingLeft() const {
	return this->paddingLeft;
}

int TextButton::getPaddingRight() const {
	return this->paddingRight;
}

void TextButton::setBodyColor(const SDL_Color& value) {
	this->bodyColor = value;
}

void TextButton::setFontColor(const SDL_Color& value) {
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->fontColor = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void TextButton::setContent(const std::string& value) {
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->content = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void TextButton::setFontPath(const std::string& value) {
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->fontPath = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void TextButton::setFontSize(const int& value) {
	if (this->textTexture != nullptr) {
		SDL_DestroyTexture(this->textTexture);
		this->textTexture = nullptr;
	}

	this->fontSize = value;

	if (this->isInitialized) {
		Uint32 textWrap = static_cast<Uint32>(
			this->bodyWidth - this->paddingLeft - this->paddingRight);

		this->textTexture = Loader::getTextureFromSolidUtf8Text(
			this->renderer,
			this->font,
			this->fontColor,
			this->content.c_str(),
			&textWrap,
			&this->textWidth,
			&this->textHeight);
	}
}

void TextButton::setPositionX(const int& value) {
	this->positionX = value;
}

void TextButton::setPositionY(const int& value) {
	this->positionY = value;
}

void TextButton::setBodyWidth(const int& value) {
	this->bodyWidth = value;
}

void TextButton::setBodyHeight(const int& value) {
	this->bodyHeight = value;
}

void TextButton::setPaddingLeft(const int& value) {
	this->paddingLeft = value;
}

void TextButton::setPaddingRight(const int& value) {
	this->paddingRight = value;
}
