#include "SoundTrack.h"

Tetris::SoundTrack::SoundTrack(
	const std::string& path)
{
	this->path = path;
}

Tetris::SoundTrack::~SoundTrack()
{
	this->destroy();
}

void Tetris::SoundTrack::init()
{
	if (this->isInitialized) {
		return;
	}

	this->track = Mix_LoadMUS(this->path.c_str());
	this->isInitialized = true;
}

void Tetris::SoundTrack::destroy()
{
	if (!this->isInitialized) {
		return;
	}

	Mix_FreeMusic(this->track);
	this->track = nullptr;
	this->isInitialized = false;
}

void Tetris::SoundTrack::play()
{
	if (!this->isInitialized) {
		return;
	}

	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(this->track, -1);
	}
}
