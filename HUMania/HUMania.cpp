// ? imports
#include <iostream>

// ? header files
#include "HUMania.hpp"

// ! *******************************************************
// !         CLASS DEFINITION IN THE HEADER FILE
// ! *******************************************************

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
int HUMania::generateRandomInteger(int min, int max)
{
    int range = max - min + 1;
    return rand() % range + min;
}

/**
 * ? @brief drawObjects()
 * * loops the 3 vectors of pigeons, butterflies and bees
 * * and call very looped variable's draw function.
 *
 * * also when bee has passed the screen it deletes the pointing object
 * * and pops it from the vector with the help of "deleteBee" helper from the class
 *
 */
void HUMania::drawObjects()
{
    for (int i = 0; i < pigeons.size(); i++)
    {
        pigeons[i]->draw();
    }
    for (int i = 0; i < butterflies.size(); i++)
    {
        butterflies[i]->draw();
    }
    for (int i = 0; i < bees.size(); i++)
    {
        bees[i]->draw();
        bool check = bees[i]->deleteBee();
        if (check)
        {
            delete bees[i];
            bees.erase(bees.begin() + i);
        }
    }
}

/**
 * ? @brief createObject()
 * * takes x and y pixels of screen and creates objects on the screen
 * * objects here are pigeon, butterfly and bee
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 */
void HUMania::createObject(int x, int y)
{

    int randomInteger = generateRandomInteger(1, 3);
    switch (randomInteger)
    {
    case 1:
    {
        Pigeon *p = new Pigeon(x, y);
        pigeons.push_back(p);
        break;
    }
    case 2:
    {
        Bee *b = new Bee(x, y);
        bees.push_back(b);
        break;
    }
    case 3:
    {
        Butterfly *bt = new Butterfly(x, y);
        butterflies.push_back(bt);
        break;
    }
    };

    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

/**
 * ? @brief Destroy the HUMania::HUMania object
 * * emptys the pigeons, butterflies and bees vector
 * * and deletes the pointing objects of classes in it
 */
HUMania::~HUMania()
{
    while (!pigeons.empty())
    {
        delete pigeons[0];
        pigeons.pop_back();
    }
    while (!butterflies.empty())
    {
        delete butterflies[0];
        butterflies.pop_back();
    }
    while (!bees.empty())
    {
        delete bees[0];
        bees.pop_back();
    }
}
