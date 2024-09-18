#include "PlayPage.h"

PlayPage::PlayPage(App* app)
	: Page(app) {
	const SDL_Point startCellPos = { 20, 20 };
	const SDL_Point cellSize = { 25, 25 };
	const int cellGab = 3;

	this->backgroundColor = { 1, 0, 20, 255 };

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			const std::string cellName = std::format(
				"cell_{}_{}__rectangle",
				i + 1,
				j + 1);

			Rectangle* cell = new Rectangle(
				this->app->getRenderer(),
				cellSize.x,
				cellSize.y,
				startCellPos.x + ((cellGab + cellSize.x) * j),
				startCellPos.y + ((cellGab + cellSize.y) * i),
				{ 150, 150, 150, 255 });

			this->renderables[cellName] = cell;
		}
	}
}

void PlayPage::init() {
	if (this->isInitialized) {
		return;
	}

	Page::init();
}

void PlayPage::clean() {
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
}

void PlayPage::input() {
	Page::input();
}

void PlayPage::update() {
	Page::update();
}

void PlayPage::render() {
	if (!this->isInitialized) {
		return;
	}

	Page::render();
}
