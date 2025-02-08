#include "PlayPage.h"

Tetris::PlayPage::PlayPage(
	Application* app)
	: Page(app)
{
	const SDL_FPoint startCellPos = { 20.f, 20.f };
	const SDL_FPoint cellSize = { 25.f, 25.f };
	const int cellGab = 3;
	Uint32 labelTextWrap = static_cast<Uint32>(150);
	float nextPieceSize = 90.0f;

	this->backgroundColor = { 0, 15, 49, 255 };

	this->pieceData = {
		{'i', {
				{{ 4, 22 }, { 4, 20 }, { 4, 21 }, { 4, 23 }},
				251, 112, 36, 255
			}
		},
		{'o', {
				{{ 4, 20 }, { 4, 21 }, { 5, 20 }, { 5, 21 }},
				243, 209, 26, 255
			}
		},
		{'t', {
				{{ 4, 20 }, { 3, 20 }, { 5, 20 }, { 4, 21 }},
				167, 47, 232, 255
			}
		},
		{'j', {
				{{ 4, 20 }, { 3, 20 }, { 5, 20 }, { 3, 21 }},
				117, 196, 63, 255
			}
		},
		{'l', {
				{{ 4, 20 }, { 3, 20 }, { 5, 20 }, { 5, 21 }},
				61, 194, 132, 255
			}
		},
		{'s', {
				{{ 4, 20 }, { 3, 20 }, { 4, 21 }, { 5, 21 }},
				238, 30, 40, 255
			}
		},
		{'z', {
				{{ 4, 20 }, { 5, 20 }, { 4, 21 }, { 3, 21 }},
				31, 197, 240, 255
			}
		},
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
		&nextPieceSize,
		&nextPieceSize);
	next_i_block_hint__texture->setPositionX(330 + 150 / 2 - nextPieceSize / 2);
	next_i_block_hint__texture->setVisibility(false);

	Texture* next_o_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/o_block.png",
		0.0,
		75.0,
		&nextPieceSize,
		&nextPieceSize);
	next_o_block_hint__texture->setPositionX(330 + 150 / 2 - nextPieceSize / 2);
	next_o_block_hint__texture->setVisibility(false);

	Texture* next_t_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/t_block.png",
		0.0,
		75.0,
		&nextPieceSize,
		&nextPieceSize);
	next_t_block_hint__texture->setPositionX(330 + 150 / 2 - nextPieceSize / 2);
	next_t_block_hint__texture->setVisibility(false);

	Texture* next_j_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/j_block.png",
		0.0,
		75.0,
		&nextPieceSize,
		&nextPieceSize);
	next_j_block_hint__texture->setPositionX(330 + 150 / 2 - nextPieceSize / 2);
	next_j_block_hint__texture->setVisibility(false);

	Texture* next_l_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/l_block.png",
		0.0,
		75.0,
		&nextPieceSize,
		&nextPieceSize);
	next_l_block_hint__texture->setPositionX(330 + 150 / 2 - nextPieceSize / 2);
	next_l_block_hint__texture->setVisibility(false);

	Texture* next_s_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/s_block.png",
		0.0,
		75.0,
		&nextPieceSize,
		&nextPieceSize);
	next_s_block_hint__texture->setPositionX(330 + 150 / 2 - nextPieceSize / 2);
	next_s_block_hint__texture->setVisibility(false);

	Texture* next_z_block_hint__texture = new Texture(
		this->app->getRenderer(),
		"assets/images/png/z_block.png",
		0.0,
		75.0,
		&nextPieceSize,
		&nextPieceSize);
	next_z_block_hint__texture->setPositionX(330 + 150 / 2 - nextPieceSize / 2);
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
		for (int r = 0, rID = 19; r < 20; r++, rID--) {
			const std::string cellName = std::format(
				"cell_{}_{}__rectangle", c, rID);

			Rectangle* cell = new Rectangle(
				this->app->getRenderer(),
				cellSize.x,
				cellSize.y,
				startCellPos.x + ((cellGab + cellSize.x) * c),
				startCellPos.y + ((cellGab + cellSize.y) * r),
				this->DEFAULT_CELL_COLOR);

			this->addRenderable(cellName, cell);
			this->cells[c][rID] = cell;
		}
	}

	for (int c = 0; c < 10; c++) {
		for (int r = 0, rID = 19; r < 20; r++, rID--) {
			const std::string cellMarkerName = std::format(
				"cell_marker_{}_{}__rectangle", c, rID);

			Rectangle* cellMarker = new Rectangle(
				this->app->getRenderer(),
				cellSize.x / 2.f,
				cellSize.y / 2.f,
				startCellPos.x + ((cellGab + cellSize.x) * c) + cellSize.x / 4.f,
				startCellPos.y + ((cellGab + cellSize.y) * r) + cellSize.y / 4.f,
				{ 255, 255, 255, 255 });
			cellMarker->setVisibility(false);

			this->addRenderable(cellMarkerName, cellMarker);
			this->cellMarkers[c][rID] = cellMarker;
		}
	}

	this->initPauseMenu();
	this->initGameOverMenu();
	this->initKeyDownEvents();
	this->initKeyUpEvents();
}

