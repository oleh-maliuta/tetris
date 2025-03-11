#include "MainMenuPage.h"

Tetris::MainMenuPage::MainMenuPage(
	Application* app)
	: Page(app)
{
	Application* appRef = this->app;
	Uint32 versionInfoTextWrap = static_cast<Uint32>(this->app->getWindowWidth()) - 6;

	Texture* logo__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/game_logo.png",
		this->app->getWindowWidth() / 2 - 233.5f,
		40);

	Text* version_info__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/normal.ttf",
		this->app->VERSION,
		15,
		&versionInfoTextWrap,
		3,
		this->app->getWindowHeight() - 20,
		{ 255, 255, 255, 255 });

	TextButton* play__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Play",
		29,
		400,
		60,
		this->app->getWindowWidth() / 2 - 200,
		220,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	TextButton* settings__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Settings",
		29,
		400,
		60,
		this->app->getWindowWidth() / 2 - 200,
		300,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	TextButton* guide__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Guide",
		29,
		400,
		60,
		this->app->getWindowWidth() / 2 - 200,
		380,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	TextButton* quit__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Quit",
		29,
		400,
		60,
		this->app->getWindowWidth() / 2 - 200,
		460,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	this->backgroundColor = { 0, 15, 49, 255 };

	this->setRenderable("logo__texture", logo__texture);
	this->setRenderable("version_info__text", version_info__text);
	this->setRenderable("play__text_button", play__text_button);
	this->setRenderable("settings__text_button", settings__text_button);
	this->setRenderable("guide__text_button", guide__text_button);
	this->setRenderable("quit__text_button", quit__text_button);

	play__text_button->setOnRelease([appRef] { appRef->changePage("play"); });
	settings__text_button->setOnRelease([appRef] { appRef->changePage("settings"); });
	guide__text_button->setOnRelease([appRef] { appRef->changePage("guide"); });
	quit__text_button->setOnRelease([appRef] { appRef->shutDown(); });
}

void Tetris::MainMenuPage::init()
{
	if (this->isInitialized) {
		return;
	}

	Page::init();
}

void Tetris::MainMenuPage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
}

void Tetris::MainMenuPage::update() {}
