#pragma once

#ifndef PAGE_PLAYPAGE_H
#define PAGE_PLAYPAGE_H

#include <format>
#include "Page.h"
#include "../renderables/Rectangle.h"

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
};

#endif
