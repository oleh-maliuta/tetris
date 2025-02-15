#pragma once

#ifndef TETRIS__RENDERABLES__LAYOUT__H
#define TETRIS__RENDERABLES__LAYOUT__H

#include <string>
#include <list>
#include <utility>
#include "Renderable.h"
#include "../Loader.h"

namespace Tetris
{
    class Layout :
        public Renderable
    {
    public:

        std::list<std::pair<std::string, Renderable*>> objects;

        Layout(
            SDL_Renderer* renderer,
            const float& width,
            const float& height,
            const float& x,
            const float& y,
            const SDL_Color& backgroundColor = { 0, 0, 0, 255 },
            const std::list<std::pair<std::string, Renderable*>> objects = {});
        ~Layout();

        virtual bool isCursorIn(
            const float& x,
            const float& y) override;
        virtual void init() override;
        virtual void render() override;
        virtual void destroy() override;

        template<class T>
        T* getObject(
            const std::string& key);

        SDL_Color getBackgroundColor() const;
        float getPositionX() const;
        float getPositionY() const;
        float getWidth() const;
        float getHeight() const;

        void setBackgroundColor(const SDL_Color& value);
        void setPositionX(const float& value);
        void setPositionY(const float& value);
        void setWidth(const float& value);
        void setHeight(const float& value);

    private:

        SDL_Color backgroundColor;
        float positionX;
        float positionY;
        float width;
        float height;
    };

    template<class T>
    T* Layout::getObject(
        const std::string& key)
    {
        if (!std::is_base_of<Renderable, T>::value) {
            return nullptr;
        }

        for (const auto& el : this->objects) {
            if (el.first == key) {
                return dynamic_cast<T*>(el.second);
            }
        }

        return nullptr;
    }
}

#endif
