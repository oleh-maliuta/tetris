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

	if (!this->app->getIsRunning()) {
		return;
	}

	this->update();

	SDL_Renderer* renderer = this->app->getRenderer();

	SDL_SetRenderDrawColor(
		renderer,
		this->backgroundColor.r,
		this->backgroundColor.g,
		this->backgroundColor.b,
		this->backgroundColor.a);

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
	if (!this->isInitialized) {
		return;
	}

	for (const auto& el : this->renderables) {
		el.second->destroy();
	}

	for (const auto& el : this->regularEvents) {
		SDL_RemoveTimer(el.second);
	}
	this->regularEvents.clear();

	this->isInitialized = false;
}

void Tetris::Page::update() {}

void Tetris::Page::addRenderable(
	const std::string& key,
	Renderable* obj)
{
	this->renderables.push_back(std::pair(key, obj));
}

void Tetris::Page::addRegularEvent(
	const std::string& key,
	Uint32 interval,
	SDL_TimerCallback callback,
	void* param)
{
	const auto it = this->regularEvents.find(key);
	if (it != this->regularEvents.end()) {
		SDL_RemoveTimer(it->second);
	}

	SDL_TimerID timerID = SDL_AddTimer(interval, callback, param);

	this->regularEvents[key] = timerID;
}

void Tetris::Page::removeRegularEvent(
	const std::string& key)
{
	const auto it = this->regularEvents.find(key);
	if (it != this->regularEvents.end()) {
		SDL_RemoveTimer(it->second);
		this->regularEvents.erase(it->first);
	}
}

Tetris::Application* Tetris::Page::getApp() const
{
	return this->app;
}

void Tetris::Page::input()
{
	SDL_Event event;
	int mousePosX, mousePosY;

	SDL_GetMouseState(&mousePosX, &mousePosY);

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			this->app->setIsRunning(false);
		}
		else if (event.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				for (const auto& el : this->renderables) {
					if (el.second && el.second->getVisibility()) {
						if (el.second->isCursorIn(mousePosX, mousePosY)) {
							el.second->getOnRelease()();
						}

						Layout* layout = dynamic_cast<Layout*>(el.second);
						if (layout) {
							for (const auto& obj : layout->objects) {
								if (
									obj.second->getVisibility() &&
									obj.second->isCursorIn(mousePosX, mousePosY))
								{
									obj.second->getOnRelease()();
								}
							}
						}
					}
				}
			}
		}
		else if (event.type == SDL_KEYDOWN) {
			const SDL_Keycode key = event.key.keysym.sym;
			const auto it = this->keyDownEvents.find(key);

			if (it != this->keyDownEvents.end()) {
				it->second();
			}
		}
		else if (event.type == SDL_KEYUP) {
			const SDL_Keycode key = event.key.keysym.sym;
			const auto it = this->keyUpEvents.find(key);

			if (it != this->keyUpEvents.end()) {
				it->second();
			}
		}
		else if (event.type == this->app->EXECUTE_FUNCTION_EVENT) {
			auto func = static_cast<std::function<void()>*>(event.user.data1);
			(*func)();
			delete func;
		}
	}
}

void Tetris::Page::render()
{
	for (const auto& el : this->renderables) {
		el.second->render();
	}
}
