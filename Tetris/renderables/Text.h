#pragma once

#ifndef RENDERABLES_TEXT_H
#define RENDERABLES_TEXT_H

#include <string>
#include "../Loader.h"
#include "Renderable.h"

namespace Tetris
{
    class Text :
        public Renderable
    {
    public:

        Text(
            SDL_Renderer* renderer,
            const std::string& fontPath,
            const std::string& content,
            const int& fontSize = 15,
            const Uint32* wrapLength = nullptr,
            const float& x = 0,
            const float& y = 0,
            const SDL_Color& fontColor = { 0, 0, 0, 255 },
            const SDL_RendererFlip& flip = SDL_FLIP_NONE,
            const SDL_FPoint* rotationPoint = nullptr,
            const double& angle = 0);
        ~Text();

        virtual bool isCursorIn(
            const float& x,
            const float& y) override;
        virtual void init() override;
        virtual void render() override;
        virtual void destroy() override;

        SDL_FPoint* getRotationPoint() const;
        Uint32* getWrapLength() const;
        SDL_Color getFontColor() const;
        SDL_RendererFlip getFlip() const;
        std::string getContent() const;
        std::string getFontPath() const;
        double getAngle() const;
        float getPositionX() const;
        float getPositionY() const;
        float getWidth() const;
        float getHeight() const;
        int getFontSize() const;

        void setRotationPoint(const SDL_FPoint* value);
        void setWrapLength(const Uint32* value);
        void setFontColor(const SDL_Color& value);
        void setFlip(const SDL_RendererFlip& value);
        void setContent(const std::string& value);
        void setFontPath(const std::string& value);
        void setAngle(const double& value);
        void setPositionX(const float& value);
        void setPositionY(const float& value);
        void setFontSize(const int& value);

    private:

        SDL_Texture* texture = nullptr;
        TTF_Font* font = nullptr;
        SDL_FPoint* rotationPoint;
        Uint32* wrapLength;
        SDL_Color fontColor;
        SDL_RendererFlip flip;
        std::string content;
        std::string fontPath;
        double angle;
        float positionX;
        float positionY;
        float width;
        float height;
        int fontSize;
    };
}

#endif
