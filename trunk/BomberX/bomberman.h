#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include "position.h"

class Bomberman : public Position
{
Q_OBJECT
public:
    // Constructors & Destructor
    Bomberman();
    Bomberman(int, int);
    ~Bomberman();

    // Compteur de bombe
    void decrementeCompteurBombe();
    void incrementeCompteurBombe();

    // Bonus
    int getBomberPower();
    void incrementeBomberPower();

    // Getters & Setters
    QString getColor();
    int getCompteurBombe();
    void setCompteurBombe(int);

public slots:

private:
    QString color;
    int compteurBombe;
    int bomberPower;

};

#endif // BOMBERMAN_H