void Tetris::PlayPage::init()
{
	if (this->isInitialized) {
		return;
	}

	Page::init();

	this->blockFallingInterval = this->START_BLOCK_FALLING_INTERVAL;
	this->pieceRotationIndex = 0;
	this->level = 1;
	this->lines = 0;
	this->score = 0;
	this->isSoftDropOn = false;
	this->pause = false;
	this->gameOver = false;

	Text* levelValue = this->getRenderable<Text>("level_value__text");
	Text* linesValue = this->getRenderable<Text>("lines_value__text");
	Text* scoreValue = this->getRenderable<Text>("score_value__text");

	levelValue->setContent("1");
	linesValue->setContent("0");
	scoreValue->setContent("0");
	levelValue->setPositionX(330 + 150 / 2.f - levelValue->getWidth() / 2.f);
	linesValue->setPositionX(330 + 150 / 2.f - linesValue->getWidth() / 2.f);
	scoreValue->setPositionX(330 + 150 / 2.f - scoreValue->getWidth() / 2.f);

	this->initRegularEvents();
}

void Tetris::PlayPage::clean()
{
	if (!this->isInitialized) {
		return;
	}

	Page::clean();

	if (this->nextBlockHint != nullptr) {
		this->nextBlockHint->setVisibility(false);
		this->nextBlockHint = nullptr;
	}

	this->fallingBlocks.clear();
	this->idleBlocks.clear();
	this->blockMarkers.clear();

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			this->gridInfo[c][r] = false;
		}
	}

	delete this->currentBlock;
	delete this->nextBlock;
	this->currentBlock = nullptr;
	this->nextBlock = nullptr;

	Layout* pauseMenu = this->getRenderable<Layout>("pause_menu__layout");
	Layout* gameOverMenu = this->getRenderable<Layout>("game_over_menu__layout");

	gameOverMenu->setVisibility(false);
	pauseMenu->setVisibility(false);

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			this->cells[c][r]->setColor({
				this->DEFAULT_CELL_COLOR.r,
				this->DEFAULT_CELL_COLOR.g,
				this->DEFAULT_CELL_COLOR.b,
				this->DEFAULT_CELL_COLOR.a });
		}
	}

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			this->cellMarkers[c][r]->setVisibility(false);
		}
	}
}

void Tetris::PlayPage::updateBlockMarkers()
{
	for (auto& marker : this->blockMarkers) {
		if (marker.y < 0) {
			continue;
		}

		this->cellMarkers[marker.x][marker.y]->setVisibility(false);
	}

	this->blockMarkers.clear();

	if (this->fallingBlocks.size() == 0) {
		return;
	}

	for (auto& block : this->fallingBlocks) {
		this->blockMarkers.push_back({ block.x, block.y });
	}

	bool touchedTheGround = false;

	while (!touchedTheGround) {
		for (auto& marker : this->blockMarkers) {
			if (marker.y <= 20 && (marker.y == 0 || this->gridInfo[marker.x][marker.y - 1])) {
				touchedTheGround = true;
				break;
			}
		}

		if (!touchedTheGround) {
			for (auto& marker : this->blockMarkers) {
				marker.y--;
			}
		}
	}

	for (auto& marker : this->blockMarkers) {
		if (marker.y > 19) {
			continue;
		}

		this->cellMarkers[marker.x][marker.y]->setVisibility(true);
	}
}

