#ifndef BOMBE_H
#define BOMBE_H

#include "position.h"

class Bombe : public Position
{
public:
    Bombe();

    void decrementeShouldExploseIn();

    bool bombeShouldExplose();

private:
    int shouldExploseIn;
};

#endif // BOMBE_H
