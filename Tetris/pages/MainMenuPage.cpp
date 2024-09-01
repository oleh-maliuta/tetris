#include "MainMenuPage.h"

MainMenuPage::MainMenuPage(App* app)
	: Page(app) {
	this->renderables["logo__texture"] = new Texture(
		this->app,
		"assets/images/png/game_logo.png",
		nullptr,
		new SDL_Rect{ this->app->getWindowWidth() / 2 - 78,100,156,34 });

	Uint32 uint32WindowWidth = static_cast<Uint32>(this->app->getWindowWidth());

	this->renderables["version_info__text"] = new Text(
		this->app,
		"assets/fonts/open_sans/normal.ttf",
		this->app->getVersion(),
		15,
		&uint32WindowWidth);

	this->renderables["quit__text_button"] = new TextButton(
		this->app,
		"assets/fonts/swansea/normal.ttf",
		"Quit",
		30,
		250,
		86,
		this->app->getWindowWidth() / 2 - 125,
		200,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);
}

void MainMenuPage::init() {
	if (this->isInitialized) {
		return;
	}

	Page::init();
}

void MainMenuPage::clean() {
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
}

void MainMenuPage::input() {
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			this->app->setRunning(false);
			break;
		}
	}
}

void MainMenuPage::update() {
	
}

void MainMenuPage::render() {
	if (!this->isInitialized) {
		return;
	}

	Page::render();
}
