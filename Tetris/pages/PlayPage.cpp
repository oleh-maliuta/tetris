#include "PlayPage.h"

Tetris::PlayPage::PlayPage(
	Application* app)
	: Page(app)
{
	const SDL_FPoint startCellPos = { 20.f, 20.f };
	const SDL_FPoint cellSize = { 25.f, 25.f };
	const int cellGab = 3;
	Uint32 labelTextWrap = static_cast<Uint32>(150);
	float nextShapeSize = 90.0;

	this->backgroundColor = { 0, 15, 49, 255 };

	this->shapeSpawnPositions = {
		{'i', {{ 4, 0 }, { 4, -1 }, { 4, -2 }, { 4, -3 }}},
		{'o', {{ 4, 0 }, { 4, -1 }, { 5, 0 }, { 5, -1 }}},
		{'t', {{ 3, 0 }, { 4, 0 }, { 5, 0 }, { 4, -1 }}},
		{'j', {{ 3, 0 }, { 4, 0 }, { 5, 0 }, { 3, -1 }}},
		{'l', {{ 3, 0 }, { 4, 0 }, { 5, 0 }, { 5, -1 }}},
		{'s', {{ 3, 0 }, { 4, 0 }, { 4, -1 }, { 5, -1 }}},
		{'z', {{ 4, 0 }, { 5, 0 }, { 4, -1 }, { 3, -1 }}}
	};

	this->shapeSpawnColors = {
		{'i', { 255, 255, 255, 255 }},
		{'o', { 255, 255, 255, 255 }},
		{'t', { 255, 255, 255, 255 }},
		{'j', { 255, 255, 255, 255 }},
		{'l', { 255, 255, 255, 255 }},
		{'s', { 255, 255, 255, 255 }},
		{'z', { 255, 255, 255, 255 }}
	};

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

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			const std::string cellName = std::format(
				"cell_{}_{}__rectangle", c, r);

			Rectangle* cell = new Rectangle(
				this->app->getRenderer(),
				static_cast<float>(cellSize.x),
				static_cast<float>(cellSize.y),
				static_cast<float>(startCellPos.x + ((cellGab + cellSize.x) * c)),
				static_cast<float>(startCellPos.y + ((cellGab + cellSize.y) * r)),
				this->DEFAULT_CELL_COLOR);

			this->addRenderable(cellName, cell);
		}
	}

	this->initKeyDownEvents();
}

void Tetris::PlayPage::init()
{
	if (this->isInitialized) {
		return;
	}

	Page::init();

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			this->cellInfo[c][r] = false;
		}
	}

	this->blockFallingInterval = this->START_BLOCK_FALLING_INTERVAL;
	this->level = 1;
	this->lines = 0;
	this->score = 0;

	this->initRegularEvents();
}

void Tetris::PlayPage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	Page::clean();
	this->fallingBlocks.clear();
	this->idleBlocks.clear();
	this->nextBlockHint->setVisibility(false);
	delete this->currentBlock;
	delete this->nextBlock;

	this->currentBlock = nullptr;
	this->nextBlock = nullptr;
}

void Tetris::PlayPage::update()
{
	if (this->fallingBlocks.size() == 0) {
		this->chooseShape();

		std::vector<TetrisCellPosition> blockPositions = PlayPage::shapeSpawnPositions[*this->currentBlock];
		SDL_Color blockColor = PlayPage::shapeSpawnColors[*this->currentBlock];

		for (auto& blockPosition : blockPositions) {
			this->fallingBlocks.push_back({
				blockPosition.x,
				blockPosition.y,
				blockColor.r,
				blockColor.g,
				blockColor.b,
				blockColor.a
			});
		}
	}

	Rectangle* cells[10][20] = {};

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			cells[c][r] = this->getRenderable<Rectangle>(
				std::format("cell_{}_{}__rectangle", c, r));
			cells[c][r]->setColor({
				this->DEFAULT_CELL_COLOR.r,
				this->DEFAULT_CELL_COLOR.g,
				this->DEFAULT_CELL_COLOR.b,
				this->DEFAULT_CELL_COLOR.a });
		}
	}

	for (auto& block : this->fallingBlocks) {
		if (block.y < 0) {
			continue;
		}

		cells[block.x][block.y]->setColor({
			block.r,
			block.g,
			block.b,
			block.a });
	}

	for (auto& block : this->idleBlocks) {
		if (block.y < 0) {
			continue;
		}

		cells[block.x][block.y]->setColor({
			block.r,
			block.g,
			block.b,
			block.a });
	}
}

void Tetris::PlayPage::chooseShape()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribution(0, 6);

	std::string blockCharacters = "iotjlsz";
	int current_block_num = this->nextBlock != nullptr ?
		blockCharacters.find(*this->nextBlock) :
		distribution(gen);
	int next_block_num = distribution(gen);

	Texture* next_block_hint__texture = this->getRenderable<Texture>(
		std::format(
			"next_{}_block_hint__texture",
			blockCharacters[next_block_num]));

	if (this->nextBlockHint != nullptr) {
		this->nextBlockHint->setVisibility(false);
	}

	this->currentBlock = new char(blockCharacters[current_block_num]);
	this->nextBlock = new char(blockCharacters[next_block_num]);
	this->nextBlockHint = next_block_hint__texture;

	this->nextBlockHint->setVisibility(true);
}

void Tetris::PlayPage::initKeyDownEvents()
{
	this->keyDownEvents[SDLK_d] = [=]() {
		if (this->fallingBlocks.size() == 0) {
			return;
		}

		bool isActionEnabled = true;

		for (auto& block : this->fallingBlocks) {
			if (block.x >= 9 || (block.y >= 0 && this->cellInfo[block.x + 1][block.y])) {
				isActionEnabled = false;
				break;
			}
		}

		if (isActionEnabled) {
			for (auto& block : this->fallingBlocks) {
				block.x++;
			}
		}
	};

	this->keyDownEvents[SDLK_a] = [=]() {
		if (this->fallingBlocks.size() == 0) {
			return;
		}

		bool isActionEnabled = true;

		for (auto& block : this->fallingBlocks) {
			if (block.x <= 0 || (block.y >= 0 && this->cellInfo[block.x - 1][block.y])) {
				isActionEnabled = false;
				break;
			}
		}

		if (isActionEnabled) {
			for (auto& block : this->fallingBlocks) {
				block.x--;
			}
		}
	};
}

void Tetris::PlayPage::initRegularEvents()
{
	this->addRegularEvent(
		"shape-falling",
		this->blockFallingInterval,
		[](Uint32 interval, void* param) -> Uint32 {
			PlayPage* page = static_cast<PlayPage*>(param);

			if (page->fallingBlocks.size() == 0) {
				return page->blockFallingInterval;
			}

			bool touchedTheGround = false;

			for (auto& block : page->fallingBlocks) {
				if (block.y >= -1 && (block.y == 19 || page->cellInfo[block.x][block.y + 1])) {
					touchedTheGround = true;
					break;
				}
			}

			if (touchedTheGround) {
				for (auto& block : page->fallingBlocks) {
					if (block.y >= 0 && block.y <= 19) {
						page->cellInfo[block.x][block.y] = true;
					}
				}

				page->idleBlocks.splice(page->idleBlocks.end(), page->fallingBlocks);
			}
			else {
				for (auto& block : page->fallingBlocks) {
					block.y++;
				}
			}

			return page->blockFallingInterval;
		},
		this);
}
