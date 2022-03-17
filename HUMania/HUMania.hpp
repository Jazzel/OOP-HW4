#include <SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include <vector>
#include <list>
using namespace std;

class HUMania
{

    // Right now we're creating one pigeon,
    Pigeon p1;
    Butterfly b1;
    Bee bu1;

    // In the solution you have to create vectors of pigeons, eggs, and nests
    vector<Pigeon *> pigeons;
    vector<Butterfly *> butterflies;
    vector<Bee *> bees;

public:
    void drawObjects();
    void createObject(int, int);
};