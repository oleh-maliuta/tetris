#include "App.h"

App::App(
	const int& windowWidth,
	const int& windowHeight) {
	std::map<std::string, std::string> app_settings;
	this->getAppSettings(app_settings);

	this->version = app_settings["app_version"];
	this->fps = std::stoi(app_settings["fps"]);
	this->vSync = app_settings["v_sync"] == "1";

	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf(
			"SDL could not initialize! SDL_Error: %s\n",
			SDL_GetError());
		return;
	}

	const int imgFlags = IMG_INIT_PNG;
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
	for (const auto& el : this->pages) {
		delete el.second;
	}

	std::map<std::string, std::string> data;

	data["app_version"] = this->version;
	data["fps"] = std::to_string(this->fps);
	data["v_sync"] = this->vSync ? "1" : "0";

	this->saveAppSettings(data);

	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void App::changePage(const std::string& key) {
	if (this->pages.find(key) == this->pages.end()) {
		printf("Could not change the page because it does not exist.\n");
		this->setRunning(false);
		return;
	}

	this->currentLocation = key;
}

void App::run(const std::string& startPage) {
	if (this->pages.find(startPage) == this->pages.end()) {
		printf("Start page not found.\n");
		return;
	}

	this->currentLocation = startPage;
	this->previousLocation = startPage;

	this->pages[this->currentLocation]->init();

	while (this->isRunning)
	{
		int frame_time = (1000 / this->fps);
		int delay_time = frame_time - SDL_GetTicks() - this->lastFrameTime;

		if (delay_time > 0 && delay_time <= frame_time) {
			SDL_Delay(delay_time);
		}

		this->deltaTime = static_cast<float>(SDL_GetTicks()) / this->lastFrameTime / 1000.0f;
		this->lastFrameTime = SDL_GetTicks();

		this->pages[this->previousLocation]->exec();

		if (this->currentLocation != this->previousLocation) {
			this->pages[this->previousLocation]->clean();
			this->pages[this->currentLocation]->init();
			this->previousLocation = this->currentLocation;
		}
	}

	this->pages[this->previousLocation]->clean();
}

SDL_Renderer* App::getRenderer() const {
	return this->renderer;
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

bool App::getAppSettings(std::map<std::string, std::string>& data) {
	std::ifstream app_settings_file("app_settings.txt");

	if (!app_settings_file.is_open()) {
		printf("Unable to open file for reading.\n");
		return false;
	}

	const char* delimiter = ":";
	std::string line;

	while (std::getline(app_settings_file, line)) {
		size_t del_pos = line.find(delimiter);

		std::string key = line.substr(0, del_pos);
		std::string value = line.substr(del_pos + 1, line.length() - 1);

		data[key] = value;
	}

	app_settings_file.close();
	return true;
}

bool App::saveAppSettings(const std::map<std::string, std::string>& data) {
	std::ofstream app_settings_file("app_settings.txt");

	if (!app_settings_file.is_open()) {
		printf("Unable to open file for writing.\n");
		return false;
	}

	const char* delimiter = ":";

	for (const auto& el : data) {
		app_settings_file << el.first << delimiter << el.second << "\n";
	}

	app_settings_file.close();
}
