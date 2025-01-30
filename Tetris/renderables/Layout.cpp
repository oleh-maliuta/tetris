#include "Layout.h"

Tetris::Layout::Layout(
	SDL_Renderer* renderer,
	const float& width,
	const float& height,
	const float& x,
	const float& y,
	const SDL_Color& backgroundColor,
	const std::list<std::pair<std::string, Renderable*>> objects)
	: Renderable(renderer)
{
	this->width = width;
	this->height = height;
	this->positionX = x;
	this->positionY = y;
	this->backgroundColor = backgroundColor;
	this->objects = objects;
}

Tetris::Layout::~Layout()
{
	this->destroy();

	for (auto& object : this->objects) {
		delete object.second;
	}
}

bool Tetris::Layout::isCursorIn(
	const float& x,
	const float& y)
{
	const float posX = this->getPositionX();
	const float posY = this->getPositionY();

	return
		x >= posX && x < posX + this->getWidth() &&
		y >= posY && y < posY + this->getHeight();
}

void Tetris::Layout::init()
{
	if (this->isInitialized) {
		return;
	}

	for (auto& object : this->objects) {
		object.second->init();
	}

	Renderable::init();
}

void Tetris::Layout::render()
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
		this->backgroundColor.r,
		this->backgroundColor.g,
		this->backgroundColor.b,
		this->backgroundColor.a);
	SDL_RenderFillRectF(
		this->renderer,
		&body);

	for (auto& object : this->objects) {
		object.second->render();
	}

	Renderable::render();
}

void Tetris::Layout::destroy()
{
	if (!this->isInitialized) {
		return;
	}

	for (auto& object : this->objects) {
		object.second->destroy();
	}

	Renderable::destroy();
}

SDL_Color Tetris::Layout::getBackgroundColor() const
{
	return this->backgroundColor;
}

float Tetris::Layout::getPositionX() const
{
	return this->positionX;
}

float Tetris::Layout::getPositionY() const
{
	return this->positionY;
}

float Tetris::Layout::getWidth() const
{
	return this->width;
}

float Tetris::Layout::getHeight() const
{
	return this->height;
}

void Tetris::Layout::setBackgroundColor(
	const SDL_Color& value)
{
	this->backgroundColor = value;
}

void Tetris::Layout::setPositionX(
	const float& value)
{
	this->positionX = value;
}

void Tetris::Layout::setPositionY(
	const float& value)
{
	this->positionY = value;
}

void Tetris::Layout::setWidth(
	const float& value)
{
	this->width = value;
}

void Tetris::Layout::setHeight(
	const float& value)
{
	this->height = value;
}
