#include "SettingsPage.h"

SettingsPage::SettingsPage(App* app)
	: Page(app) {
	
}

SettingsPage::~SettingsPage() {

}

void SettingsPage::init() {
	if (this->initialized) {
		return;
	}
	Page::init();
}

void SettingsPage::clean() {
	if (!this->initialized) {
		return;
	}
	Page::clean();
}

void SettingsPage::input() {
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

void SettingsPage::update() {

}

void SettingsPage::render() {
	
}
