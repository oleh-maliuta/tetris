#pragma once

#ifndef RENDERABLES_IMAGEBUTTON_H
#define RENDERABLES_IMAGEBUTTON_H

#include <string>
#include "Renderable.h"
#include "../Loader.h"

class ImageButton :
    public Renderable
{
public:

    ImageButton(
        SDL_Renderer* renderer,
        const std::string& imagePath,
        const int& x = 0,
        const int& y = 0,
        const SDL_Color& bodyColor = { 0, 0, 0, 255 },
        const int& paddingTop = 0,
        const int& paddingBottom = 0,
        const int& paddingLeft = 0,
        const int& paddingRight = 0,
        const int* width = nullptr,
        const int* height = nullptr,
        const SDL_Color& imageModuleColor = { 255, 255, 255, 255 });
    ~ImageButton();

    virtual bool isCursorIn(int x, int y) override;
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;

    int getPositionX() const;
    int getPositionY() const;
    int getImageWidth() const;
    int getImageHeight() const;
    int getWidth() const;
    int getHeight() const;

    void setPositionX(const int& value);
    void setPositionY(const int& value);
    void setImageWidth(const int* value);
    void setImageHeight(const int* value);

private:

    SDL_Texture* texture = nullptr;
    SDL_Color bodyColor;
    std::string imagePath;
    Uint8 moduleRed;
    Uint8 moduleGreen;
    Uint8 moduleBlue;
    int* imageWidth;
    int* imageHeight;
    int defaultImageWidth;
    int defaultImageHeight;
    int positionX;
    int positionY;
    int paddingTop;
    int paddingBottom;
    int paddingLeft;
    int paddingRight;
};

#endif
