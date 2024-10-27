#include "PlayPage.h"

Tetris::PlayPage::PlayPage(
	Application* app)
	: Page(app)
{
	const SDL_Point startCellPos = { 20, 20 };
	const SDL_Point cellSize = { 25, 25 };
	const int cellGab = 3;
	Uint32 labelTextWrap = static_cast<Uint32>(150);
	float nextShapeSize = 90.0;

	this->backgroundColor = { 0, 15, 49, 255 };

	Rectangle* next_block__rectangle = new Rectangle(
		this->app->getRenderer(),
		150,
		170,
		330,
		20,
		{ 0, 0, 30, 255 });

	Text* next_block_label__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Next",
		30,
		&labelTextWrap,
		0.f,
		15.f,
		{ 255, 255, 255, 255 });
	next_block_label__text->setPositionX(330 + 150 / 2 - next_block_label__text->getWidth() / 2);

	Texture* next_i_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/i_block.png",
		0.0,
		75.0,
		&nextShapeSize,
		&nextShapeSize);
	next_i_block_hint__texture->setPositionX(330 + 150 / 2 - nextShapeSize / 2);
	next_i_block_hint__texture->setVisibility(false);

	Texture* next_o_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/o_block.png",
		0.0,
		75.0,
		&nextShapeSize,
		&nextShapeSize);
	next_o_block_hint__texture->setPositionX(330 + 150 / 2 - nextShapeSize / 2);
	next_o_block_hint__texture->setVisibility(false);

	Texture* next_t_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/t_block.png",
		0.0,
		75.0,
		&nextShapeSize,
		&nextShapeSize);
	next_t_block_hint__texture->setPositionX(330 + 150 / 2 - nextShapeSize / 2);
	next_t_block_hint__texture->setVisibility(false);

	Texture* next_j_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/j_block.png",
		0.0,
		75.0,
		&nextShapeSize,
		&nextShapeSize);
	next_j_block_hint__texture->setPositionX(330 + 150 / 2 - nextShapeSize / 2);
	next_j_block_hint__texture->setVisibility(false);

	Texture* next_l_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/l_block.png",
		0.0,
		75.0,
		&nextShapeSize,
		&nextShapeSize);
	next_l_block_hint__texture->setPositionX(330 + 150 / 2 - nextShapeSize / 2);
	next_l_block_hint__texture->setVisibility(false);

	Texture* next_s_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/s_block.png",
		0.0,
		75.0,
		&nextShapeSize,
		&nextShapeSize);
	next_s_block_hint__texture->setPositionX(330 + 150 / 2 - nextShapeSize / 2);
	next_s_block_hint__texture->setVisibility(false);

	Texture* next_z_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/z_block.png",
		0.0,
		75.0,
		&nextShapeSize,
		&nextShapeSize);
	next_z_block_hint__texture->setPositionX(330 + 150 / 2 - nextShapeSize / 2);
	next_z_block_hint__texture->setVisibility(false);

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

	Text* level_value__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		std::to_string(this->level),
		25,
		&labelTextWrap,
		0.f,
		260.f,
		{ 255, 255, 255, 255 });
	level_value__text->setPositionX(330 + 150 / 2 - level_value__text->getWidth() / 2);

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

	Text* lines_value__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		std::to_string(this->lines),
		25,
		&labelTextWrap,
		0.f,
		380.f,
		{ 255, 255, 255, 255 });
	lines_value__text->setPositionX(330 + 150 / 2 - lines_value__text->getWidth() / 2);

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

	Text* score_value__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		std::to_string(this->score),
		25,
		&labelTextWrap,
		0.f,
		500.f,
		{ 255, 255, 255, 255 });
	score_value__text->setPositionX(330 + 150 / 2 - score_value__text->getWidth() / 2);

	this->addRenderable("next_block__rectangle", next_block__rectangle);
	this->addRenderable("next_block_label__text", next_block_label__text);
	this->addRenderable("next_i_block_hint__texture", next_i_block_hint__texture);
	this->addRenderable("next_o_block_hint__texture", next_o_block_hint__texture);
	this->addRenderable("next_t_block_hint__texture", next_t_block_hint__texture);
	this->addRenderable("next_j_block_hint__texture", next_j_block_hint__texture);
	this->addRenderable("next_l_block_hint__texture", next_l_block_hint__texture);
	this->addRenderable("next_s_block_hint__texture", next_s_block_hint__texture);
	this->addRenderable("next_z_block_hint__texture", next_z_block_hint__texture);
	this->addRenderable("level__rectangle", level__rectangle);
	this->addRenderable("level_label__text", level_label__text);
	this->addRenderable("level_value__text", level_value__text);
	this->addRenderable("lines__rectangle", lines__rectangle);
	this->addRenderable("lines_label__text", lines_label__text);
	this->addRenderable("lines_value__text", lines_value__text);
	this->addRenderable("score__rectangle", score__rectangle);
	this->addRenderable("score_label__text", score_label__text);
	this->addRenderable("score_value__text", score_value__text);

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

void Tetris::PlayPage::init()
{
	if (this->isInitialized) {
		return;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribution(0, 6);

	const char* blockCharacters = "iotjlsz";
	int current_block_num = distribution(gen);
	int next_block_num = distribution(gen);

	if (current_block_num == next_block_num) {
		if (next_block_num == 6) {
			next_block_num = 0;
		}
		else {
			next_block_num++;
		}
	}

	Texture* next_block_hint__texture = dynamic_cast<Texture*>(
		this->getRenderable(std::format(
			"next_{}_block_hint__texture",
			blockCharacters[next_block_num])));

	this->nextBlockHint = next_block_hint__texture;
	this->currentBlock = blockCharacters[current_block_num];
	this->blockFallingDelay = 0;
	this->level = 1;
	this->lines = 0;
	this->score = 0;

	this->nextBlockHint->setVisibility(true);

	Page::init();
}

void Tetris::PlayPage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	this->cells.clear();
	this->nextBlockHint->setVisibility(false);

	Page::clean();
}

void Tetris::PlayPage::input()
{
	Page::input();
}

void Tetris::PlayPage::update()
{
	Page::update();
}

void Tetris::PlayPage::render()
{
	if (!this->isInitialized) {
		return;
	}

	Page::render();
}
