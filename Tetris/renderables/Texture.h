#pragma once

#ifndef RENDERABLES_TEXTURE_H
#define RENDERABLES_TEXTURE_H

#include <cstring>
#include <string>
#include "Renderable.h"
#include "../Loader.h"

class Texture :
    public Renderable
{
private:
    const char* filePath;
    SDL_Texture* sdlTexture = nullptr;
    SDL_Rect* dstrect = nullptr;
    SDL_Rect* srcrect = nullptr;
public:
    Uint8 moduleRed = 255;
    Uint8 moduleGreen = 255;
    Uint8 moduleBlue = 255;
    Texture(App*, const char*, SDL_Rect*, SDL_Rect*);
    ~Texture();
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;
};

#endif
