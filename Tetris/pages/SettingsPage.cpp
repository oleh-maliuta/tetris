#include "SettingsPage.h"

SettingsPage::SettingsPage(App* app)
	: Page(app) {
	App* appRef = this->app;
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
		this->app->getWindowHeight() - 20);

	Text* v_sync__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"V. Sync.",
		20,
		&vSyncTextWrap,
		130,
		100);

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

	this->renderables["version_info__text"] = version_info__text;
	this->renderables["v_sync__texture"] = v_sync__texture;
	this->renderables["v_sync__text"] = v_sync__text;
	this->renderables["apply__text_button"] = apply__text_button;
	this->renderables["return__image_button"] = return__image_button;

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

	this->initData();
}

void SettingsPage::init() {
	if (this->isInitialized) {
		return;
	}

	this->initData();
	Page::init();
}

void SettingsPage::clean() {
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
}

bool SettingsPage::getVSync() const {
	return this->vSync;
}

void SettingsPage::setVSync(const bool& value) {
	this->vSync = value;
}

void SettingsPage::input() {
	Page::input();
}

void SettingsPage::update() {
	Page::update();
}

void SettingsPage::render() {
	if (!this->isInitialized) {
		return;
	}

	Page::render();
}

void SettingsPage::initData() {
	Texture* v_sync__texture = dynamic_cast<Texture*>(this->renderables["v_sync__texture"]);

	this->vSync = this->app->getVSync();

	v_sync__texture->setFilePath(this->vSync ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png");
}

