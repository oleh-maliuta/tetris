#pragma once

#ifndef RENDERABLES_IMAGEBUTTON_H
#define RENDERABLES_IMAGEBUTTON_H

#include <string>
#include "Renderable.h"
#include "../Loader.h"

namespace Tetris
{
    class ImageButton :
        public Renderable
    {
    public:

        ImageButton(
            SDL_Renderer* renderer,
            const std::string& imagePath,
            const float& x = 0,
            const float& y = 0,
            const SDL_Color& bodyColor = { 0, 0, 0, 255 },
            const float& paddingTop = 0,
            const float& paddingBottom = 0,
            const float& paddingLeft = 0,
            const float& paddingRight = 0,
            const float* width = nullptr,
            const float* height = nullptr,
            const SDL_Color& imageModuleColor = { 255, 255, 255, 255 });
        ~ImageButton();

        virtual bool isCursorIn(
            const float& x,
            const float& y) override;
        virtual void init() override;
        virtual void render() override;
        virtual void destroy() override;

        SDL_Color getBodyColor() const;
        float getPositionX() const;
        float getPositionY() const;
        float getImageWidth() const;
        float getImageHeight() const;
        float getWidth() const;
        float getHeight() const;

        void setBodyColor(const SDL_Color& value);
        void setPositionX(const float& value);
        void setPositionY(const float& value);
        void setImageWidth(const float* value);
        void setImageHeight(const float* value);

    private:

        SDL_Texture* texture = nullptr;
        SDL_Color bodyColor;
        std::string imagePath;
        Uint8 moduleRed;
        Uint8 moduleGreen;
        Uint8 moduleBlue;
        float* imageWidth;
        float* imageHeight;
        float defaultImageWidth;
        float defaultImageHeight;
        float positionX;
        float positionY;
        float paddingTop;
        float paddingBottom;
        float paddingLeft;
        float paddingRight;
    };
}

#endif
