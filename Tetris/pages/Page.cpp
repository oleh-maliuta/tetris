#include "Page.h"

Tetris::Page::Page(
	Application* app)
{
	this->app = app;
	this->onQuit = [=] { this->app->setIsRunning(false); };
}

Tetris::Page::~Page()
{
	for (const auto& el : this->renderables) {
		delete el.second;
	}

	for (const auto& el : this->soundEffects) {
		delete el.second;
	}

	delete this->music;
}

void Tetris::Page::exec()
{
	this->input();

	if (!this->app->getIsRunning()) {
		return;
	}

	this->manageRegularEvents();
	this->update();

	SDL_Renderer* renderer = this->app->getRenderer();

	SDL_SetRenderDrawColor(
		renderer,
		this->backgroundColor.r,
		this->backgroundColor.g,
		this->backgroundColor.b,
		this->backgroundColor.a);

	SDL_RenderClear(renderer);
	this->render();
	SDL_RenderPresent(renderer);
}

void Tetris::Page::manageRegularEvents()
{
	std::list<std::string> eventsToErase;

	for (auto& reRef : this->regularEvents) {
		const Uint32 currentTime = SDL_GetTicks();
		RegularEventData* regularEvent = &reRef.second;

		if (currentTime - regularEvent->startTime >= regularEvent->interval) {
			const Uint32 resultInterval = regularEvent->callback(
				regularEvent->interval,
				regularEvent->param);

			if (resultInterval == 0) {
				eventsToErase.push_back(reRef.first);
				continue;
			}

			regularEvent->interval = resultInterval;
			regularEvent->startTime = currentTime;
		}
	}

	if (eventsToErase.size() > 0) {
		std::erase_if(this->regularEvents, [eventsToErase](const auto& el) {
			for (std::string key : eventsToErase) {
				if (key == el.first) {
					return true;
				}
			}
			return false;
		});
	}
}

void Tetris::Page::init()
{
	for (const auto& el : this->renderables) {
		el.second->init();
	}

	for (const auto& el : this->soundEffects) {
		el.second->init();
	}

	if (this->music != nullptr) {
		this->music->init();
	}

	this->isInitialized = true;
}

void Tetris::Page::clean()
{
	if (!this->isInitialized) {
		return;
	}

	this->app->haltSound();
	this->app->haltMusic();

	for (const auto& el : this->renderables) {
		el.second->destroy();
	}

	for (const auto& el : this->soundEffects) {
		el.second->destroy();
	}
	
	if (this->music != nullptr) {
		this->music->destroy();
	}

	this->regularEvents.clear();
	this->isInitialized = false;
}

void Tetris::Page::update() {}

void Tetris::Page::setRenderable(
	const std::string& key,
	Renderable* obj)
{
	this->renderables.push_back(std::pair(key, obj));
}

Tetris::SoundEffect* Tetris::Page::setSoundEffect(
	const std::string& key,
	const std::string& path)
{
	const auto it = this->soundEffects.find(key);

	if (it != this->soundEffects.end()) {
		delete it->second;
		this->soundEffects.erase(it->first);
	}

	SoundEffect* soundEffect = new SoundEffect(path);

	if (this->isInitialized) {
		soundEffect->init();
	}

	this->soundEffects[key] = soundEffect;
	return soundEffect;
}

Tetris::SoundEffect* Tetris::Page::getSoundEffect(
	const std::string& key)
{
	const auto it = this->soundEffects.find(key);
	if (it != this->soundEffects.end()) {
		return it->second;
	}
	return nullptr;
}

void Tetris::Page::muteAllSoundEffects(
	const bool& value)
{
	for (const auto& el : this->soundEffects) {
		el.second->mute(value);
	}
}

void Tetris::Page::setMusic(
	const std::string& path)
{
	if (this->music != nullptr) {
		delete this->music;
		this->music = nullptr;
	}

	SoundTrack* music = new SoundTrack(path);
	if (this->isInitialized) {
		music->init();
	}
	this->music = music;
}

void Tetris::Page::playMusic()
{
	this->music->play();
}

void Tetris::Page::muteMusic(
	const bool& value)
{
	this->music->mute(value);
}

void Tetris::Page::setRegularEvent(
	const std::string& key,
	std::function<Uint32(Uint32, void*)> callback,
	Uint32 interval,
	void* param)
{
	const auto it = this->regularEvents.find(key);
	if (it != this->regularEvents.end()) {
		this->regularEvents.erase(it->first);
	}

	const RegularEventData data = {
		SDL_GetTicks(),
		interval,
		param,
		callback
	};
	this->regularEvents[key] = data;
}

void Tetris::Page::removeRegularEvent(
	const std::string& key)
{
	const auto it = this->regularEvents.find(key);
	if (it != this->regularEvents.end()) {
		this->regularEvents.erase(it->first);
	}
}

Tetris::Application* Tetris::Page::getApp() const
{
	return this->app;
}

void Tetris::Page::input()
{
	SDL_Event event;
	int mousePosX, mousePosY;

	SDL_GetMouseState(&mousePosX, &mousePosY);

	while (SDL_PollEvent(&event) && this->app->getIsRunning())
	{
		if (event.type == SDL_QUIT) {
			this->onQuit();
		}
		else if (event.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				for (const auto& el : this->renderables) {
					if (el.second && el.second->getVisibility()) {
						if (el.second->isCursorIn(mousePosX, mousePosY)) {
							el.second->getOnRelease()();
						}

						Layout* layout = dynamic_cast<Layout*>(el.second);
						if (layout) {
							for (const auto& obj : layout->objects) {
								if (
									obj.second->getVisibility() &&
									obj.second->isCursorIn(mousePosX, mousePosY))
								{
									obj.second->getOnRelease()();
								}
							}
						}
					}
				}
			}
		}
		else if (event.type == SDL_KEYDOWN) {
			const SDL_Keycode key = event.key.keysym.sym;
			const auto it = this->keyDownEvents.find(key);

			if (it != this->keyDownEvents.end()) {
				it->second();
			}
		}
		else if (event.type == SDL_KEYUP) {
			const SDL_Keycode key = event.key.keysym.sym;
			const auto it = this->keyUpEvents.find(key);

			if (it != this->keyUpEvents.end()) {
				it->second();
			}
		}
	}
}

void Tetris::Page::render()
{
	for (const auto& el : this->renderables) {
		el.second->render();
	}
}
