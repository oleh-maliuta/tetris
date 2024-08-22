#pragma once

#ifndef PAGES_MAINMENUPAGE_H
#define PAGES_MAINMENUPAGE_H

#include "Page.h"
#include "../Loader.h"
#include "../renderables/Texture.h"
#include "../renderables/Text.h"

class MainMenuPage
	: public Page
{
private:
	Texture* logo = nullptr;
	Text* versionInfo = nullptr;
public:
	MainMenuPage(App*);
	~MainMenuPage();
	virtual void init() override;
	virtual void clean() override;
	virtual void input() override;
	virtual void update() override;
	virtual void render() override;
};

#endif
