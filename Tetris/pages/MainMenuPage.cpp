#include "MainMenuPage.h"

MainMenuPage::MainMenuPage(App* app) : Page(app) {
	this->logo = new Texture(
		this->app,
		"assets/images/png/game_logo.png");
	this->logo->srcrect = nullptr;
	this->logo->dstrect = new SDL_Rect{ this->app->windowWidth / 2 - 78,100,156,34 };

	this->versionInfo = new Text(this->app, "assets/fonts/swansea.ttf", this->app->version, { 0, 0, 0 }, 18, this->app->windowWidth);
}

MainMenuPage::~MainMenuPage() {
	delete this->logo;
	delete this->versionInfo;
	this->logo = nullptr;
	this->versionInfo = nullptr;
}

void MainMenuPage::init() {
	if (this->initialized) {
		return;
	}

	SDL_Renderer* renderer = this->app->getRenderer();

	this->logo->init();
	this->versionInfo->init();

	Page::init();
}

void MainMenuPage::clean() {
	if (!this->initialized) {
		return;
	}

	this->logo->destroy();
	this->versionInfo->destroy();

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
	this->versionInfo->render();
}
