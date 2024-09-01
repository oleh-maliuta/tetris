#include "TextButton.h"

TextButton::TextButton(
	App* app,
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
	: Renderable(app) {
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

void TextButton::init() {
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

	Uint32 textWrap = static_cast<Uint32>(
		this->bodyWidth - this->paddingLeft - this->paddingRight);

	this->textTexture = Loader::loadTextureFromSolidUtf8Text(
		renderer,
		this->font,
		this->fontColor,
		this->content.c_str(),
		&textWrap,
		&this->textWidth,
		&this->textHeight);
}

void TextButton::render() {
	if (!this->visibility) {
		return;
	}

	SDL_Renderer* renderer = this->app->getRenderer();
	SDL_Rect body = { this->positionX, this->positionY, this->bodyWidth, this->bodyHeight };
	SDL_Rect textRectangle = {
		this->bodyWidth / 2 - this->textWidth / 2,
		this->bodyHeight / 2 - this->textHeight / 2,
		this->textWidth,
		this->textHeight
	};

	SDL_SetRenderDrawColor(renderer, this->bodyColor.r, this->bodyColor.g, this->bodyColor.b, this->bodyColor.a);
	SDL_RenderSetViewport(renderer, &body);
	SDL_RenderFillRect(renderer, nullptr);

	SDL_RenderCopy(
		renderer,
		this->textTexture,
		nullptr,
		&textRectangle);

	SDL_RenderSetViewport(renderer, nullptr);
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
}
