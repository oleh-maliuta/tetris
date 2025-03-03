#include "SettingsPage.h"

Tetris::SettingsPage::SettingsPage(
	Application* app)
	: Page(app)
{
	Tetris::Application* appRef = this->app;
	SettingsPage* pageRef = this;
	Uint32 versionInfoTextWrap = this->app->getWindowWidth() - 6;
	Uint32 vSyncTextWrap = 230;
	float switchWidth = 48;
	float switchHeight = 25;

	Text* version_info__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/normal.ttf",
		this->app->VERSION,
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
		120,
		100,
		{ 255, 255, 255, 255 });

	Texture* v_sync__texture = new Texture(
		this->app->getRenderer(),
		this->vSync ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png",
		380,
		100,
		&switchWidth,
		&switchHeight);

	Text* color_blocks__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Color blocks",
		20,
		&vSyncTextWrap,
		120,
		150,
		{ 255, 255, 255, 255 });

	Texture* color_blocks__texture = new Texture(
		this->app->getRenderer(),
		this->colorBlocksOn ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png",
		380,
		150,
		&switchWidth,
		&switchHeight);

	Text* music__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Music",
		20,
		&vSyncTextWrap,
		120,
		200,
		{ 255, 255, 255, 255 });

	Texture* music__texture = new Texture(
		this->app->getRenderer(),
		this->musicOn ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png",
		380,
		200,
		&switchWidth,
		&switchHeight);

	Text* sound_effects__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Sound effects",
		20,
		&vSyncTextWrap,
		120,
		250,
		{ 255, 255, 255, 255 });

	Texture* sound_effects__texture = new Texture(
		this->app->getRenderer(),
		this->soundEffectsOn ? "assets/images/png/checked.png" : "assets/images/png/unchecked.png",
		380,
		250,
		&switchWidth,
		&switchHeight);

	TextButton* apply__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Apply",
		20,
		140,
		45,
		this->app->getWindowWidth() / 2 - 70,
		450,
		{ 0, 150, 0, 255 },
		{ 255, 255, 255, 255 },
		5,
		5);

	Text* changes_are_saved__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Changes are saved",
		18,
		&vSyncTextWrap,
		0,
		500,
		{ 0, 255, 0, 255 });
	changes_are_saved__text->setPositionX(this->app->getWindowWidth() / 2.f - changes_are_saved__text->getWidth() / 2);
	changes_are_saved__text->setVisibility(false);

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

	this->setRenderable("v_sync__text", v_sync__text);
	this->setRenderable("v_sync__texture", v_sync__texture);
	this->setRenderable("color_blocks__text", color_blocks__text);
	this->setRenderable("color_blocks__texture", color_blocks__texture);
	this->setRenderable("music__text", music__text);
	this->setRenderable("music__texture", music__texture);
	this->setRenderable("sound_effects__text", sound_effects__text);
	this->setRenderable("sound_effects__texture", sound_effects__texture);
	this->setRenderable("version_info__text", version_info__text);
	this->setRenderable("apply__text_button", apply__text_button);
	this->setRenderable("changes_are_saved__text", changes_are_saved__text);
	this->setRenderable("return__image_button", return__image_button);

	return__image_button->setOnRelease([appRef] {
		appRef->changePage("main_menu");
	});
	v_sync__texture->setOnRelease([pageRef, v_sync__texture] {
		pageRef->setVSync(!pageRef->getVSync());
		v_sync__texture->setFilePath(
			pageRef->getVSync() ?
			"assets/images/png/checked.png" :
			"assets/images/png/unchecked.png");
	});
	color_blocks__texture->setOnRelease([pageRef, color_blocks__texture] {
		pageRef->setColorBlocksOn(!pageRef->getColorBlocksOn());
		color_blocks__texture->setFilePath(
			pageRef->getColorBlocksOn() ?
			"assets/images/png/checked.png" :
			"assets/images/png/unchecked.png");
	});
	music__texture->setOnRelease([pageRef, music__texture] {
		pageRef->setMusicOn(!pageRef->getMusicOn());
		music__texture->setFilePath(
			pageRef->getMusicOn() ?
			"assets/images/png/checked.png" :
			"assets/images/png/unchecked.png");
	});
	sound_effects__texture->setOnRelease([pageRef, sound_effects__texture] {
		pageRef->setSoundEffectsOn(!pageRef->getSoundEffectsOn());
		sound_effects__texture->setFilePath(
			pageRef->getSoundEffectsOn() ?
			"assets/images/png/checked.png" :
			"assets/images/png/unchecked.png");
	});
	apply__text_button->setOnRelease([appRef, pageRef] {
		if (appRef->getVSync() != pageRef->getVSync()) {
			appRef->setVSync(pageRef->getVSync());
		}
		if (appRef->getColorBlocksOn() != pageRef->getColorBlocksOn()) {
			appRef->setColorBlocksOn(pageRef->getColorBlocksOn());
		}
		if (appRef->getMusicOn() != pageRef->getMusicOn()) {
			appRef->setMusicOn(pageRef->getMusicOn());
		}
		if (appRef->getSoundEffectsOn() != pageRef->getSoundEffectsOn()) {
			appRef->setSoundEffectsOn(pageRef->getSoundEffectsOn());
		}

		Text* messageText = pageRef->getRenderable<Text>("changes_are_saved__text");
		messageText->setVisibility(true);

		pageRef->setRegularEvent(
			"message-about-the-saved-changes",
			[](Uint32 interval, void* param) -> Uint32 {
				Text* messageText = static_cast<Text*>(param);
				messageText->setVisibility(false);
				return 0;
			},
			3000,
			messageText);
	});

	this->initKeyDownEvents();
}

