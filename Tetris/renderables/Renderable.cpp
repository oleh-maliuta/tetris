#include "Renderable.h"

Renderable::Renderable(App* app) {
	this->app = app;
}

Renderable::~Renderable() {}

bool Renderable::isCursorIn(int x, int y) {
	return false;
}

void Renderable::init() {}

void Renderable::render() {}

void Renderable::destroy() {}

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
