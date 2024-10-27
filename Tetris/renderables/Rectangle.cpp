#include "Rectangle.h"

Tetris::Rectangle::Rectangle(
	SDL_Renderer* renderer,
	const float& width,
	const float& height,
	const float& x,
	const float& y,
	const SDL_Color& color)
	: Renderable(renderer)
{
	this->width = width;
	this->height = height;
	this->positionX = x;
	this->positionY = y;
	this->color = color;
}

Tetris::Rectangle::~Rectangle()
{
	this->destroy();
}

bool Tetris::Rectangle::isCursorIn(
	const float& x,
	const float& y)
{
	const float posX = this->getPositionX();
	const float posY = this->getPositionY();

	return
		x >= posX && x < posX + this->getWidth() &&
		y >= posY && y < posY + this->getHeight();
}

void Tetris::Rectangle::init()
{
	if (this->isInitialized) {
		return;
	}

	Renderable::init();
}

void Tetris::Rectangle::render()
{
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	SDL_FRect body = {
		this->positionX,
		this->positionY,
		this->width,
		this->height
	};

	SDL_SetRenderDrawColor(
		this->renderer,
		this->color.r,
		this->color.g,
		this->color.b,
		this->color.a);
	SDL_RenderFillRectF(
		this->renderer,
		&body);

	Renderable::render();
}

void Tetris::Rectangle::destroy()
{
	if (!this->isInitialized) {
		return;
	}

	Renderable::destroy();
}

SDL_Color Tetris::Rectangle::getColor() const
{
	return this->color;
}

float Tetris::Rectangle::getPositionX() const
{
	return this->positionX;
}

float Tetris::Rectangle::getPositionY() const
{
	return this->positionY;
}

float Tetris::Rectangle::getWidth() const
{
	return this->width;
}

float Tetris::Rectangle::getHeight() const
{
	return this->height;
}

void Tetris::Rectangle::setColor(
	const SDL_Color& value)
{
	this->color = value;
}

void Tetris::Rectangle::setPositionX(
	const float& value)
{
	this->positionX = value;
}

void Tetris::Rectangle::setPositionY(
	const float& value)
{
	this->positionY = value;
}

void Tetris::Rectangle::setWidth(
	const float& value)
{
	this->width = value;
}

void Tetris::Rectangle::setHeight(
	const float& value)
{
	this->height = value;
}
