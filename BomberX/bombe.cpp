#include "bombe.h"

Bombe::Bombe(int _bomberId, int _offsetX, int _offsetY)
{
    bomberId = _bomberId;
    shouldExploseIn = 30;
    offsetX = _offsetX;
    offsetY = _offsetY;
    setX(_offsetX/SPEED);
    setY((_offsetY+20)/SPEED);
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
