#pragma once

#ifndef RENDERABLES_TEXTBUTTON_H
#define RENDERABLES_TEXTBUTTON_H

#include <string>
#include "../Loader.h"
#include "Renderable.h"

class TextButton :
    public Renderable
{
public:

    TextButton(
        App* app,
        const std::string& fontPath,
        const std::string& content,
        const int& fontSize = 15,
        const int& width = 0,
        const int& height = 0,
        const int& x = 0,
        const int& y = 0,
        const SDL_Color& bodyColor = { 0, 0, 0, 255 },
        const SDL_Color& fontColor = { 0, 0, 0, 255 },
        const int& paddingLeft = 0,
        const int& paddingRight = 0);
    ~TextButton();

    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;

private:

    SDL_Texture* textTexture = nullptr;
    TTF_Font* font = nullptr;
    SDL_Color bodyColor;
    SDL_Color fontColor;
    std::string content;
    std::string fontPath;
    int fontSize;
    int positionX;
    int positionY;
    int bodyWidth;
    int bodyHeight;
    int textWidth = 0;
    int textHeight = 0;
    int paddingLeft;
    int paddingRight;
};

#endif
