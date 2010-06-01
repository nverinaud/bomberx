#include "bombe.h"

Bombe::Bombe(int _bomberId, int _offsetX, int _offsetY)
{
    bomberId = _bomberId;
    shouldExploseIn = 30;
    offsetX = _offsetX;
    offsetY = _offsetY;
    setX(_offsetX/50);
    setY((_offsetY+20)/50);
    power = 1;
}

void Bombe::decrementeShouldExploseIn()
{
    if(shouldExploseIn > 0)
        shouldExploseIn--;
}

bool Bombe::bombeShouldExplose()
{
    if(shouldExploseIn == 0)
        return true;
    else
        return false;
}

int Bombe::getBomberId()
{
    return bomberId;
}

int Bombe::getOffsetX()
{
    return offsetX;
}

int Bombe::getOffsetY()
{
    return offsetY;
}

int Bombe::getPower()
{
    return power;
}