void Tetris::PlayPage::clearFilledGridRows()
{
	std::vector<int> filledRows;

	for (int rowNum = 0; rowNum < 20; rowNum++) {
		bool isRowFilled = true;
		bool isRowEmpty = true;

		for (int columnNum = 0; columnNum < 10; columnNum++) {
			if (!this->gridInfo[columnNum][rowNum]) {
				isRowFilled = false;
			}
			else {
				isRowEmpty = false;
			}
		}

		if (isRowFilled) {
			filledRows.push_back(rowNum);
		}

		if (isRowEmpty) {
			break;
		}
	}

	if (filledRows.size() == 0) {
		return;
	}
	
	for (int rowId = filledRows.size() - 1; rowId >= 0; rowId--) {
		this->idleBlocks.remove_if([&rowId, &filledRows](TetrisBlockData el) {
			return el.y == filledRows[rowId];
		});

		for (auto& el : this->idleBlocks) {
			if (el.y > filledRows[rowId]) {
				el.y--;
			}
		}
	}

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			this->gridInfo[c][r] = false;
		}
	}

	for (auto& block : this->idleBlocks) {
		this->gridInfo[block.x][block.y] = true;
	}

	const size_t rowClearedCount = filledRows.size();

	this->lines += rowClearedCount;
	this->score += rowClearedCount == 1 ? 100 :
		rowClearedCount == 2 ? 300 : 500;

	if (this->level < 100 && this->lines % 10 == 0) {
		this->level = this->lines / 10 + 1;
		this->blockFallingInterval = this->START_BLOCK_FALLING_INTERVAL - 10 * (this->level - 1);
	}

	this->addExecuteFunctionEvent([=] {
		Text* linesValue = this->getRenderable<Text>("lines_value__text");
		Text* scoreValue = this->getRenderable<Text>("score_value__text");

		linesValue->setContent(std::to_string(this->lines));
		scoreValue->setContent(std::to_string(this->score));
		linesValue->setPositionX(330 + 150 / 2.f - linesValue->getWidth() / 2.f);
		scoreValue->setPositionX(330 + 150 / 2.f - scoreValue->getWidth() / 2.f);

		if (this->lines % 10 == 0) {
			Text* levelValue = this->getRenderable<Text>("level_value__text");
			levelValue->setContent(std::to_string(this->level));
			levelValue->setPositionX(330 + 150 / 2.f - levelValue->getWidth() / 2.f);
		}
	});
}

void Tetris::PlayPage::saveGameOverResults()
{
	Layout* menu = this->getRenderable<Layout>("game_over_menu__layout");
	Text* levelTextObj = menu->getObject<Text>("level__text");
	Text* linesTextObj = menu->getObject<Text>("lines__text");
	Text* scoreTextObj = menu->getObject<Text>("score__text");
	Uint32 windowWidth = static_cast<Uint32>(this->app->getWindowWidth());

	levelTextObj->setContent("Level: " + std::to_string(this->level));
	linesTextObj->setContent("Lines: " + std::to_string(this->lines));
	scoreTextObj->setContent("Score: " + std::to_string(this->score));

	float maxTextWidth = std::max({
		levelTextObj->getWidth(),
		linesTextObj->getWidth(),
		scoreTextObj->getWidth()
	});

	levelTextObj->setPositionX(windowWidth / 2.f - maxTextWidth / 2.f);
	linesTextObj->setPositionX(windowWidth / 2.f - maxTextWidth / 2.f);
	scoreTextObj->setPositionX(windowWidth / 2.f - maxTextWidth / 2.f);

	menu->setVisibility(true);
}

