// ? header files
#include "pigeon.hpp"

// ! *******************************************************
// !         CLASS DEFINITION IN THE HEADER FILE
// ! *******************************************************

/**
 * ? @brief draw()
 * * draws the Pigeon with SDL params, srcRect and moveRect co-ordinates
 * * calls the fly() function to enable the animations
 *
 */
void Pigeon::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    fly();
}

/**
 * ? @brief fly()
 * * switches the srcRect with the help of frame variable
 * * moves the pigeon to the right with the help of moverRect.x
 * * resets the pigeon back to left when it touches the right corner.
 *
 */
void Pigeon::fly()
{
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

/**
 * ? @brief Construct a new Pigeon:: Pigeon object
 * * default constructor
 *
 */
Pigeon::Pigeon()
{
    srcRect = {7, 88, 155, 103};
    moverRect = {30, 40, 50, 50};
}

/**
 * ? @brief Construct a new Pigeon:: Pigeon object
 * * constructor with x any y co-ordinates
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 */
Pigeon::Pigeon(int x, int y)
{
    srcRect = {7, 88, 155, 103};
    moverRect = {x, y, 50, 50};
}
