#pragma once

#ifndef RENDERABLES_TEXTURE_H
#define RENDERABLES_TEXTURE_H

#include <string>
#include "Renderable.h"
#include "../Loader.h"

class Texture :
    public Renderable
{
private:
    std::string filePath;
    SDL_Texture* sdlTexture = nullptr;
public:
    SDL_Rect* dstrect = nullptr;
    SDL_Rect* srcrect = nullptr;
    SDL_Point* rotationPoint = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    Uint8 moduleRed = 255;
    Uint8 moduleGreen = 255;
    Uint8 moduleBlue = 255;
    double angle = 0;
    Texture(
        App* app,
        std::string path);
    ~Texture();
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;
};

#endif
