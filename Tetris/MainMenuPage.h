#pragma once

#include "Page.h"

class MainMenuPage : public Page
{
private:
	SDL_Texture* logoTexture = NULL;
	SDL_Rect logoRect;
public:
	MainMenuPage(App*);
	virtual void init() override;
	virtual void clean() override;
	virtual void input() override;
	virtual void update() override;
	virtual void render() override;
};

