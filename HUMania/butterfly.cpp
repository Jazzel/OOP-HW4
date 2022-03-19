// ? imports
#include <string>

// ? header files
#include "butterfly.hpp"
#include "drawing.hpp"

// ! *******************************************************
// !         CLASS DEFINITION IN THE HEADER FILE
// ! *******************************************************

/**
 * ? @brief draw()
 * * draws the Butterfly with SDL params, srcRect and moveRect co-ordinates
 * * calls the fly() function to enable the animations
 *
 */
void Butterfly::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    fly();
}

/**
 * ? @brief fly()
 * * switches the srcRect with the help of frame variable
 * * moves the Butterfly to the right with the help of moverRect.x
 * * if the down is true
 * *     - moves the Butterfly to the downward with the help of moverRect.x
 * *     - else moves the Butterfly to the upward with the help of moverRect.x
 * * resets the Butterfly back to left when it touches the right corner.
 * *
 *
 */
void Butterfly::fly()
{
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

/**
 * ? @brief Construct a new Butterfly:: Butterfly object
 * * default constructor
 *
 */
Butterfly::Butterfly()
{
    srcRect = {256, 24, 173, 134};
    moverRect = {40, 50, 50, 50};
}

/**
 * ? @brief Construct a new Butterfly:: Butterfly object
 * * constructor with x any y co-ordinates
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 */
Butterfly::Butterfly(int x, int y)
{
    srcRect = {256, 24, 173, 134};
    moverRect = {x, y, 50, 50};
}
