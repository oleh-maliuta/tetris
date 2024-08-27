#include "App.h"

App::App(
	std::string version,
	int fps,
	int windowWidth,
	int windowHeight
) {
	this->version = version;
	this->fps = fps;
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
		return;
	}

	if (TTF_Init() == -1)
	{
		printf(
			"SDL_ttf could not initialize! SDL_ttf Error: %s\n",
			TTF_GetError());
		return;
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

SDL_Renderer* App::getRenderer() const {
	return this->renderer;
}

App::Location App::getCurrentLocation() const {
	return this->currentLocation;
}

App::Location App::getPreviousLocation() const {
	return this->previousLocation;
}

std::string App::getVersion() const {
	return this->version;
}

bool App::getRunning() const {
	return this->isRunning;
}

int App::getLastFrameTime() const {
	return this->lastFrameTime;
}

int App::getFps() const {
	return this->fps;
}

int App::getWindowWidth() const {
	return this->windowWidth;
}

int App::getWindowHeight() const {
	return this->windowHeight;
}

float App::getDeltaTime() const {
	return this->deltaTime;
}

void App::setCurrentLocation(App::Location value) {
	this->currentLocation = value;
}

void App::setPreviousLocation(App::Location value) {
	this->previousLocation = value;
}

void App::setRunning(bool value) {
	this->isRunning = value;
}

void App::setLastFrameTime(int value) {
	this->lastFrameTime = value;
}

void App::setFps(int value) {
	this->fps = value;
}

void App::setDeltaTime(float value) {
	this->deltaTime = value;
}