void Tetris::PlayPage::rotatePiece(
	bool clockwise,
	bool shouldOffset = true)
{
	int oldRotationIndex = this->pieceRotationIndex;
	TetrisBlockData pivot = this->fallingBlocks.front();
	this->pieceRotationIndex += clockwise ? 1 : -1;
	this->pieceRotationIndex = (this->pieceRotationIndex % 4 + 4) % 4;

	for (auto& block : this->fallingBlocks)
	{
		this->rotateTile(
			block,
			{ pivot.x, pivot.y },
			clockwise);

	}

	if (!shouldOffset)
	{
		return;
	}

	bool canOffset = this->offsetPiecePosition(
		oldRotationIndex,
		this->pieceRotationIndex);

	if (!canOffset)
	{
		this->rotatePiece(!clockwise, false);
	}
}

void Tetris::PlayPage::rotateTile(
	TetrisBlockData& curBlock,
	TetrisCellPosition originPos,
	bool clockwise)
{
	TetrisCellPosition relativePos = {
		curBlock.x - originPos.x,
		curBlock.y - originPos.y
	};
	TetrisCellPosition rotMatrix[2] = {};

	if (clockwise) {
		rotMatrix[0] = { 0, -1 };
		rotMatrix[1] = { 1, 0 };
	}
	else {
		rotMatrix[0] = { 0, 1 };
		rotMatrix[1] = { -1, 0 };
	}

	int newXPos = (rotMatrix[0].x * relativePos.x) + (rotMatrix[1].x * relativePos.y);
	int newYPos = (rotMatrix[0].y * relativePos.x) + (rotMatrix[1].y * relativePos.y);

	TetrisCellPosition newPos = { newXPos, newYPos };
	newPos.x += originPos.x;
	newPos.y += originPos.y;

	curBlock.x = newPos.x;
	curBlock.y = newPos.y;
}

bool Tetris::PlayPage::offsetPiecePosition(
	int oldRotIndex,
	int newRotIndex)
{
	TetrisCellPosition offsetVal1 = {}, offsetVal2 = {}, endOffset = { 0, 0 };
	bool movePossible = false;

	for (int testIndex = 0; testIndex < 5; testIndex++)
	{
		if (*this->currentBlock == 'i')
		{
			offsetVal1.x = this->I_OFFSET_DATA[testIndex][oldRotIndex].x;
			offsetVal1.y = this->I_OFFSET_DATA[testIndex][oldRotIndex].y;
			offsetVal2.x = this->I_OFFSET_DATA[testIndex][newRotIndex].x;
			offsetVal2.y = this->I_OFFSET_DATA[testIndex][newRotIndex].y;
		}
		else
		{
			offsetVal1.x = this->J_L_S_T_Z_OFFSET_DATA[testIndex][oldRotIndex].x;
			offsetVal1.y = this->J_L_S_T_Z_OFFSET_DATA[testIndex][oldRotIndex].y;
			offsetVal2.x = this->J_L_S_T_Z_OFFSET_DATA[testIndex][newRotIndex].x;
			offsetVal2.y = this->J_L_S_T_Z_OFFSET_DATA[testIndex][newRotIndex].y;
		}

		endOffset.x = offsetVal1.x - offsetVal2.x;
		endOffset.y = offsetVal1.y - offsetVal2.y;

		if (this->canMovePiece(endOffset))
		{
			movePossible = true;
			break;
		}
	}

	if (movePossible)
	{
		this->movePiece(endOffset);
	}

	return movePossible;
}

bool Tetris::PlayPage::canMovePiece(
	TetrisCellPosition movement)
{
	for (auto& block : this->fallingBlocks)
	{
		TetrisCellPosition endPos = {
			movement.x + block.x,
			movement.y + block.y
		};

		if (!this->canTileMove(block, endPos))
		{
			return false;
		}
	}
	return true;
}

bool Tetris::PlayPage::canTileMove(
	TetrisBlockData& curBlock,
	TetrisCellPosition endPos) const
{
	if (endPos.x < 0 || endPos.x >= 9 || endPos.y < 0)
	{
		return false;
	}

	if (endPos.y < 20 && this->gridInfo[endPos.x][endPos.y])
	{
		return false;
	}

	return true;
}

bool Tetris::PlayPage::movePiece(
	TetrisCellPosition movement)
{
	for (auto& block : this->fallingBlocks)
	{
		TetrisCellPosition endPos = {
			movement.x + block.x,
			movement.y + block.y
		};

		if (!this->canTileMove(block, endPos))
		{
			return false;
		}
	}

	for (auto& block : this->fallingBlocks)
	{
		TetrisCellPosition endPos = {
			block.x + movement.x,
			block.y + movement.y
		};

		block.x = endPos.x;
		block.y = endPos.y;
	}

	return true;
}

