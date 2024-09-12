#include "ImageButton.h"

ImageButton::ImageButton(
	App* app,
	const std::string& imagePath,
	const int& x,
	const int& y,
	const SDL_Color& bodyColor,
	const int& paddingTop,
	const int& paddingBottom,
	const int& paddingLeft,
	const int& paddingRight,
	const int* width,
	const int* height,
	const SDL_Color& imageModuleColor)
	: Renderable(app) {
	this->imagePath = imagePath;
	this->positionX = x;
	this->positionY = y;
	this->bodyColor = bodyColor;
	this->paddingTop = paddingTop;
	this->paddingBottom = paddingBottom;
	this->paddingLeft = paddingLeft;
	this->paddingRight = paddingRight;
	this->imageWidth = width != nullptr ? new int(*width) : nullptr;
	this->imageHeight = height != nullptr ? new int(*height) : nullptr;
	this->moduleRed = imageModuleColor.r;
	this->moduleGreen = imageModuleColor.g;
	this->moduleBlue = imageModuleColor.b;

	Loader::getImageSize(imagePath.c_str(), &this->defaultImageWidth, &this->defaultImageHeight);
}

ImageButton::~ImageButton() {
	this->destroy();
	delete this->imageWidth;
	delete this->imageHeight;
}

bool ImageButton::isCursorIn(int x, int y) {
	int posX = this->getPositionX();
	int posY = this->getPositionY();

	return
		x >= posX && x < posX + this->getWidth() &&
		y >= posY && y < posY + this->getHeight();
}

void ImageButton::init() {
	SDL_Renderer* renderer = this->app->getRenderer();

	this->texture = Loader::getTextureFromImage(
		renderer,
		this->imagePath.c_str());

	Renderable::init();
}

void ImageButton::render() {
	if (!this->visibility || !this->isInitialized) {
		return;
	}

	int bodyWidth = this->getWidth();
	int bodyHeight = this->getHeight();
	int imageWidth = this->getImageWidth();
	int imageHeight = this->getImageHeight();
	SDL_Renderer* renderer = this->app->getRenderer();
	SDL_Rect body = { this->positionX, this->positionY, bodyWidth, bodyHeight };
	SDL_Rect imageRectangle = {
		bodyWidth / 2 - imageWidth / 2,
		bodyHeight / 2 - imageHeight / 2,
		imageWidth,
		imageHeight
	};

	SDL_SetRenderDrawColor(renderer, this->bodyColor.r, this->bodyColor.g, this->bodyColor.b, this->bodyColor.a);
	SDL_RenderSetViewport(renderer, &body);
	SDL_RenderFillRect(renderer, nullptr);
	SDL_RenderCopy(renderer, this->texture, nullptr, &imageRectangle);
	SDL_SetTextureColorMod(this->texture, this->moduleRed, this->moduleGreen, this->moduleBlue);
	SDL_RenderSetViewport(renderer, nullptr);

	Renderable::render();
}

void ImageButton::destroy() {
	Renderable::destroy();
}

int ImageButton::getPositionX() const {
	return this->positionX;
}

int ImageButton::getPositionY() const {
	return this->positionY;
}

int ImageButton::getImageWidth() const {
	return this->imageWidth != nullptr ? *this->imageWidth : this->defaultImageWidth;
}

int ImageButton::getImageHeight() const {
	return this->imageHeight != nullptr ? *this->imageHeight : this->defaultImageHeight;
}

int ImageButton::getWidth() const {
	return (this->imageWidth != nullptr ? *this->imageWidth : this->defaultImageWidth) + this->paddingLeft + this->paddingRight;
}

int ImageButton::getHeight() const {
	return (this->imageHeight != nullptr ? *this->imageHeight : this->defaultImageHeight) + this->paddingTop + this->paddingBottom;
}

void ImageButton::setPositionX(const int& value) {
	this->positionX = value;
}

void ImageButton::setPositionY(const int& value) {
	this->positionY = value;
}

void ImageButton::setImageWidth(const int* value) {
	delete this->imageWidth;
	this->imageWidth = nullptr;

	if (value != nullptr) {
		this->imageWidth = new int(*value);
	}
}

void ImageButton::setImageHeight(const int* value) {
	delete this->imageHeight;
	this->imageHeight = nullptr;

	if (value != nullptr) {
		this->imageHeight = new int(*value);
	}
}
