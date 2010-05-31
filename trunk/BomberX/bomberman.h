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

    void decrementeCompteurBombe();
    void incrementeCompteurBombe();

    // Getters & Setters
    QString getColor();
    int getCompteurBombe();
    void setCompteurBombe(int);

public slots:

private:
    QString color;
    int compteurBombe;

};

#endif // BOMBERMAN_H