void Tetris::PlayPage::update()
{
	if (this->pause) {
		return;
	}

	for (int c = 0; c < 10; c++) {
		for (int r = 0; r < 20; r++) {
			this->cells[c][r]->setColor({
				this->DEFAULT_CELL_COLOR.r,
				this->DEFAULT_CELL_COLOR.g,
				this->DEFAULT_CELL_COLOR.b,
				this->DEFAULT_CELL_COLOR.a });
		}
	}

	for (auto& block : this->fallingBlocks) {
		if (block.y > 19) {
			continue;
		}

		this->cells[block.x][block.y]->setColor({
			block.r,
			block.g,
			block.b,
			block.a });
	}

	for (auto& block : this->idleBlocks) {
		if (block.y > 19) {
			continue;
		}

		this->cells[block.x][block.y]->setColor({
			block.r,
			block.g,
			block.b,
			block.a });
	}
}

void Tetris::PlayPage::choosePiece()
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

void Tetris::PlayPage::initPauseMenu()
{
	Uint32 windowWidth = static_cast<Uint32>(this->app->getWindowWidth());

	Text* header__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Pause",
		50,
		&windowWidth,
		0.f,
		60.f,
		{ 255, 255, 255, 255 });
	header__text->setPositionX(windowWidth / 2.f - header__text->getWidth() / 2.f);

	TextButton* resume__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Resume",
		31,
		400,
		65,
		this->app->getWindowWidth() / 2 - 200,
		180,
		{ 255, 255, 255, 255 },
		{ 0, 0, 0, 255 },
		5,
		5);

	TextButton* restart__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Restart",
		31,
		400,
		65,
		this->app->getWindowWidth() / 2 - 200,
		280,
		{ 255, 255, 255, 255 },
		{ 0, 0, 0, 255 },
		5,
		5);

	TextButton* main_menu__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Main Menu",
		31,
		400,
		65,
		this->app->getWindowWidth() / 2 - 200,
		380,
		{ 255, 255, 255, 255 },
		{ 0, 0, 0, 255 },
		5,
		5);

	TextButton* quit__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Quit the game",
		31,
		400,
		65,
		this->app->getWindowWidth() / 2 - 200,
		480,
		{ 255, 255, 255, 255 },
		{ 0, 0, 0, 255 },
		5,
		5);

	Layout* menu = new Layout(
		this->app->getRenderer(),
		this->app->getWindowWidth(),
		this->app->getWindowHeight(),
		0.f,
		0.f,
		{ 0, 0, 0, 200 },
		{
			{ "header__text", header__text },
			{ "resume__text_button", resume__text_button },
			{ "restart__text_button", restart__text_button },
			{ "main_menu__text_button", main_menu__text_button },
			{ "quit__text_button", quit__text_button }
		});
	menu->setVisibility(false);

	this->addRenderable("pause_menu__layout", menu);

	resume__text_button->setOnRelease([=] {
		if (!this->pause || this->gameOver) {
			return;
		}

		const Uint32 resultInterval = this->isSoftDropOn ?
			static_cast<Uint32>(ceil(this->blockFallingInterval / 10)) :
			this->blockFallingInterval;
		Layout* menu = this->getRenderable<Layout>("pause_menu__layout");

		this->pause = false;
		menu->setVisibility(false);
		this->addRegularEvent(
			"game-process",
			resultInterval,
			this->gameProcessTimerCallback(),
			this);
	});

	restart__text_button->setOnRelease([=] {
		if (!this->pause || this->gameOver) {
			return;
		}

		this->getApp()->restartPage();
	});

	main_menu__text_button->setOnRelease([=] {
		if (!this->pause || this->gameOver) {
			return;
		}

		this->getApp()->changePage("main_menu");
	});

	quit__text_button->setOnRelease([=] {
		if (!this->pause || this->gameOver) {
			return;
		}

		this->getApp()->setIsRunning(false);
	});
}

