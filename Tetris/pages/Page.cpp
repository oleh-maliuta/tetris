#include "Page.h"

Tetris::Page::Page(
	Application* app)
{
	this->app = app;
}

Tetris::Page::~Page()
{
	for (const auto& el : this->renderables) {
		delete el.second;
	}
}

void Tetris::Page::exec()
{
	this->input();
	this->update();

	SDL_Renderer* renderer = this->app->getRenderer();

	SDL_SetRenderDrawColor(
		renderer,
		backgroundColor.r,
		backgroundColor.g,
		backgroundColor.b,
		backgroundColor.a);

	SDL_RenderClear(renderer);
	this->render();
	SDL_RenderPresent(renderer);
}

void Tetris::Page::init()
{
	for (const auto& el : this->renderables) {
		el.second->init();
	}

	this->isInitialized = true;
}

void Tetris::Page::clean()
{
	for (const auto& el : this->renderables) {
		el.second->destroy();
	}

	this->isInitialized = false;
}

void Tetris::Page::input()
{
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
				for (const auto& el : this->renderables) {
					if (el.second->isCursorIn(mousePosX, mousePosY)) {
						el.second->getOnRelease()();
					}
				}
			}
			break;
		}
		case SDL_KEYDOWN: {
			const SDL_Keycode key = event.key.keysym.sym;
			const auto it = this->keyDownEvents.find(key);

			if (it != this->keyDownEvents.end()) {
				it->second();
			}
			break;
		}
		case SDL_KEYUP: {
			const SDL_Keycode key = event.key.keysym.sym;
			const auto it = this->keyUpEvents.find(key);

			if (it != this->keyUpEvents.end()) {
				it->second();
			}
			break;
		}
		}
	}
}

void Tetris::Page::update() {}

void Tetris::Page::render()
{
	for (const auto& el : this->renderables) {
		el.second->render();
	}
}

void Tetris::Page::addRenderable(
	const std::string& key,
	Renderable* obj)
{
	this->renderables.push_back(std::pair(key, obj));
}

Tetris::Renderable* Tetris::Page::getRenderable(
	const std::string& key)
{
	for (const auto& el : this->renderables) {
		if (el.first == key) {
			return el.second;
		}
	}

	return nullptr;
}
