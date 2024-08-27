#include "Renderable.h"

Renderable::Renderable(App* app) {
	this->app = app;
}

Renderable::~Renderable() {}

void Renderable::init() {}

void Renderable::render() {}

void Renderable::destroy() {}

bool Renderable::getVisibility() const {
	return this->visibility;
}

void Renderable::setVisibility(const bool& value) {
	this->visibility = value;
}