void Tetris::PlayPage::initGameOverMenu()
{
	Uint32 windowWidth = static_cast<Uint32>(this->app->getWindowWidth());

	Text* header__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"Game Over",
		50,
		&windowWidth,
		0.f,
		60.f,
		{ 200, 70, 103, 255 });
	header__text->setPositionX(windowWidth / 2.f - header__text->getWidth() / 2.f);

	Text* level__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"1",
		22,
		&windowWidth,
		0.f,
		140.f,
		{ 255, 255, 255, 255 });
	level__text->setPositionX(windowWidth / 2.f - level__text->getWidth() / 2.f);

	Text* lines__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"1",
		22,
		&windowWidth,
		0.f,
		180.f,
		{ 255, 255, 255, 255 });
	lines__text->setPositionX(windowWidth / 2.f - lines__text->getWidth() / 2.f);

	Text* score__text = new Text(
		this->app->getRenderer(),
		"assets/fonts/open_sans/bold.ttf",
		"1",
		22,
		&windowWidth,
		0.f,
		220.f,
		{ 255, 255, 255, 255 });
	score__text->setPositionX(windowWidth / 2.f - score__text->getWidth() / 2.f);

	TextButton* restart__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Restart",
		31,
		400,
		65,
		this->app->getWindowWidth() / 2 - 200,
		280,
		{ 200, 70, 103, 255 },
		{ 0, 0, 0, 255 },
		5,
		5);

	TextButton* main_menu__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Main Menu",
		31,
		400,
		65,
		this->app->getWindowWidth() / 2 - 200,
		380,
		{ 200, 70, 103, 255 },
		{ 0, 0, 0, 255 },
		5,
		5);

	TextButton* quit__text_button = new TextButton(
		this->app->getRenderer(),
		"assets/fonts/swansea/bold.ttf",
		"Quit the game",
		31,
		400,
		65,
		this->app->getWindowWidth() / 2 - 200,
		480,
		{ 200, 70, 103, 255 },
		{ 0, 0, 0, 255 },
		5,
		5);

	Layout* menu = new Layout(
		this->app->getRenderer(),
		this->app->getWindowWidth(),
		this->app->getWindowHeight(),
		0.f,
		0.f,
		{ 0, 0, 0, 200 },
		{
			{ "header__text", header__text },
			{ "level__text", level__text },
			{ "lines__text", lines__text },
			{ "score__text", score__text },
			{ "restart__text_button", restart__text_button },
			{ "main_menu__text_button", main_menu__text_button },
			{ "quit__text_button", quit__text_button }
		});
	menu->setVisibility(false);

	this->addRenderable("game_over_menu__layout", menu);

	restart__text_button->setOnRelease([=] {
		if (!this->gameOver) {
			return;
		}

		this->getApp()->restartPage();
	});

	main_menu__text_button->setOnRelease([=] {
		if (!this->gameOver) {
			return;
		}

		this->getApp()->changePage("main_menu");
		});

	quit__text_button->setOnRelease([=] {
		if (!this->gameOver) {
			return;
		}

		this->getApp()->setIsRunning(false);
		});
}

