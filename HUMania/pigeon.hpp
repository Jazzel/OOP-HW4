// ? imports
#include <SDL.h>

// ? header files
#include "drawing.hpp"

/**
 * ? @brief Pigeon
 * * handles the Butterfly object and it's functions

 * ? @attributes
 * * SDL_Rect struct type of srcRect & moverRect
 * *     - SDL_Rect stores int values x, y, w & h
 * * frame int type
 **      - used to switch srcRect to animate the movement of object
 *
 * ? @functions
 * * draw()
 * *     - draws the object Pigeon with moverRect, srcRect and SDL parameters
 * *     - calls fly() to trigger animation
 *
 * * fly()
 * *     - animates the object Pigeon
 * *     - moves the Pigeon to the right of the screen
 * *     - and if it touches the right corner, resets it to the left corner
 * *     - switches the 3 srcRects continuosly to make the Pigeon flying real
 *
 *
 * ? @constructors
 * * Default
 * * with parameters (int, int)
 * *     - takes 2 params x and y and assign it to x and y of moverRect
 * *     - which makes the Pigeon object appear where the mouse click triggered.
 *
 */
class Pigeon
{
    SDL_Rect srcRect, moverRect;
    int frame = 0;

public:
    void draw();
    void fly();

    Pigeon();
    Pigeon(int, int);
};
