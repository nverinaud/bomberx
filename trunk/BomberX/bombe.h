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

    void decrementeShouldExploseIn();

    bool bombeShouldExplose();

private:
    int shouldExploseIn;
    int offsetX;
    int offsetY;
    int bomberId;
};

#endif // BOMBE_H