void Tetris::PlayPage::initKeyDownEvents()
{
	this->keyDownEvents[SDLK_ESCAPE] = [=] {
		if (this->pause) {
			return;
		}

		Layout* menu = this->getRenderable<Layout>("pause_menu__layout");

		this->pause = true;
		this->isSoftDropOn = false;
		menu->setVisibility(true);
		this->removeRegularEvent("game-process");
	};

	this->keyDownEvents[SDLK_RIGHT] = [=] {
		if (this->fallingBlocks.size() == 0 || this->pause) {
			return;
		}

		bool isActionEnabled = true;

		for (auto& block : this->fallingBlocks) {
			if (block.x >= 9 || (block.y <= 19 && this->gridInfo[block.x + 1][block.y])) {
				isActionEnabled = false;
				break;
			}
		}

		if (isActionEnabled) {
			for (auto& block : this->fallingBlocks) {
				block.x++;
			}

			this->updateBlockMarkers();
		}
	};

	this->keyDownEvents[SDLK_LEFT] = [=] {
		if (this->fallingBlocks.size() == 0 || this->pause) {
			return;
		}

		bool isActionEnabled = true;

		for (auto& block : this->fallingBlocks) {
			if (block.x <= 0 || (block.y <= 19 && this->gridInfo[block.x - 1][block.y])) {
				isActionEnabled = false;
				break;
			}
		}

		if (isActionEnabled) {
			for (auto& block : this->fallingBlocks) {
				block.x--;
			}

			this->updateBlockMarkers();
		}
	};

	this->keyDownEvents[SDLK_UP] = [=] {
		if (this->fallingBlocks.size() == 0 ||
			*this->currentBlock == 'o' ||
			this->pause)
{
			return;
		}

		this->rotatePiece(true);
		this->updateBlockMarkers();
	};

	this->keyDownEvents[SDLK_z] = [=] {
		if (this->fallingBlocks.size() == 0 ||
			*this->currentBlock == 'o' ||
			this->pause)
		{
			return;
		}

		this->rotatePiece(false);
		this->updateBlockMarkers();
	};

	this->keyDownEvents[SDLK_DOWN] = [=] {
		if (this->isSoftDropOn || this->pause) {
			return;
		}

		const Uint32 resultInterval = static_cast<Uint32>(
			ceil(this->blockFallingInterval / 10));

		this->isSoftDropOn = true;
		this->addRegularEvent(
			"game-process",
			0,
			this->gameProcessTimerCallback(),
			this);
	};
}

void Tetris::PlayPage::initKeyUpEvents()
{
	this->keyUpEvents[SDLK_DOWN] = [=] {
		if (!this->isSoftDropOn || this->pause) {
			return;
		}

		this->isSoftDropOn = false;
		this->addRegularEvent(
			"game-process",
			this->blockFallingInterval,
			this->gameProcessTimerCallback(),
			this);
	};
}

void Tetris::PlayPage::initRegularEvents()
{
	this->addRegularEvent(
		"game-process",
		0,
		this->gameProcessTimerCallback(),
		this);
}

SDL_TimerCallback Tetris::PlayPage::gameProcessTimerCallback()
{
	return [](Uint32 interval, void* param) -> Uint32 {
		PlayPage* page = static_cast<PlayPage*>(param);
		const Uint32 resultInterval = page->isSoftDropOn ?
			static_cast<Uint32>(ceil(page->blockFallingInterval / 10)) :
			page->blockFallingInterval;

		if (page->fallingBlocks.size() == 0) {
			page->clearFilledGridRows();
			page->choosePiece();

			TetrisPieceData currentPieceData = page->pieceData[*page->currentBlock];

			for (auto& blockPosition : currentPieceData.startBlockPositions) {
				page->fallingBlocks.push_back({
					blockPosition.x,
					blockPosition.y,
					currentPieceData.r,
					currentPieceData.g,
					currentPieceData.b,
					currentPieceData.a });
			}

			page->updateBlockMarkers();

			return resultInterval;
		}

		bool touchedTheGround = false;

		for (auto& block : page->fallingBlocks) {
			if (block.y <= 20 && (block.y == 0 || page->gridInfo[block.x][block.y - 1])) {
				touchedTheGround = true;
				break;
			}
		}

		if (touchedTheGround) {
			for (auto& block : page->fallingBlocks) {
				if (block.y <= 19) {
					page->gridInfo[block.x][block.y] = true;
				}
				else {
					page->pause = true;
					page->gameOver = true;
					page->isSoftDropOn = false;

					page->addExecuteFunctionEvent([page] {
						page->saveGameOverResults();
					});
					page->removeRegularEvent("game-process");
					break;
				}
			}

			page->idleBlocks.splice(page->idleBlocks.end(), page->fallingBlocks);
			page->updateBlockMarkers();
		}
		else {
			for (auto& block : page->fallingBlocks) {
				block.y--;
			}

			if (page->isSoftDropOn) {
				page->score += 1;
				page->addExecuteFunctionEvent([page] {
					Text* scoreValue = page->getRenderable<Text>("score_value__text");
					scoreValue->setContent(std::to_string(page->score));
					scoreValue->setPositionX(330 + 150 / 2.f - scoreValue->getWidth() / 2.f);
				});
			}
		}

		return resultInterval;
	};
}
