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
				{{ 4, 21 }, { 4, 19 }, { 4, 20 }, { 4, 22 }},
				251, 112, 36, 255
			}
		},
		{'o', {
				{{ 4, 19 }, { 4, 20 }, { 5, 19 }, { 5, 20 }},
				243, 209, 26, 255
			}
		},
		{'t', {
				{{ 4, 19 }, { 3, 19 }, { 5, 19 }, { 4, 20 }},
				167, 47, 232, 255
			}
		},
		{'j', {
				{{ 4, 19 }, { 3, 19 }, { 5, 19 }, { 3, 20 }},
				117, 196, 63, 255
			}
		},
		{'l', {
				{{ 4, 19 }, { 3, 19 }, { 5, 19 }, { 5, 20 }},
				61, 194, 132, 255
			}
		},
		{'s', {
				{{ 4, 19 }, { 3, 19 }, { 4, 20 }, { 5, 20 }},
				238, 30, 40, 255
			}
		},
		{'z', {
				{{ 4, 19 }, { 5, 19 }, { 4, 20 }, { 3, 20 }},
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
		}
	}

	this->initKeyDownEvents();
	this->initKeyUpEvents();
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
	this->pieceRotationIndex = 0;
	this->level = 1;
	this->lines = 0;
	this->score = 0;
	this->isBlockFallingAccelerated = false;

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

