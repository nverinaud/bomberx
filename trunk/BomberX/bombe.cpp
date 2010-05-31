#include "bombe.h"

Bombe::Bombe()
{
    shouldExploseIn = 3;
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
