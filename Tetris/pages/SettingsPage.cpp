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
