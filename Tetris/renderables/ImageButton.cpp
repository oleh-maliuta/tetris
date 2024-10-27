#include "ImageButton.h"

Tetris::ImageButton::ImageButton(
	SDL_Renderer* renderer,
	const std::string& imagePath,
	const float& x,
	const float& y,
	const SDL_Color& bodyColor,
	const float& paddingTop,
	const float& paddingBottom,
	const float& paddingLeft,
	const float& paddingRight,
	const float* width,
	const float* height,
	const SDL_Color& imageModuleColor)
	: Renderable(renderer)
{
	this->imagePath = imagePath;
	this->positionX = x;
	this->positionY = y;
	this->bodyColor = bodyColor;
	this->paddingTop = paddingTop;
	this->paddingBottom = paddingBottom;
	this->paddingLeft = paddingLeft;
	this->paddingRight = paddingRight;
	this->imageWidth = width != nullptr ? new float(*width) : nullptr;
	this->imageHeight = height != nullptr ? new float(*height) : nullptr;
	this->moduleRed = imageModuleColor.r;
	this->moduleGreen = imageModuleColor.g;
	this->moduleBlue = imageModuleColor.b;

	Loader::getImageSize(
		imagePath.c_str(),
		&this->defaultImageWidth,
		&this->defaultImageHeight);
}

Tetris::ImageButton::~ImageButton()
{
	this->destroy();
	delete this->imageWidth;
	delete this->imageHeight;
}

bool Tetris::ImageButton::isCursorIn(
	const float& x,
	const float& y)
{
	const float posX = this->getPositionX();
	const float posY = this->getPositionY();

	return
		x >= posX && x < posX + this->getWidth() &&
		y >= posY && y < posY + this->getHeight();
}

void Tetris::ImageButton::init()
{
	if (this->isInitialized) {
		return;
	}

	this->texture = Loader::getTextureFromImage(
		this->renderer,
		this->imagePath.c_str());

	Renderable::init();
}

void Tetris::ImageButton::render()
{
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	const float bodyWidth = this->getWidth();
	const float bodyHeight = this->getHeight();
	const float imageWidth = this->getImageWidth();
	const float imageHeight = this->getImageHeight();

	SDL_FRect body = {
		this->positionX,
		this->positionY,
		bodyWidth,
		bodyHeight
	};
	SDL_FRect imageRectangle = {
		body.x + bodyWidth / 2 - imageWidth / 2,
		body.y + bodyHeight / 2 - imageHeight / 2,
		imageWidth,
		imageHeight
	};

	SDL_SetRenderDrawColor(
		this->renderer,
		this->bodyColor.r,
		this->bodyColor.g,
		this->bodyColor.b,
		this->bodyColor.a);
	SDL_RenderFillRectF(
		this->renderer,
		&body);
	SDL_RenderCopyF(
		this->renderer,
		this->texture,
		nullptr,
		&imageRectangle);
	SDL_SetTextureColorMod(
		this->texture,
		this->moduleRed,
		this->moduleGreen,
		this->moduleBlue);

	Renderable::render();
}

void Tetris::ImageButton::destroy()
{
	if (!this->isInitialized) {
		return;
	}

	Renderable::destroy();
}

SDL_Color Tetris::ImageButton::getBodyColor() const
{
	return this->bodyColor;
}

float Tetris::ImageButton::getPositionX() const
{
	return this->positionX;
}

float Tetris::ImageButton::getPositionY() const
{
	return this->positionY;
}

float Tetris::ImageButton::getImageWidth() const
{
	return this->imageWidth != nullptr ? *this->imageWidth : this->defaultImageWidth;
}

float Tetris::ImageButton::getImageHeight() const
{
	return this->imageHeight != nullptr ? *this->imageHeight : this->defaultImageHeight;
}

float Tetris::ImageButton::getWidth() const
{
	return (this->imageWidth != nullptr ? *this->imageWidth : this->defaultImageWidth)
		+ this->paddingLeft + this->paddingRight;
}

float Tetris::ImageButton::getHeight() const
{
	return (this->imageHeight != nullptr ? *this->imageHeight : this->defaultImageHeight)
		+ this->paddingTop + this->paddingBottom;
}

void Tetris::ImageButton::setBodyColor(
	const SDL_Color& value)
{
	this->bodyColor = value;
}

void Tetris::ImageButton::setPositionX(
	const float& value)
{
	this->positionX = value;
}

void Tetris::ImageButton::setPositionY(
	const float& value)
{
	this->positionY = value;
}

void Tetris::ImageButton::setImageWidth(
	const float* value)
{
	delete this->imageWidth;
	this->imageWidth = nullptr;

	if (value != nullptr) {
		this->imageWidth = new float(*value);
	}
}

void Tetris::ImageButton::setImageHeight(
	const float* value)
{
	delete this->imageHeight;
	this->imageHeight = nullptr;

	if (value != nullptr) {
		this->imageHeight = new float(*value);
	}
}
