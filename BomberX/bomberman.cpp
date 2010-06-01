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
    bomberPower = 2;
}

Bomberman::~Bomberman()
{

}

/*
 * Compteur de bombe
 */

void Bomberman::decrementeCompteurBombe(){
    if(compteurBombe != 0)
        compteurBombe--;
}

void Bomberman::incrementeCompteurBombe(){
        compteurBombe++;
}

/*
 * Bonus
 */

int Bomberman::getBomberPower()
{
    return bomberPower;
}

void Bomberman::incrementeBomberPower()
{
    bomberPower++;
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
