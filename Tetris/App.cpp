#include "App.h"

App::App(
	const char* version,
	int windowWidth,
	int windowHeight
) {
	this->version = version;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf(
			"SDL could not initialize! SDL_Error: %s\n",
			SDL_GetError());
		return;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf(
			"SDL_image could not initialize! SDL_image Error: %s\n",
			IMG_GetError());
	}

	if (TTF_Init() == -1)
	{
		printf(
			"SDL_ttf could not initialize! SDL_ttf Error: %s\n",
			TTF_GetError());
	}

	this->window = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->windowWidth,
		this->windowHeight,
		SDL_WINDOW_SHOWN);
	if (this->window == nullptr) {
		printf(
			"Window could not be created! SDL_Error: %s\n",
			SDL_GetError());
		return;
	}

	this->renderer = SDL_CreateRenderer(
		this->window,
		-1,
		0);
	if (this->renderer == nullptr) {
		printf(
			"Renderer could not be created! SDL_Error: %s\n",
			SDL_GetError());
		return;
	}

	this->isRunning = true;
}

App::~App() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Renderer* App::getRenderer() {
	return this->renderer;
}
