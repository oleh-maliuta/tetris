#include "SettingsPage.h"

Tetris::SettingsPage::SettingsPage(
	Application* app)
	: Page(app)
{
	Tetris::Application* appRef = this->app;
	SettingsPage* pageRef = this;
	Uint32 versionInfoTextWrap = this->app->getWindowWidth() - 6;
	Uint32 vSyncTextWrap = 100;

	Texture* v_sync__texture = new Texture(
		this->app->getRenderer(),
		this->vSync ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png",
		280,
		100);

	Text* version_info__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/normal.ttf",
		this->app->getVersion(),
		15,
		&versionInfoTextWrap,
		3,
		this->app->getWindowHeight() - 20,
		{ 255, 255, 255, 255 });

	Text* v_sync__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"V-Sync",
		20,
		&vSyncTextWrap,
		130,
		100,
		{ 255, 255, 255, 255 });

	TextButton* apply__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/normal.ttf",
		"Apply",
		20,
		140,
		45,
		this->app->getWindowWidth() / 2 - 70,
		450,
		{ 0, 200, 0, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

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

	this->backgroundColor = { 0, 15, 49, 255 };

	this->addRenderable("version_info__text", version_info__text);
	this->addRenderable("v_sync__texture", v_sync__texture);
	this->addRenderable("v_sync__text", v_sync__text);
	this->addRenderable("apply__text_button", apply__text_button);
	this->addRenderable("return__image_button", return__image_button);

	v_sync__texture->setOnRelease([pageRef, v_sync__texture] {
		pageRef->setVSync(!pageRef->getVSync());
		v_sync__texture->setFilePath(pageRef->getVSync() ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png");
	});
	return__image_button->setOnRelease([appRef] { appRef->changePage("main_menu"); });
	apply__text_button->setOnRelease([appRef, pageRef] {
		if (appRef->getVSync() != pageRef->getVSync()) {
			appRef->setVSync(pageRef->getVSync());
		}
	});
}

void Tetris::SettingsPage::init()
{
	if (this->isInitialized) {
		return;
	}

	Texture* v_sync__texture = dynamic_cast<Texture*>(this->getRenderable("v_sync__texture"));

	this->vSync = this->app->getVSync();

	v_sync__texture->setFilePath(this->vSync ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png");

	Page::init();
}

void Tetris::SettingsPage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
}

bool Tetris::SettingsPage::getVSync() const
{
	return this->vSync;
}

void Tetris::SettingsPage::setVSync(
	const bool& value)
{
	this->vSync = value;
}

void Tetris::SettingsPage::input()
{
	Page::input();
}

void Tetris::SettingsPage::update()
{
	Page::update();
}

void Tetris::SettingsPage::render()
{
	if (!this->isInitialized) {
		return;
	}

	Page::render();
}
