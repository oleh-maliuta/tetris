#include "Renderable.h"

Tetris::Renderable::Renderable(
	SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

Tetris::Renderable::~Renderable() {}

bool Tetris::Renderable::isCursorIn(
	const float& x,
	const float& y)
{
	return false;
}

void Tetris::Renderable::init()
{
	this->isInitialized = true;
}

void Tetris::Renderable::render() {}

void Tetris::Renderable::destroy()
{
	this->isInitialized = false;
}

bool Tetris::Renderable::getVisibility() const
{
	return this->visibility;
}

std::function<void()> Tetris::Renderable::getOnRelease() const
{
	return this->onRelease;
}

void Tetris::Renderable::setVisibility(
	const bool& value)
{
	this->visibility = value;
}

void Tetris::Renderable::setOnRelease(
	const std::function<void()>& value)
{
	this->onRelease = value;
}
