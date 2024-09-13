#include "Texture.h"

Texture::Texture(
	SDL_Renderer* renderer,
	const std::string& path,
	const int& x,
	const int& y,
	const int* width,
	const int* height,
	const SDL_Point* rotationPoint,
	const SDL_RendererFlip& flip,
	const SDL_Color& moduleColor,
	const double& angle
) : Renderable(renderer) {
	this->filePath = path;
	this->positionX = x;
	this->positionY = y;
	this->width = width != nullptr ? new int(*width) : nullptr;
	this->height = height != nullptr ? new int(*height) : nullptr;
	this->rotationPoint = rotationPoint != nullptr ? new SDL_Point(*rotationPoint) : nullptr;
	this->flip = flip;
	this->moduleRed = moduleColor.r;
	this->moduleGreen = moduleColor.g;
	this->moduleBlue = moduleColor.b;
	this->angle = angle;

	Loader::getImageSize(path.c_str(), &this->defaultWidth, &this->defaultHeight);
}

Texture::~Texture() {
	this->destroy();
	delete this->width;
	delete this->height;
	delete this->rotationPoint;
}

bool Texture::isCursorIn(int x, int y) {
	int posX = this->getPositionX();
	int posY = this->getPositionY();

	return
		x >= posX && x < posX + this->getWidth() &&
		y >= posY && y < posY + this->getHeight();
}

void Texture::init() {
	this->sdlTexture = Loader::getTextureFromImage(
		this->renderer,
		this->filePath.c_str());

	Renderable::init();
}

void Texture::render() {
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	SDL_Rect textureRectangle = {
		this->positionX,
		this->positionY,
		this->width != nullptr ? *this->width : this->defaultWidth,
		this->height != nullptr ? *this->height : this->defaultHeight
	};

	SDL_RenderCopyEx(
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

void Texture::destroy() {
	if (this->sdlTexture != nullptr) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = nullptr;
	}

	Renderable::destroy();
}

SDL_Point* Texture::getRotationPoint() const {
	return this->rotationPoint != nullptr ? new SDL_Point(*this->rotationPoint) : nullptr;
}

SDL_RendererFlip Texture::getFlip() const {
	return this->flip;
}

SDL_Color Texture::getModuleColor() const {
	return {
		this->moduleRed,
		this->moduleGreen,
		this->moduleBlue
	};
}

std::string Texture::getFilePath() const {
	return this->filePath;
}

Uint8 Texture::getModuleRed() const {
	return this->moduleRed;
}

Uint8 Texture::getModuleGreen() const {
	return this->moduleGreen;
}

Uint8 Texture::getModuleBlue() const {
	return this->moduleBlue;
}

double Texture::getAngle() const {
	return this->angle;
}

int Texture::getPositionX() const {
	return this->positionX;
}

int Texture::getPositionY() const {
	return this->positionY;
}

int Texture::getWidth() const {
	if (this->width != nullptr) {
		return *this->width;
	}

	return this->defaultWidth;
}

int Texture::getHeight() const {
	if (this->height != nullptr) {
		return *this->height;
	}

	return this->defaultHeight;
}

void Texture::setRotationPoint(const SDL_Point* value) {
	if (this->rotationPoint != nullptr) {
		delete this->rotationPoint;
	}

	if (value != nullptr) {
		this->rotationPoint = new SDL_Point(*value);
	}
	else {
		this->rotationPoint = nullptr;
	}
}

void Texture::setFilePath(const std::string& value) {
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

void Texture::setModuleRed(const Uint8& value) {
	this->moduleRed = value;
}

void Texture::setModuleGreen(const Uint8& value) {
	this->moduleGreen = value;
}

void Texture::setModuleBlue(const Uint8& value) {
	this->moduleBlue = value;
}

void Texture::setModuleColor(const SDL_Color& color) {
	this->moduleRed = color.r;
	this->moduleGreen = color.g;
	this->moduleBlue = color.b;
}

void Texture::setPositionX(const int& value) {
	this->positionX = value;
}

void Texture::setPositionY(const int& value) {
	this->positionY = value;
}

void Texture::setWidth(const int* value) {
	delete this->width;
	this->width = nullptr;

	if (value != nullptr) {
		this->width = new int(*value);
	}
}

void Texture::setHeight(const int* value) {
	delete this->height;
	this->height = nullptr;

	if (value != nullptr) {
		this->height = new int(*value);
	}
}

void Texture::setAngle(const double& value) {
	this->angle = value;
}