void Tetris::SettingsPage::init()
{
	if (this->isInitialized) {
		return;
	}

	Page::init();

	Texture* v_sync__texture = this->getRenderable<Texture>("v_sync__texture");
	Texture* color_blocks__texture = this->getRenderable<Texture>("color_blocks__texture");
	Texture* music__texture = this->getRenderable<Texture>("music__texture");
	Texture* sound_effects__texture = this->getRenderable<Texture>("sound_effects__texture");

	this->vSync = this->app->getVSync();
	this->colorBlocksOn = this->app->getColorBlocksOn();
	this->musicOn = this->app->getMusicOn();
	this->soundEffectsOn = this->app->getSoundEffectsOn();

	v_sync__texture->setFilePath(
		this->vSync ?
		"assets/images/png/checked.png" :
		"assets/images/png/unchecked.png");
	color_blocks__texture->setFilePath(
		this->colorBlocksOn ?
		"assets/images/png/checked.png" :
		"assets/images/png/unchecked.png");
	music__texture->setFilePath(
		this->musicOn ?
		"assets/images/png/checked.png" :
		"assets/images/png/unchecked.png");
	sound_effects__texture->setFilePath(
		this->soundEffectsOn ?
		"assets/images/png/checked.png" :
		"assets/images/png/unchecked.png");
}

void Tetris::SettingsPage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	Page::clean();

	Text* changes_are_saved__text = this->getRenderable<Text>("changes_are_saved__text");
	changes_are_saved__text->setVisibility(false);
}

bool Tetris::SettingsPage::getMusicOn() const
{
	return this->musicOn;
}

bool Tetris::SettingsPage::getSoundEffectsOn() const
{
	return this->soundEffectsOn;
}

bool Tetris::SettingsPage::getColorBlocksOn() const
{
	return this->colorBlocksOn;
}

bool Tetris::SettingsPage::getVSync() const
{
	return this->vSync;
}

void Tetris::SettingsPage::setMusicOn(
	const bool& value)
{
	this->musicOn = value;
}

void Tetris::SettingsPage::setSoundEffectsOn(
	const bool& value)
{
	this->soundEffectsOn = value;
}

void Tetris::SettingsPage::setColorBlocksOn(
	const bool& value)
{
	this->colorBlocksOn = value;
}

void Tetris::SettingsPage::setVSync(
	const bool& value)
{
	this->vSync = value;
}

void Tetris::SettingsPage::update() {}

void Tetris::SettingsPage::initKeyDownEvents()
{
	this->keyDownEvents[SDLK_ESCAPE] = [=] {
		this->getApp()->changePage("main_menu");
	};

	this->keyDownEvents[SDLK_BACKSPACE] = [=] {
		this->getApp()->changePage("main_menu");
	};
}
