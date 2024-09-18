#pragma once

#include "Renderable.h"

class Rectangle :
    public Renderable
{
public:

    Rectangle(
        SDL_Renderer* renderer,
        const float& width,
        const float& height,
        const float& x,
        const float& y,
        const SDL_Color& color = { 0, 0, 0, 255 });
    ~Rectangle();

    virtual bool isCursorIn(
        const float& x,
        const float& y) override;
    virtual void init() override;
    virtual void render() override;
    virtual void destroy() override;

    SDL_Color getColor() const;
    float getPositionX() const;
    float getPositionY() const;
    float getWidth() const;
    float getHeight() const;

    void setColor(const SDL_Color& value);
    void setPositionX(const float& value);
    void setPositionY(const float& value);
    void setWidth(const float& value);
    void setHeight(const float& value);

private:

    SDL_Color color;
    float positionX;
    float positionY;
    float width;
    float height;
};

