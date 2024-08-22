#pragma once

#ifndef RENDERABLES_TEXT_H
#define RENDERABLES_TEXT_H

#include <string>
#include "../Loader.h"
#include "Renderable.h"

class Text :
    public Renderable
{
private:
    std::string content;
    std::string fontPath;
    SDL_Color fontColor = { 0, 0, 0 };
    int fontSize = 15;
    Uint32 wrapLength = 0;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    TTF_Font* font = nullptr;
    SDL_Texture* texture = nullptr;
public:
    SDL_Point* rotationPoint = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    Uint8 moduleRed = 255;
    Uint8 moduleGreen = 255;
    Uint8 moduleBlue = 255;
    double angle = 0;
    Text(
        App* app,
        std::string fontPath,
        std::string content,
        SDL_Color fontColor,
        int fontSize,
        Uint32 wrapLength);
    ~Text();
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;
};

#endif
