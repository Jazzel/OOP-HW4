#include "butterfly.hpp"
#include "drawing.hpp"
#include <string>

void Butterfly::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Butterfly::fly()
{
    //
    switch (frame)
    {
    case 0:
        srcRect = {257, 24, 173, 134};
        frame = 1;
        break;
    case 1:
        srcRect = {257, 182, 192, 214};
        frame = 2;
        break;
    case 2:
        srcRect = {248, 433, 247, 178};
        frame = 0;
        break;
    default:
        frame = 0;
        break;
    }
    moverRect.x += 20;
    if (moverRect.x >= 1000)
    {
        moverRect.x = -50;
    }

    if (down)
    {
        moverRect.y += 20;
        if (moverRect.y > 500)
        {
            down = false;
        }
    }
    else
    {
        moverRect.y -= 20;
        if (moverRect.y < 0)
        {
            down = true;
        }
    }
}

Butterfly::Butterfly()
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {256, 24, 173, 134};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {40, 50, 50, 50};
}
