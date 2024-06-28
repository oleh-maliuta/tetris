#include "MainMenuPage.h"
#include "Loader.h"

MainMenuPage::MainMenuPage(App* app) : Page(app) {
	this->logoRect = {
		App::APP_WINDOW_WIDTH / 2 - 78,
		100,
		156,
		34
	};
}

void MainMenuPage::init() {
	if (this->initialized) {
		return;
	}
	this->logoTexture = Loader::loadTexture(
		this->app->getRenderer(),
		"assets/game_logo.png");
	Page::init();
}

void MainMenuPage::clean() {
	if (!this->initialized) {
		return;
	}
	SDL_DestroyTexture(this->logoTexture);
	this->logoTexture = NULL;
	Page::clean();
}

void MainMenuPage::input() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			this->app->isRunning = false;
			break;
		}
	}
}

void MainMenuPage::update() {
	
}

void MainMenuPage::render() {
	SDL_Renderer* renderer = this->app->getRenderer();
	SDL_RenderCopy(renderer, this->logoTexture, NULL, &this->logoRect);
}
