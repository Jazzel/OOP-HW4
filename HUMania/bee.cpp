// ? header files
#include "bee.hpp"

// ! *******************************************************
// !         CLASS DEFINITION IN THE HEADER FILE
// ! *******************************************************

/**
 * ? @brief draw()
 * * draws the Bee with SDL params, srcRect and moveRect co-ordinates
 * * calls the fly() function to enable the animations
 *
 */
void Bee::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    fly();
}

/**
 * ? @brief deleteBee()
 * * returns true if the bee has crossed the screen
 *
 * ? @return type bool
 */
bool Bee::deleteBee()
{
    if (moverRect.x > 1000)
    {
        return true;
    }
    return false;
}

/**
 * ? @brief fly()
 * * switches the srcRect with the help of frame variable
 * * moves the Bee to the right with the help of moverRect.x
 * * resets the Bee back to left when it touches the right corner.
 *
 */
void Bee::fly()
{
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
    if (!hover())
    {
        Bee::hold = -1;
        moverRect.x += 20;
    }
    else
    {
        Bee::hold -= 1;
    }
}

/**
 * ? brief generateRandomInteger
 * * gives random number according to range given
 *
 * ? @param min
 * * int - the lowest number possible
 * ? @param max
 * * int - the highest number possible
 *
 * ! @return int
 * * random int
 */
int Bee::generateRandomInt(int min, int max)
{
    int range = max - min + 1;
    return rand() % range + min;
}

/**
 * ? @brief hover()
 * * generates the 1% probability with the help of "generateRandomInt" helper
 * * assigns 10 to hold if the probability is 1
 * * returns true if the hold is not 0 or -1.
 *
 * ? @return type bool
 */
bool Bee::hover()
{
    int random = generateRandomInt(1, 100);
    if (random == 1)
    {
        hold = 10;
    }
    return Bee::hold <= 0 ? false : true;
}

/**
 * ? @brief Construct a new Bee:: Bee object
 * * default constructor
 *
 */
Bee::Bee()
{
    srcRect = {63, 619, 151, 166};
    moverRect = {50, 60, 50, 50};
}

/**
 * ? @brief Construct a new Bee:: Bee object
 * * constructor with x any y co-ordinates
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 */
Bee::Bee(int x, int y)
{
    srcRect = {63, 619, 151, 166};
    moverRect = {x, y, 50, 50};
}
