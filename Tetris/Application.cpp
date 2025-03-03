#include "Application.h"

Tetris::Application::Application(
	const int& windowWidth,
	const int& windowHeight)
{
	this->getAppSettings();

	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
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

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf(
			"SDL_mixer could not initialize! SDL_mixer Error: %s\n",
			Mix_GetError());
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
	SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);

	SDL_Surface* iconSurface = IMG_Load("assets/images/png/icon.png");

	if (iconSurface == nullptr) {
		printf("Failed to load icon image! SDL_Error: %s\n",
			IMG_GetError());
	}

	SDL_SetWindowIcon(this->window, iconSurface);
	SDL_FreeSurface(iconSurface);

	this->isRunning = true;
}

Tetris::Application::~Application()
{
	for (const auto& el : this->pages) {
		delete el.second;
	}

	this->saveAppSettings();

	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Tetris::Application::changePage(
	const std::string& key)
{
	if (this->pages.find(key) == this->pages.end()) {
		printf("Could not change the page because it does not exist.\n");
		this->setIsRunning(false);
		return;
	}

	this->currentLocation = key;
}

void Tetris::Application::restartPage()
{
	this->isRestartRequired = true;
}

void Tetris::Application::run(
	const std::string& startPage)
{
	if (this->pages.find(startPage) == this->pages.end()) {
		printf("Start page not found.\n");
		return;
	}

	this->currentLocation = startPage;
	this->previousLocation = startPage;

	Page* currentPage = this->pages[this->currentLocation];
	currentPage->init();

	while (this->isRunning)
	{
		int frameTime = (1000 / this->fps);
		int delayTime = frameTime - SDL_GetTicks() - this->lastFrameTime;

		if (delayTime > 0 && delayTime <= frameTime) {
			SDL_Delay(delayTime);
		}

		this->deltaTime = static_cast<float>(SDL_GetTicks()) / this->lastFrameTime / 1000.0f;
		this->lastFrameTime = SDL_GetTicks();

		if (this->isRestartRequired) {
			currentPage->clean();
			currentPage->init();
			this->isRestartRequired = false;
		}

		if (this->currentLocation != this->previousLocation) {
			currentPage->clean();
			currentPage = this->pages[this->currentLocation];
			currentPage->init();
			this->previousLocation = this->currentLocation;
		}

		currentPage->exec();
	}

	currentPage->clean();
}

void Tetris::Application::haltSound()
{
	Mix_HaltChannel(-1);
}

void Tetris::Application::pauseMusic()
{
	if (Mix_PlayingMusic() == 1) {
		Mix_PauseMusic();
	}
}

void Tetris::Application::resumeMusic()
{
	if (Mix_PausedMusic() == 1) {
		Mix_ResumeMusic();
	}
}

void Tetris::Application::haltMusic()
{
	Mix_HaltMusic();
}

SDL_Renderer* Tetris::Application::getRenderer() const
{
	return this->renderer;
}

float Tetris::Application::getDeltaTime() const
{
	return this->deltaTime;
}

int Tetris::Application::getLastFrameTime() const
{
	return this->lastFrameTime;
}

int Tetris::Application::getFps() const
{
	return this->fps;
}

int Tetris::Application::getWindowWidth() const
{
	return this->windowWidth;
}

int Tetris::Application::getWindowHeight() const
{
	return this->windowHeight;
}

bool Tetris::Application::getVSync() const
{
	return this->vSync;
}

bool Tetris::Application::getColorBlocksOn() const
{
	return this->colorBlocksOn;
}

bool Tetris::Application::getMusicOn() const
{
	return this->musicOn;
}

bool Tetris::Application::getSoundEffectsOn() const
{
	return this->soundEffectsOn;
}

bool Tetris::Application::getIsRunning() const
{
	return this->isRunning;
}

void Tetris::Application::setFps(
	const int& value)
{
	this->fps = value;
}

void Tetris::Application::setVSync(
	const bool& value)
{
	if (this->vSync == value) {
		return;
	}

	this->vSync = value;

	SDL_RenderSetVSync(this->renderer, this->vSync);
}

void Tetris::Application::setColorBlocksOn(
	const bool& value)
{
	this->colorBlocksOn = value;
}

void Tetris::Application::setMusicOn(
	const bool& value)
{
	this->musicOn = value;
}

void Tetris::Application::setSoundEffectsOn(
	const bool& value)
{
	this->soundEffectsOn = value;
}

void Tetris::Application::setIsRunning(
	const bool& value)
{
	this->isRunning = value;
}

void Tetris::Application::getAppSettings()
{
	std::ifstream appSettingsFile("app_settings.json");

	if (!appSettingsFile.is_open()) {
		this->fps = 60;
		this->vSync = false;
		this->colorBlocksOn = true;
		this->musicOn = true;
		this->soundEffectsOn = true;
		return;
	}

	nlohmann::json appSettings;
	
	try
	{
		appSettingsFile >> appSettings;
	}
	catch (const nlohmann::json::parse_error& ex)
	{
		appSettings = {
			{"fps", 60},
			{"v_sync", false},
			{"color_blocks", true},
			{"music", true},
			{"sound_effects", true}
		};
	}

	appSettingsFile.close();

	if (appSettings.contains("fps")) {
		this->fps = appSettings["fps"];
	}
	else {
		this->fps = 60;
	}

	if (appSettings.contains("v_sync")) {
		this->vSync = appSettings["v_sync"];
	}
	else {
		this->vSync = false;
	}

	if (appSettings.contains("color_blocks")) {
		this->colorBlocksOn = appSettings["color_blocks"];
	}
	else {
		this->colorBlocksOn = true;
	}

	if (appSettings.contains("music")) {
		this->musicOn = appSettings["music"];
	}
	else {
		this->musicOn = true;
	}

	if (appSettings.contains("sound_effects")) {
		this->soundEffectsOn = appSettings["sound_effects"];
	}
	else {
		this->soundEffectsOn = true;
	}
}

void Tetris::Application::saveAppSettings()
{
	std::ofstream appSettingsFile("app_settings.json");
	nlohmann::json appSettings = {
		{"fps", this->fps},
		{"v_sync", this->vSync},
		{"color_blocks", this->colorBlocksOn},
		{"music", this->musicOn},
		{"sound_effects", this->soundEffectsOn}
	};

	appSettingsFile << appSettings.dump(4);
	appSettingsFile.close();
}
