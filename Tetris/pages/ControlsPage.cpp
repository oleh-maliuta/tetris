#include "ControlsPage.h"

Tetris::ControlsPage::ControlsPage(
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

	Texture* controls__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/controls.png",
		this->app->getWindowWidth() / 2 - 233.5f,
		100);
	controls__texture->setPositionX(this->app->getWindowWidth() / 2.f - controls__texture->getWidth() / 2);

	this->setRenderable("version_info__text", version_info__text);
	this->setRenderable("return__image_button", return__image_button);
	this->setRenderable("controls__texture", controls__texture);

	return__image_button->setOnRelease([=] {
		this->getApp()->changePage("guide");
	});

	this->initKeyDownEvents();
}

void Tetris::ControlsPage::init()
{
	if (this->isInitialized) {
		return;
	}

	Page::init();
}

void Tetris::ControlsPage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
}

void Tetris::ControlsPage::update() {}

void Tetris::ControlsPage::initKeyDownEvents()
{
	this->keyDownEvents[SDLK_ESCAPE] = [=] {
		this->getApp()->changePage("guide");
		};

	this->keyDownEvents[SDLK_BACKSPACE] = [=] {
		this->getApp()->changePage("guide");
		};
}
