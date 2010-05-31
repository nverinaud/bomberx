#include "bomberman.h"

/*
 * Constructors & Destructor
 */
Bomberman::Bomberman()
{

}

Bomberman::Bomberman(int _x, int _y)
{
    setX(_x);
    setY(_y);
    setCompteurBombe(1);
}

Bomberman::~Bomberman()
{

}

/*
 * Getters & Setters
 */
QString Bomberman::getColor()
{
    return color;
}

int Bomberman::getCompteurBombe()
{
 return compteurBombe;
}

void Bomberman::setCompteurBombe(int _compteurBombe)
{
    if (_compteurBombe >= 0)
        compteurBombe = _compteurBombe;
}

void Bomberman::decrementeCompteurBombe(){
    if(compteurBombe != 0)
        compteurBombe--;
}

void Bomberman::incrementeCompteurBombe(){
        compteurBombe++;
}

