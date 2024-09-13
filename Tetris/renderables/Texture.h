#pragma once

#ifndef RENDERABLES_TEXTURE_H
#define RENDERABLES_TEXTURE_H

#include <string>
#include "Renderable.h"
#include "../Loader.h"

class Texture :
    public Renderable
{
public:

    Texture(
        SDL_Renderer* renderer,
        const std::string& path,
        const int& x = 0,
        const int& y = 0,
        const int* width = nullptr,
        const int* height = nullptr,
        const SDL_Point* rotationPoint = nullptr,
        const SDL_RendererFlip& flip = SDL_FLIP_NONE,
        const SDL_Color& moduleColor = { 255, 255, 255 },
        const double& angle = 0);
    ~Texture();

    virtual bool isCursorIn(int x, int y) override;
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;

    SDL_Point* getRotationPoint() const;
    SDL_RendererFlip getFlip() const;
    SDL_Color getModuleColor() const;
    std::string getFilePath() const;
    Uint8 getModuleRed() const;
    Uint8 getModuleGreen() const;
    Uint8 getModuleBlue() const;
    double getAngle() const;
    int getPositionX() const;
    int getPositionY() const;
    int getWidth() const;
    int getHeight() const;

    void setRotationPoint(const SDL_Point* value);
    void setFilePath(const std::string& value);
    void setModuleRed(const Uint8& value);
    void setModuleGreen(const Uint8& value);
    void setModuleBlue(const Uint8& value);
    void setModuleColor(const SDL_Color& color);
    void setPositionX(const int& value);
    void setPositionY(const int& value);
    void setWidth(const int* value);
    void setHeight(const int* value);
    void setAngle(const double& value);

private:

    SDL_Texture* sdlTexture = nullptr;
    SDL_Point* rotationPoint;
    SDL_RendererFlip flip;
    std::string filePath;
    Uint8 moduleRed;
    Uint8 moduleGreen;
    Uint8 moduleBlue;
    int* width;
    int* height;
    int defaultWidth;
    int defaultHeight;
    int positionX;
    int positionY;
    double angle;
};

#endif
