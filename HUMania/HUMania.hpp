// ? imports
#include <SDL.h>
#include <vector>
#include <list>

// ? header files
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
using namespace std;

/**
 * ? @brief HUMania
 * * parent class to hold the objects that will be displayed on the screen
 *
 * ? @attributes
 * * private: vectors of pigeons, butterflies & bees
 * * that are of data type pointers of Pigeon, Butterfly & Bee class.
 *
 * ? @functions
 * * drawObjects():
 * *    - Reads the vectors of pigeons, butterflies & bees
 * *    - and calls the draw the functions of the classes in respective vectors
 *
 * * createObject(int, int):
 * *    - Gets random integer with the help of 'generateRandomInteger()' helper
 * *    - swithes according to random int and creates Pigeon, Bee or Butterfly pointing object
 * *    - and pushes it into the respective vector
 * *    - Takes 2 parameters(int) which defines the x and y pixel of mouse click.
 *
 * * generateRandomInteger(int, int):
 * *    - Generates random int with a range.
 * *    - Takes 2 parameters(int) min and max to define the range.
 *
 */

class HUMania
{
private:
    vector<Pigeon *> pigeons;
    vector<Butterfly *> butterflies;
    vector<Bee *> bees;

public:
    void drawObjects();
    void createObject(int, int);
    int generateRandomInteger(int, int);

    ~HUMania();
};
