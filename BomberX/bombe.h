#ifndef BOMBE_H
#define BOMBE_H

#include "position.h"

class Bombe : public Position
{
public:
    Bombe(int, int, int);

    int getBomberId();

    void decrementeShouldExploseIn();

    bool bombeShouldExplose();

private:
    int shouldExploseIn;
    int bomberId;
};

#endif // BOMBE_H
