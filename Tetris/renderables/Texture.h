#pragma once

#ifndef RENDERABLES_TEXTURE_H
#define RENDERABLES_TEXTURE_H

#include <string>
#include "Renderable.h"
#include "../Loader.h"

namespace Tetris
{
    class Texture :
        public Renderable
    {
    public:

        Texture(
            SDL_Renderer* renderer,
            const std::string& path,
            const float& x = 0,
            const float& y = 0,
            const float* width = nullptr,
            const float* height = nullptr,
            const SDL_FPoint* rotationPoint = nullptr,
            const SDL_RendererFlip& flip = SDL_FLIP_NONE,
            const SDL_Color& moduleColor = { 255, 255, 255 },
            const double& angle = 0);
        ~Texture();

        virtual bool isCursorIn(
            const float& x,
            const float& y) override;
        virtual void init() override;
        virtual void render() override;
        virtual void destroy() override;

        SDL_FPoint* getRotationPoint() const;
        SDL_RendererFlip getFlip() const;
        SDL_Color getModuleColor() const;
        std::string getFilePath() const;
        Uint8 getModuleRed() const;
        Uint8 getModuleGreen() const;
        Uint8 getModuleBlue() const;
        double getAngle() const;
        float getPositionX() const;
        float getPositionY() const;
        float getWidth() const;
        float getHeight() const;

        void setRotationPoint(const SDL_FPoint* value);
        void setFilePath(const std::string& value);
        void setModuleColor(const SDL_Color& color);
        void setModuleRed(const Uint8& value);
        void setModuleGreen(const Uint8& value);
        void setModuleBlue(const Uint8& value);
        void setAngle(const double& value);
        void setPositionX(const float& value);
        void setPositionY(const float& value);
        void setWidth(const float* value);
        void setHeight(const float* value);

    private:

        SDL_Texture* sdlTexture = nullptr;
        SDL_FPoint* rotationPoint;
        SDL_RendererFlip flip;
        std::string filePath;
        Uint8 moduleRed;
        Uint8 moduleGreen;
        Uint8 moduleBlue;
        double angle;
        float* width;
        float* height;
        float defaultWidth;
        float defaultHeight;
        float positionX;
        float positionY;
    };
}

#endif
