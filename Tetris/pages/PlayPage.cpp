#include "PlayPage.h"

PlayPage::PlayPage(App* app)
	: Page(app) {
	const SDL_Point startCellPos = { 20, 20 };
	const SDL_Point cellSize = { 25, 25 };
	const int cellGab = 3;

	Uint32 labelTextWrap = static_cast<Uint32>(150);

	this->backgroundColor = { 0, 15, 49, 255 };

	Rectangle* next_piece__rectangle = new Rectangle(
		this->app->getRenderer(),
		150,
		170,
		330,
		20,
		{ 0, 0, 30, 255 });

	Text* next_piece_label__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Next",
		30,
		&labelTextWrap,
		0.f,
		15.f,
		{ 255, 255, 255, 255 });
	next_piece_label__text->setPositionX(330 + 150 / 2 - next_piece_label__text->getWidth() / 2);

	Rectangle* level__rectangle = new Rectangle(
		this->app->getRenderer(),
		150,
		100,
		330,
		210,
		{ 0, 0, 30, 255 });

	Text* level_label__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Level",
		30,
		&labelTextWrap,
		0.f,
		205.f,
		{ 255, 255, 255, 255 });
	level_label__text->setPositionX(330 + 150 / 2 - level_label__text->getWidth() / 2);

	Rectangle* lines__rectangle = new Rectangle(
		this->app->getRenderer(),
		150,
		100,
		330,
		330,
		{ 0, 0, 30, 255 });

	Text* lines_label__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Lines",
		30,
		&labelTextWrap,
		0.f,
		325.f,
		{ 255, 255, 255, 255 });
	lines_label__text->setPositionX(330 + 150 / 2 - lines_label__text->getWidth() / 2);

	Rectangle* score__rectangle = new Rectangle(
		this->app->getRenderer(),
		150,
		100,
		330,
		450,
		{ 0, 0, 30, 255 });

	Text* score_label__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Score",
		30,
		&labelTextWrap,
		0.f,
		445.f,
		{ 255, 255, 255, 255 });
	score_label__text->setPositionX(330 + 150 / 2 - score_label__text->getWidth() / 2);

	this->addRenderable("next_piece__rectangle", next_piece__rectangle);
	this->addRenderable("next_piece_label__text", next_piece_label__text);
	this->addRenderable("level__rectangle", level__rectangle);
	this->addRenderable("level_label__text", level_label__text);
	this->addRenderable("lines__rectangle", lines__rectangle);
	this->addRenderable("lines_label__text", lines_label__text);
	this->addRenderable("score__rectangle", score__rectangle);
	this->addRenderable("score_label__text", score_label__text);

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
				{ 35, 50, 79, 255 });

			this->addRenderable(cellName, cell);
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
