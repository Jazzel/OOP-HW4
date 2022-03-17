#include "pigeon.hpp"
// pigeon implementation will go here.

void Pigeon::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Pigeon::fly()
{
    //
    switch (frame)
    {
    case 0:
        srcRect = {7, 88, 155, 103};
        frame = 1;
        break;
    case 1:
        srcRect = {0, 237, 153, 84};
        frame = 2;
        break;
    case 2:
        srcRect = {2, 361, 159, 124};
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
}

Pigeon::Pigeon()
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7, 88, 155, 103};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {30, 40, 50, 50};
}
