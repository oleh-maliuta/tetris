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

void Page::input() {
	SDL_Event event;
	int mousePosX, mousePosY;

	SDL_GetMouseState(&mousePosX, &mousePosY);

	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			this->app->setRunning(false);
			break;
		case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				for (auto& el : this->renderables) {
					if (el.second->isCursorIn(mousePosX, mousePosY)) {
						el.second->getOnRelease()();
					}
				}
			}
			break;
		}
		case SDL_KEYDOWN: {
			SDL_Keycode key = event.key.keysym.sym;
			auto it = this->keyDownEvents.find(key);

			if (it != this->keyDownEvents.end()) {
				it->second();
			}
			break;
		}
		case SDL_KEYUP: {
			SDL_Keycode key = event.key.keysym.sym;
			auto it = this->keyUpEvents.find(key);

			if (it != this->keyUpEvents.end()) {
				it->second();
			}
			break;
		}
		}
	}
}

void Page::update() {}

void Page::render() {
	for (auto& el : this->renderables) {
		el.second->render();
	}
}
