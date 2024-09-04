#pragma once

#ifndef RENDERABLES_TEXT_H
#define RENDERABLES_TEXT_H

#include <string>
#include "../Loader.h"
#include "Renderable.h"

class Text :
    public Renderable
{
public:

    Text(
        App* app,
        const std::string& fontPath,
        const std::string& content,
        const int& fontSize = 15,
        const Uint32* wrapLength = nullptr,
        const int& x = 0,
        const int& y = 0,
        const SDL_Color& fontColor = { 0, 0, 0, 255 },
        const SDL_RendererFlip& flip = SDL_FLIP_NONE,
        const SDL_Point* rotationPoint = nullptr,
        const double& angle = 0);
    ~Text();

    virtual bool isCursorIn(int x, int y) override;
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;

    SDL_Point* getRotationPoint() const;
    Uint32* getWrapLength() const;
    SDL_Color getFontColor() const;
    SDL_RendererFlip getFlip() const;
    std::string getContent() const;
    std::string getFontPath() const;
    double getAngle() const;
    int getFontSize() const;
    int getPositionX() const;
    int getPositionY() const;
    int getWidth() const;
    int getHeight() const;

    void setRotationPoint(const SDL_Point* value);
    void setWrapLength(const Uint32* value);
    void setFontColor(const SDL_Color& value);
    void setFlip(const SDL_RendererFlip& value);
    void setContent(const std::string& value);
    void setFontPath(const std::string& value);
    void setAngle(const double& value);
    void setFontSize(const int& value);
    void setPositionX(const int& value);
    void setPositionY(const int& value);
    void setPosition(const int& x, const int& y);

private:

    SDL_Texture* texture = nullptr;
    TTF_Font* font = nullptr;
    SDL_Point* rotationPoint;
    Uint32* wrapLength;
    SDL_Color fontColor;
    SDL_RendererFlip flip;
    std::string content;
    std::string fontPath;
    double angle;
    int fontSize;
    int positionX;
    int positionY;
    int width = 0;
    int height = 0;
};

#endif
