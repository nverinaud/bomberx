#ifndef BOMBE_H
#define BOMBE_H

#include "position.h"

class Bombe : public Position
{
public:
    Bombe(int, int, int);

    int getBomberId();
    int getOffsetX();
    int getOffsetY();
    int getPower();

    void decrementeShouldExploseIn();

    bool bombeShouldExplose();

private:
    int shouldExploseIn;
    int offsetX;
    int offsetY;
    int bomberId;
    int power;
};

#endif // BOMBE_H
