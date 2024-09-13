#include "Renderable.h"

Renderable::Renderable(SDL_Renderer* renderer) {
	this->renderer = renderer;
}

Renderable::~Renderable() {}

bool Renderable::isCursorIn(int x, int y) {
	return false;
}

void Renderable::init() {
	this->isInitialized = true;
}

void Renderable::render() {}

void Renderable::destroy() {
	this->isInitialized = false;
}

bool Renderable::getVisibility() const {
	return this->visibility;
}

std::function<void()> Renderable::getOnRelease() const {
	return this->onRelease;
}

void Renderable::setVisibility(const bool& value) {
	this->visibility = value;
}

void Renderable::setOnRelease(const std::function<void()>& value) {
	this->onRelease = value;
}
