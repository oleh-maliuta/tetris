#include "Page.h"

Page::Page(App* app) {
	this->app = app;
}

void Page::exec() {
	this->input();
	this->update();

	SDL_Renderer* renderer = this->app->getRenderer();
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	this->render();
	SDL_RenderPresent(renderer);
}

void Page::init() {
	this->initialized = true;
}

void Page::clean() {
	this->initialized = false;
}

void Page::input() {}

void Page::update() {}

void Page::render() {}