void Tetris::PlayPage::updateBlockMarkers()
{
	for (auto& marker : this->blockMarkers) {
		if (marker.y < 0) {
			continue;
		}

		Rectangle* cellMarker = this->getRenderable<Rectangle>(
			std::format("cell_marker_{}_{}__rectangle", marker.x, marker.y));

		cellMarker->setVisibility(false);
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
			if (marker.y <= 20 && (marker.y == 0 || this->cellInfo[marker.x][marker.y - 1])) {
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

		Rectangle* cellMarker = this->getRenderable<Rectangle>(
			std::format("cell_marker_{}_{}__rectangle", marker.x, marker.y));

		cellMarker->setVisibility(true);
	}
}

void Tetris::PlayPage::test_rotatePiece(
	bool clockwise,
	bool shouldOffset)
{
	int oldRotationIndex = this->pieceRotationIndex;
	TetrisBlockData pivot = this->fallingBlocks.front();
	this->pieceRotationIndex += clockwise ? 1 : -1;
	this->pieceRotationIndex = PlayPage::test_mod(this->pieceRotationIndex, 4);

	for (auto& block : this->fallingBlocks)
	{
		this->test_rotateTile(
			block,
			{ pivot.x, pivot.y },
			clockwise);

	}

	if (!shouldOffset)
	{
		return;
	}

	bool canOffset = this->test_offset(
		oldRotationIndex,
		this->pieceRotationIndex);

	if (!canOffset)
	{
		this->test_rotatePiece(!clockwise, false);
	}
}

int Tetris::PlayPage::test_mod(int x, int m)
{
	return (x % m + m) % m;
}

void Tetris::PlayPage::test_rotateTile(
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

bool Tetris::PlayPage::test_offset(
	int oldRotIndex,
	int newRotIndex)
{
	TetrisCellPosition offsetVal1, offsetVal2, endOffset;
	bool movePossible = false;

	endOffset = { 0, 0 };

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

		if (this->test_canMovePiece(endOffset))
		{
			movePossible = true;
			break;
		}
	}

	if (movePossible)
	{
		this->test_movePiece(endOffset);
	}

	return movePossible;
}

bool Tetris::PlayPage::test_canMovePiece(
	TetrisCellPosition movement)
{
	for (auto& block : this->fallingBlocks)
	{
		TetrisCellPosition endPos = {
			movement.x + block.x,
			movement.y + block.y
		};

		if (!this->test_canTileMove(block, endPos))
		{
			return false;
		}
	}
	return true;
}

bool Tetris::PlayPage::test_canTileMove(TetrisBlockData& curBlock, TetrisCellPosition endPos)
{
	if (!this->test_isInBounds(endPos))
	{
		return false;
	}
	if (!this->test_isPosEmpty(endPos))
	{
		return false;
	}
	return true;
}

bool Tetris::PlayPage::test_isInBounds(
	TetrisCellPosition coordToTest)
{
	if (coordToTest.x < 0 || coordToTest.x >= 9 || coordToTest.y < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Tetris::PlayPage::test_isPosEmpty(
	TetrisCellPosition coordToTest)
{
	if (coordToTest.y >= 20)
	{
		return true;
	}

	if (this->cellInfo[coordToTest.x][coordToTest.y])
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Tetris::PlayPage::test_movePiece(
	TetrisCellPosition movement)
{
	for (auto& block : this->fallingBlocks)
	{
		TetrisCellPosition endPos = {
			movement.x + block.x,
			movement.y + block.y
		};

		if (!this->test_canTileMove(block, endPos))
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
	if (this->fallingBlocks.size() == 0) {
		this->choosePiece();

		TetrisPieceData currentPieceData = this->pieceData[*this->currentBlock];

		for (auto& blockPosition : currentPieceData.startBlockPositions) {
			this->fallingBlocks.push_back({
				blockPosition.x,
				blockPosition.y,
				currentPieceData.r,
				currentPieceData.g,
				currentPieceData.b,
				currentPieceData.a
			});
		}

		this->updateBlockMarkers();
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
		if (block.y > 19) {
			continue;
		}

		cells[block.x][block.y]->setColor({
			block.r,
			block.g,
			block.b,
			block.a });
	}

	for (auto& block : this->idleBlocks) {
		if (block.y > 19) {
			continue;
		}

		cells[block.x][block.y]->setColor({
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

void Tetris::PlayPage::initKeyDownEvents()
{
	this->keyDownEvents[SDLK_RIGHT] = [=]() {
		if (this->fallingBlocks.size() == 0) {
			return;
		}

		bool isActionEnabled = true;

		for (auto& block : this->fallingBlocks) {
			if (block.x >= 9 || (block.y <= 19 && this->cellInfo[block.x + 1][block.y])) {
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

	this->keyDownEvents[SDLK_LEFT] = [=]() {
		if (this->fallingBlocks.size() == 0) {
			return;
		}

		bool isActionEnabled = true;

		for (auto& block : this->fallingBlocks) {
			if (block.x <= 0 || (block.y <= 19 && this->cellInfo[block.x - 1][block.y])) {
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

	this->keyDownEvents[SDLK_UP] = [=]() {
		if (this->fallingBlocks.size() == 0 || *this->currentBlock == 'o') {
			return;
		}

		this->test_rotatePiece(true, true);
		this->updateBlockMarkers();
	};

	this->keyDownEvents[SDLK_DOWN] = [=]() {
		if (!this->isBlockFallingAccelerated) {
			const Uint32 resultInterval = static_cast<Uint32>(
				ceil(this->blockFallingInterval / 10));

			this->isBlockFallingAccelerated = true;
			this->blockFallingTimerCallback()(0, this);
			this->addRegularEvent(
				"block-falling",
				resultInterval,
				this->blockFallingTimerCallback(),
				this);
		}
	};
}

void Tetris::PlayPage::initKeyUpEvents()
{
	this->keyUpEvents[SDLK_DOWN] = [=]() {
		if (this->isBlockFallingAccelerated) {
			this->isBlockFallingAccelerated = false;
			this->addRegularEvent(
				"block-falling",
				this->blockFallingInterval,
				this->blockFallingTimerCallback(),
				this);
		}
	};
}

void Tetris::PlayPage::initRegularEvents()
{
	this->addRegularEvent(
		"block-falling",
		this->blockFallingInterval,
		this->blockFallingTimerCallback(),
		this);
}

SDL_TimerCallback Tetris::PlayPage::blockFallingTimerCallback()
{
	return [](Uint32 interval, void* param) -> Uint32 {
		PlayPage* page = static_cast<PlayPage*>(param);
		const Uint32 resultInterval = page->isBlockFallingAccelerated ?
			static_cast<Uint32>(ceil(page->blockFallingInterval / 10)) :
			page->blockFallingInterval;

		if (page->fallingBlocks.size() == 0) {
			return resultInterval;
		}

		bool touchedTheGround = false;

		for (auto& block : page->fallingBlocks) {
			if (block.y <= 20 && (block.y == 0 || page->cellInfo[block.x][block.y - 1])) {
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
				block.y--;
			}
		}

		return resultInterval;
	};
}
