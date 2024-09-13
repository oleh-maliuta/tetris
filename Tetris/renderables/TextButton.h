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
        SDL_Renderer* renderer,
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

    virtual bool isCursorIn(int x, int y) override;
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;

    SDL_Color getBodyColor() const;
    SDL_Color getFontColor() const;
    std::string getContent() const;
    std::string getFontPath() const;
    int getFontSize() const;
    int getPositionX() const;
    int getPositionY() const;
    int getBodyWidth() const;
    int getBodyHeight() const;
    int getTextWidth() const;
    int getTextHeight() const;
    int getPaddingLeft() const;
    int getPaddingRight() const;

    void setBodyColor(const SDL_Color& value);
    void setFontColor(const SDL_Color& value);
    void setContent(const std::string& value);
    void setFontPath(const std::string& value);
    void setFontSize(const int& value);
    void setPositionX(const int& value);
    void setPositionY(const int& value);
    void setBodyWidth(const int& value);
    void setBodyHeight(const int& value);
    void setPaddingLeft(const int& value);
    void setPaddingRight(const int& value);

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
