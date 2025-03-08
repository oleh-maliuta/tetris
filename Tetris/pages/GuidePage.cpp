#include "GuidePage.h"

Tetris::GuidePage::GuidePage(
	Application* app)
	: Page(app)
{
	Uint32 versionInfoTextWrap = this->app->getWindowWidth() - 6;

	this->backgroundColor = { 0, 15, 49, 255 };

	Text* version_info__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/normal.ttf",
		this->app->VERSION,
		15,
		&versionInfoTextWrap,
		3,
		this->app->getWindowHeight() - 20,
		{ 255, 255, 255, 255 });

	ImageButton* return__image_button = new ImageButton(
		this->app->getRenderer(),
		"assets/images/png/return.png",
		10,
		10,
		{ 0, 55, 164, 255 },
		5,
		5,
		5,
		5);

	TextButton* controls__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Controls",
		21,
		300,
		40,
		this->app->getWindowWidth() / 2 - 150,
		100,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	TextButton* score_values__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Score values",
		21,
		300,
		40,
		this->app->getWindowWidth() / 2 - 150,
		170,
		{ 0, 55, 164, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	this->setRenderable("controls__text_button", controls__text_button);
	this->setRenderable("score_values__text_button", score_values__text_button);
	this->setRenderable("version_info__text", version_info__text);
	this->setRenderable("return__image_button", return__image_button);

	return__image_button->setOnRelease([=] {
		this->getApp()->changePage("main_menu");
	});
	controls__text_button->setOnRelease([=] {
		this->getApp()->changePage("controls");
	});

	this->initKeyDownEvents();
}

void Tetris::GuidePage::init()
{
	if (this->isInitialized) {
		return;
	}

	Page::init();
}

void Tetris::GuidePage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
}

void Tetris::GuidePage::update() {}

void Tetris::GuidePage::initKeyDownEvents()
{
	this->keyDownEvents[SDLK_ESCAPE] = [=] {
		this->getApp()->changePage("main_menu");
	};

	this->keyDownEvents[SDLK_BACKSPACE] = [=] {
		this->getApp()->changePage("main_menu");
	};
}
