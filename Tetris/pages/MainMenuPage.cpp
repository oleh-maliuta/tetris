#include "MainMenuPage.h"

MainMenuPage::MainMenuPage(App* app)
	: Page(app) {
	App* appRef = this->app;
	Uint32 versionInfoTextWrap = static_cast<Uint32>(this->app->getWindowWidth()) - 6;

	Texture* logo__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/game_logo.png",
		this->app->getWindowWidth() / 2 - 78,
		100);

	Text* version_info__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/normal.ttf",
		this->app->getVersion(),
		15,
		&versionInfoTextWrap,
		3,
		this->app->getWindowHeight() - 20);

	TextButton* settings__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/normal.ttf",
		"Settings",
		30,
		250,
		86,
		this->app->getWindowWidth() / 2 - 125,
		200,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	TextButton* quit__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/normal.ttf",
		"Quit",
		30,
		250,
		86,
		this->app->getWindowWidth() / 2 - 125,
		320,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	this->renderables["logo__texture"] = logo__texture;
	this->renderables["version_info__text"] = version_info__text;
	this->renderables["settings__text_button"] = settings__text_button;
	this->renderables["quit__text_button"] = quit__text_button;

	settings__text_button->setOnRelease([appRef] { appRef->changePage("settings"); });
	quit__text_button->setOnRelease([appRef] { appRef->setRunning(false); });
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
	Page::input();
}

void MainMenuPage::update() {
	Page::update();
}

void MainMenuPage::render() {
	if (!this->isInitialized) {
		return;
	}

	Page::render();
}
