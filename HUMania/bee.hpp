#include <SDL.h>
#include "drawing.hpp"
class Bee
{

    SDL_Rect srcRect, moverRect;
    int frame = 0;
    int hold = 0;

public:
    // add the fly function here as well.
    void draw();
    void fly();
    Bee();
    // may add other overloaded constructors here...
};
