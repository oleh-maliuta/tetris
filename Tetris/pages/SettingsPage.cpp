#include "SettingsPage.h"

SettingsPage::SettingsPage(App* app)
	: Page(app) {
	
}

void SettingsPage::init() {
	if (this->isInitialized) {
		return;
	}

	Page::init();
}

void SettingsPage::clean() {
	if (!this->isInitialized) {
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
			this->app->setRunning(false);
			break;
		}
	}
}

void SettingsPage::update() {

}

void SettingsPage::render() {
	if (!this->isInitialized) {
		return;
	}

	Page::render();
}
