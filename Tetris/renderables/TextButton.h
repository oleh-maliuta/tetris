#pragma once

#ifndef RENDERABLES_TEXTBUTTON_H
#define RENDERABLES_TEXTBUTTON_H

#include <string>
#include "../Loader.h"
#include "Renderable.h"

namespace Tetris
{
    class TextButton :
        public Renderable
    {
    public:

        TextButton(
            SDL_Renderer* renderer,
            const std::string& fontPath,
            const std::string& content,
            const int& fontSize = 15,
            const float& width = 0,
            const float& height = 0,
            const float& x = 0,
            const float& y = 0,
            const SDL_Color& bodyColor = { 0, 0, 0, 255 },
            const SDL_Color& fontColor = { 0, 0, 0, 255 },
            const float& paddingLeft = 0,
            const float& paddingRight = 0);
        ~TextButton();

        virtual bool isCursorIn(
            const float& x,
            const float& y) override;
        virtual void init() override;
        virtual void render() override;
        virtual void destroy() override;

        SDL_Color getBodyColor() const;
        SDL_Color getFontColor() const;
        std::string getContent() const;
        std::string getFontPath() const;
        int getFontSize() const;
        float getPositionX() const;
        float getPositionY() const;
        float getBodyWidth() const;
        float getBodyHeight() const;
        float getTextWidth() const;
        float getTextHeight() const;
        float getPaddingLeft() const;
        float getPaddingRight() const;

        void setBodyColor(const SDL_Color& value);
        void setFontColor(const SDL_Color& value);
        void setContent(const std::string& value);
        void setFontPath(const std::string& value);
        void setFontSize(const int& value);
        void setPositionX(const float& value);
        void setPositionY(const float& value);
        void setBodyWidth(const float& value);
        void setBodyHeight(const float& value);
        void setPaddingLeft(const float& value);
        void setPaddingRight(const float& value);

    private:

        SDL_Texture* textTexture = nullptr;
        TTF_Font* font = nullptr;
        SDL_Color bodyColor;
        SDL_Color fontColor;
        std::string content;
        std::string fontPath;
        int fontSize;
        float positionX;
        float positionY;
        float bodyWidth;
        float bodyHeight;
        float textWidth = 0;
        float textHeight = 0;
        float paddingLeft;
        float paddingRight;
    };
}

#endif
