#pragma once

#ifndef PAGE_PLAYPAGE_H
#define PAGE_PLAYPAGE_H

#include <format>
#include "Page.h"
#include "../Loader.h"
#include "../renderables/Rectangle.h"
#include "../renderables/Text.h"
#include "../structures/Tetris_Cell.h"

class PlayPage :
    public Page
{
public:

	PlayPage(App* app);

	virtual void init() override;
	virtual void clean() override;

protected:

	virtual void input() override;
	virtual void update() override;
	virtual void render() override;

private:

	std::list<Tetris_Cell> cells;
	unsigned int currentPiece = 0;
	unsigned int nextPiece = 0;
	unsigned int level = 0;
	unsigned int lines = 0;
	unsigned int score = 0;
};

#endif
