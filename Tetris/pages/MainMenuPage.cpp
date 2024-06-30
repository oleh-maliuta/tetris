#include "MainMenuPage.h"

MainMenuPage::MainMenuPage(App* app) : Page(app) {
	this->logo = new Texture(
		this->app,
		"assets/images/png/game_logo.png",
		nullptr,
		new SDL_Rect{ App::APP_WINDOW_WIDTH / 2 - 78,100,156,34 });
}

MainMenuPage::~MainMenuPage() {
	delete this->logo;
}

void MainMenuPage::init() {
	if (this->initialized) {
		return;
	}

	SDL_Renderer* renderer = this->app->getRenderer();

	this->logo->init();

	Page::init();
}

void MainMenuPage::clean() {
	if (!this->initialized) {
		return;
	}

	this->logo->destroy();

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
	this->logo->render();
}
