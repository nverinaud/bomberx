#include "position.h"

Position::Position()
{
}

int Position::getX()
{
    return x;
}

int Position::getY()
{
    return y;
}

void Position::setX(int _x)
{
    if(_x >= 0)
        x = _x;
}

void Position::setY(int _y)
{
    if(_y >= 0)
        y = _y;
}
