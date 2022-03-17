#include "bee.hpp"

void Bee::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Bee::fly()
{
    //
    switch (frame)
    {
    case 0:
        srcRect = {63, 619, 151, 166};
        frame = 1;
        break;
    case 1:
        srcRect = {234, 630, 163, 162};
        frame = 2;
        break;
    case 2:
        srcRect = {409, 650, 171, 147};
        frame = 0;
        break;
    default:
        frame = 0;
        break;
    }
    if (hold) {
        
    }
    moverRect.x += 20;
}

Bee::Bee()
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {63, 619, 151, 166};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {50, 60, 50, 50};
}
