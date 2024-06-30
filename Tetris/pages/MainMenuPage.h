#pragma once

#include "Page.h"
#include "../Loader.h"
#include "../renderables/Texture.h"

class MainMenuPage
	: public Page
{
private:
	Texture* logo = nullptr;
public:
	MainMenuPage(App*);
	~MainMenuPage();
	virtual void init() override;
	virtual void clean() override;
	virtual void input() override;
	virtual void update() override;
	virtual void render() override;
};

