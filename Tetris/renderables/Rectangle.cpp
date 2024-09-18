#include "Rectangle.h"

Rectangle::Rectangle(
	SDL_Renderer* renderer,
	const float& width,
	const float& height,
	const float& x,
	const float& y,
	const SDL_Color& color)
	: Renderable(renderer) {
	this->width = width;
	this->height = height;
	this->positionX = x;
	this->positionY = y;
	this->color = color;
}

Rectangle::~Rectangle() {
	this->destroy();
}

bool Rectangle::isCursorIn(
	const float& x,
	const float& y) {
	const float posX = this->getPositionX();
	const float posY = this->getPositionY();

	return
		x >= posX && x < posX + this->getWidth() &&
		y >= posY && y < posY + this->getHeight();
}

void Rectangle::init() {
	if (this->isInitialized) {
		return;
	}

	Renderable::init();
}

void Rectangle::render() {
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	SDL_FRect body = {
		this->positionX,
		this->positionY,
		this->width,
		this->height
	};

	SDL_SetRenderDrawColor(this->renderer, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRectF(this->renderer, &body);

	Renderable::render();
}

void Rectangle::destroy() {
	if (!this->isInitialized) {
		return;
	}

	Renderable::destroy();
}

SDL_Color Rectangle::getColor() const {
	return this->color;
}

float Rectangle::getPositionX() const {
	return this->positionX;
}

float Rectangle::getPositionY() const {
	return this->positionY;
}

float Rectangle::getWidth() const {
	return this->width;
}

float Rectangle::getHeight() const {
	return this->height;
}

void Rectangle::setColor(const SDL_Color& value) {
	this->color = value;
}

void Rectangle::setPositionX(const float& value) {
	this->positionX = value;
}

void Rectangle::setPositionY(const float& value) {
	this->positionY = value;
}

void Rectangle::setWidth(const float& value) {
	this->width = value;
}

void Rectangle::setHeight(const float& value) {
	this->height = value;
}
