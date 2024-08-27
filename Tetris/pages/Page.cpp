#include "Page.h"

Page::Page(App* app) {
	this->app = app;
}

Page::~Page() {
	for (auto& el : this->renderables) {
		delete el.second;
	}
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
	for (auto& el : this->renderables) {
		el.second->init();
	}

	this->isInitialized = true;
}

void Page::clean() {
	for (auto& el : this->renderables) {
		el.second->destroy();
	}

	this->isInitialized = false;
}

void Page::input() {}

void Page::update() {}

void Page::render() {
	for (auto& el : this->renderables) {
		el.second->render();
	}
}
