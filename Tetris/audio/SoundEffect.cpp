#include "SoundEffect.h"

Tetris::SoundEffect::SoundEffect(
	const std::string& path)
{
	this->path = path;
}

Tetris::SoundEffect::~SoundEffect()
{
	this->destroy();
}

void Tetris::SoundEffect::init()
{
	if (this->isInitialized) {
		return;
	}

	this->effect = Mix_LoadWAV(this->path.c_str());
	this->isInitialized = true;
}

void Tetris::SoundEffect::destroy()
{
	if (!this->isInitialized) {
		return;
	}

	Mix_FreeChunk(this->effect);
	this->effect = nullptr;
	this->isInitialized = false;
}

void Tetris::SoundEffect::play()
{
	if (!this->isInitialized) {
		return;
	}

	Mix_PlayChannel(-1, this->effect, 0);
}
