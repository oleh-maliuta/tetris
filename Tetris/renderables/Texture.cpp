#include "Texture.h"

Texture::Texture(
	App* app,
	const std::string& path,
	const SDL_Rect* srcRectangle,
	const SDL_Rect* dstRectangle,
	const SDL_Point* rotationPoint,
	const SDL_RendererFlip& flip,
	const SDL_Color& moduleColor,
	const double& angle
) : Renderable(app) {
	this->filePath = path;
	this->srcRectangle = srcRectangle != nullptr ? new SDL_Rect(*srcRectangle) : nullptr;
	this->dstRectangle = dstRectangle != nullptr ? new SDL_Rect(*dstRectangle) : nullptr;
	this->rotationPoint = rotationPoint != nullptr ? new SDL_Point(*rotationPoint) : nullptr;
	this->flip = flip;
	this->moduleRed = moduleColor.r;
	this->moduleGreen = moduleColor.g;
	this->moduleBlue = moduleColor.b;
	this->angle = angle;
}

Texture::~Texture() {
	this->destroy();
	delete this->srcRectangle;
	delete this->dstRectangle;
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
	SDL_Renderer* renderer = this->app->getRenderer();

	this->sdlTexture = Loader::loadTextureFromImage(
		renderer,
		this->filePath.c_str());
}

void Texture::render() {
	if (!this->visibility) {
		return;
	}

	SDL_Renderer* renderer = this->app->getRenderer();

	SDL_RenderCopyEx(
		renderer,
		this->sdlTexture,
		this->srcRectangle,
		this->dstRectangle,
		this->angle,
		this->rotationPoint,
		this->flip);

	SDL_SetTextureColorMod(
		this->sdlTexture,
		this->moduleRed,
		this->moduleGreen,
		this->moduleBlue);
}

void Texture::destroy() {
	if (this->sdlTexture != nullptr) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = nullptr;
	}
}

SDL_Rect* Texture::getSrcRectangle() const {
	return this->srcRectangle != nullptr ? new SDL_Rect(*this->srcRectangle) : nullptr;
}

SDL_Rect* Texture::getDstRectangle() const {
	return this->dstRectangle != nullptr ? new SDL_Rect(*this->dstRectangle) : nullptr;
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
	if (this->dstRectangle != nullptr) {
		return dstRectangle->x;
	}

	if (this->srcRectangle != nullptr) {
		return srcRectangle->x;
	}

	return 0;
}

int Texture::getPositionY() const {
	if (this->dstRectangle != nullptr) {
		return dstRectangle->y;
	}

	if (this->srcRectangle != nullptr) {
		return srcRectangle->y;
	}

	return 0;
}

int Texture::getWidth() const {
	if (this->dstRectangle != nullptr) {
		return dstRectangle->w;
	}

	if (this->srcRectangle != nullptr) {
		return srcRectangle->w;
	}

	return this->app->getWindowWidth();
}

int Texture::getHeight() const {
	if (this->dstRectangle != nullptr) {
		return dstRectangle->h;
	}

	if (this->srcRectangle != nullptr) {
		return srcRectangle->h;
	}

	return this->app->getWindowHeight();
}

void Texture::setSrcRectangle(const SDL_Rect* value) {
	if (this->srcRectangle != nullptr) {
		delete this->srcRectangle;
	}

	if (value != nullptr) {
		this->srcRectangle = new SDL_Rect(*value);
	}
	else {
		this->srcRectangle = nullptr;
	}
}

void Texture::setDstRectangle(const SDL_Rect* value) {
	if (this->dstRectangle != nullptr) {
		delete this->dstRectangle;
	}

	if (value != nullptr) {
		this->dstRectangle = new SDL_Rect(*value);
	}
	else {
		this->dstRectangle = nullptr;
	}
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

void Texture::setAngle(const double& value) {
	this->angle = value;
}
