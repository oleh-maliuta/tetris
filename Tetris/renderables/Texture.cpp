#include "Texture.h"

Tetris::Texture::Texture(
	SDL_Renderer* renderer,
	const std::string& path,
	const float& x,
	const float& y,
	const float* width,
	const float* height,
	const SDL_FPoint* rotationPoint,
	const SDL_RendererFlip& flip,
	const SDL_Color& moduleColor,
	const double& angle)
	: Renderable(renderer)
{
	this->filePath = path;
	this->positionX = x;
	this->positionY = y;
	this->width = width != nullptr ? new float(*width) : nullptr;
	this->height = height != nullptr ? new float(*height) : nullptr;
	this->rotationPoint = rotationPoint != nullptr ? new SDL_FPoint(*rotationPoint) : nullptr;
	this->flip = flip;
	this->moduleRed = moduleColor.r;
	this->moduleGreen = moduleColor.g;
	this->moduleBlue = moduleColor.b;
	this->angle = angle;

	Loader::getImageSize(
		path.c_str(),
		&this->defaultWidth,
		&this->defaultHeight);
}

Tetris::Texture::~Texture()
{
	this->destroy();
	delete this->width;
	delete this->height;
	delete this->rotationPoint;
}

bool Tetris::Texture::isCursorIn(
	const float& x,
	const float& y)
{
	const float posX = this->getPositionX();
	const float posY = this->getPositionY();

	return
		x >= posX && x < posX + this->getWidth() &&
		y >= posY && y < posY + this->getHeight();
}

void Tetris::Texture::init()
{
	if (this->isInitialized) {
		return;
	}

	this->sdlTexture = Loader::getTextureFromImage(
		this->renderer,
		this->filePath.c_str());

	Renderable::init();
}

void Tetris::Texture::render()
{
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	SDL_FRect textureRectangle = {
		this->positionX,
		this->positionY,
		this->width != nullptr ? *this->width : this->defaultWidth,
		this->height != nullptr ? *this->height : this->defaultHeight
	};

	SDL_RenderCopyExF(
		this->renderer,
		this->sdlTexture,
		nullptr,
		&textureRectangle,
		this->angle,
		this->rotationPoint,
		this->flip);
	SDL_SetTextureColorMod(
		this->sdlTexture,
		this->moduleRed,
		this->moduleGreen,
		this->moduleBlue);

	Renderable::render();
}

void Tetris::Texture::destroy()
{
	if (!this->isInitialized) {
		return;
	}

	if (this->sdlTexture != nullptr) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = nullptr;
	}

	Renderable::destroy();
}

SDL_FPoint* Tetris::Texture::getRotationPoint() const
{
	return this->rotationPoint != nullptr ?
		new SDL_FPoint(*this->rotationPoint) :
		nullptr;
}

SDL_RendererFlip Tetris::Texture::getFlip() const
{
	return this->flip;
}

SDL_Color Tetris::Texture::getModuleColor() const
{
	return {
		this->moduleRed,
		this->moduleGreen,
		this->moduleBlue
	};
}

std::string Tetris::Texture::getFilePath() const
{
	return this->filePath;
}

Uint8 Tetris::Texture::getModuleRed() const
{
	return this->moduleRed;
}

Uint8 Tetris::Texture::getModuleGreen() const
{
	return this->moduleGreen;
}

Uint8 Tetris::Texture::getModuleBlue() const
{
	return this->moduleBlue;
}

double Tetris::Texture::getAngle() const
{
	return this->angle;
}

float Tetris::Texture::getPositionX() const
{
	return this->positionX;
}

float Tetris::Texture::getPositionY() const
{
	return this->positionY;
}

float Tetris::Texture::getWidth() const
{
	if (this->width != nullptr) {
		return *this->width;
	}

	return this->defaultWidth;
}

float Tetris::Texture::getHeight() const
{
	if (this->height != nullptr) {
		return *this->height;
	}

	return this->defaultHeight;
}

void Tetris::Texture::setRotationPoint(
	const SDL_FPoint* value)
{
	if (this->rotationPoint != nullptr) {
		delete this->rotationPoint;
	}

	if (value != nullptr) {
		this->rotationPoint = new SDL_FPoint(*value);
	}
	else {
		this->rotationPoint = nullptr;
	}
}

void Tetris::Texture::setFilePath(
	const std::string& value)
{
	if (this->sdlTexture != nullptr) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = nullptr;
	}

	this->filePath = value;

	if (this->isInitialized) {
		this->sdlTexture = Loader::getTextureFromImage(
			this->renderer,
			this->filePath.c_str());
	}
}

void Tetris::Texture::setModuleColor(
	const SDL_Color& color)
{
	this->moduleRed = color.r;
	this->moduleGreen = color.g;
	this->moduleBlue = color.b;
}

void Tetris::Texture::setModuleRed(
	const Uint8& value)
{
	this->moduleRed = value;
}

void Tetris::Texture::setModuleGreen(
	const Uint8& value)
{
	this->moduleGreen = value;
}

void Tetris::Texture::setModuleBlue(
	const Uint8& value)
{
	this->moduleBlue = value;
}

void Tetris::Texture::setAngle(
	const double& value)
{
	this->angle = value;
}

void Tetris::Texture::setPositionX(
	const float& value)
{
	this->positionX = value;
}

void Tetris::Texture::setPositionY(
	const float& value)
{
	this->positionY = value;
}

void Tetris::Texture::setWidth(
	const float* value)
{
	delete this->width;
	this->width = nullptr;

	if (value != nullptr) {
		this->width = new float(*value);
	}
}

void Tetris::Texture::setHeight(
	const float* value)
{
	delete this->height;
	this->height = nullptr;

	if (value != nullptr) {
		this->height = new float(*value);
	}
}
