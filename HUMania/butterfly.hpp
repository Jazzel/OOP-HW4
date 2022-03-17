#include <SDL.h>
#include "drawing.hpp"
#include <string>

using namespace std;
class Butterfly
{

    SDL_Rect srcRect, moverRect;
    int frame = 0;
    bool down = true;

public:
    // add the fly function here as well.
    void draw();
    void fly();
    Butterfly();
    // may add other overloaded constructors here...
};
