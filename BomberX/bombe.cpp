#include "bombe.h"

Bombe::Bombe(int _bomberId, int offsetX, int offsetY)
{
    bomberId = _bomberId;
    shouldExploseIn = 3;
    setX(offsetX);
    setY(offsetY);
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
