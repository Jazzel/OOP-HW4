#include <iostream>
#include "HUMania.hpp"

void HUMania::drawObjects()
{
    // call draw functions of all the objects here
    p1.draw();
    p1.fly();
    b1.draw();
    b1.fly();
    bu1.draw();
    bu1.fly();
}

void HUMania::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}
