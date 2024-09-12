#include "App.h"

App::App(
	std::string version,
	int fps,
	bool vSync,
	int windowWidth,
	int windowHeight,
	App::Location startLocation
) {
	this->version = version;
	this->fps = fps;
	this->vSync = vSync;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->currentLocation = startLocation;
	this->previousLocation = startLocation;

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
		SDL_RENDERER_ACCELERATED);

	if (this->renderer == nullptr) {
		printf(
			"Renderer could not be created! SDL_Error: %s\n",
			SDL_GetError());
		return;
	}

	SDL_RenderSetVSync(this->renderer, this->vSync);

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

float App::getDeltaTime() const {
	return this->deltaTime;
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

bool App::getVSync() const {
	return this->vSync;
}

bool App::getRunning() const {
	return this->isRunning;
}

void App::setCurrentLocation(const App::Location& value) {
	this->currentLocation = value;
}

void App::setPreviousLocation(const App::Location& value) {
	this->previousLocation = value;
}

void App::setDeltaTime(const float& value) {
	this->deltaTime = value;
}

void App::setLastFrameTime(const int& value) {
	this->lastFrameTime = value;
}

void App::setFps(const int& value) {
	this->fps = value;
}

void App::setVSync(const bool& value) {
	if (this->vSync == value) {
		return;
	}

	this->vSync = value;

	SDL_RenderSetVSync(this->renderer, this->vSync);
}

void App::setRunning(const bool& value) {
	this->isRunning = value;
}
