#include "gamecontroller.h"

#include <iostream>

GameController::GameController(QWidget *parent) :
    QWidget(parent)
{
    // Création d'une boucle évènementielle pour la gestion des bombes
    QTimer *bombesTimer = new QTimer(this);
    connect(bombesTimer, SIGNAL(timeout()), this, SLOT(someBombesShouldMaybeExplose()));
    bombesTimer->start(1000);

    // Génération du tableau logique de cases
    this->generateGameArea();

    // Affichage de la vue
    gameView = new GameView(*this);
}

void GameController::generateGameArea()
{
    // Génération de la map
    for(int ligne = 0 ; ligne < 15 ; ligne++){
        this->gameArea.append(QVector<Case*>());
        for (int colonne = 0 ; colonne < 15 ; colonne++) {
            if (ligne == 0 || ligne == 14 || colonne == 0 || colonne == 14) {
                // Les bords de la map
                this->gameArea[ligne].append(new Case(INDESTRUCTIBLE));
            } else {
                if (    (ligne == 3 || ligne == 7 || ligne == 11) && (colonne == 3 || colonne == 7 || colonne == 11)
                    ||  (ligne == 5 || ligne == 9 ) && ( colonne == 5 || colonne == 9)
                    ) {
                    // Les cases indestructibles à l'intérieur de la map
                    this->gameArea[ligne].append(new Case(INDESTRUCTIBLE) );
                } else {
                    if (    (ligne == 1 && (colonne == 1 || colonne == 2 || colonne == 3 || colonne == 11 || colonne == 12 || colonne == 13 ))
                        ||  ( (ligne == 2 || ligne == 3) && (colonne == 1 || colonne == 13 ))
                        ||  ( (ligne == 11 || ligne == 12) && (colonne == 1 || colonne == 13 ))
                        ||  (ligne == 13 && (colonne == 1 || colonne == 2 || colonne == 3 || colonne == 11 || colonne == 12 || colonne == 13 ))
                        )
                        // Génération des zones de départ pour le mouvement des Bombermans
                        this->gameArea[ligne].append(new Case(VIDE));
                    else
                        this->gameArea[ligne].append(new Case(DESTRUCTIBLE));
                }
            }
        }
    }

    // Génération des bombermans
    player1 = new Bomberman(1, 1);
    player2 = new Bomberman(1, 13);
    player3 = new Bomberman(13, 1);
    player4 = new Bomberman(13, 13);
}

bool GameController::bomberWantMoveToPosition(int _bomber, Movement mov)
{
    Bomberman* bomber;
    bool bomberCanMove = false;

    switch (_bomber){
    case 1:
        bomber = player1;
        break;
    case 2:
        bomber = player2;
        break;
    case 3:
        bomber = player3;
        break;
    case 4:
        bomber = player4;
        break;
    default:
        break;
    }

    switch (mov){
    case TOP:
        bomberCanMove = this->isCaseEmptyAtPosition(bomber->getY()-1, bomber->getX());
        if (bomberCanMove)
            bomber->setY(bomber->getY()-1);
        break;
    case RIGHT:
        bomberCanMove = this->isCaseEmptyAtPosition(bomber->getY(), bomber->getX()+1);
        if (bomberCanMove)
            bomber->setX(bomber->getX()+1);
        break;
    case BOTTOM:
        bomberCanMove = this->isCaseEmptyAtPosition(bomber->getY()+1, bomber->getX());
        if (bomberCanMove)
            bomber->setY(bomber->getY()+1);
        break;
    case LEFT:
        bomberCanMove = this->isCaseEmptyAtPosition(bomber->getY(), bomber->getX()-1);
        if (bomberCanMove)
            bomber->setX(bomber->getX()-1);
        break;
    default:
        break;
    }

    // Debug
    std::cout << "Position X: " << bomber->getX() << " Position Y: " << bomber->getY() << std::endl;

    return bomberCanMove;
}

bool GameController::isCaseEmptyAtPosition(int ligne, int colonne)
{
    TypeDeCase typeCase = this->gameArea[ligne][colonne]->getTypeDeCase();
    if (typeCase != VIDE)
        return false;
    else
        return true;
}

// Slots
void GameController::someBombesShouldMaybeExplose()
{
    for(int i = 0 ; i < this->bombes.size() ; i++){
        this->bombes.at(i)->decrementeShouldExploseIn();
        if(this->bombes.at(i)->bombeShouldExplose()){
            std::cout << "BOOM!" << std::endl;
            this->bombes.remove(i);
        }
    }
}

// Tests compteurBombe
bool GameController::canPlantBombe(int _bomber)
{
    bool canPlant = false;
    switch (_bomber){
    case 1:
        canPlant = player1->getCompteurBombe() != 0;
        std::cout << "Compteur Bombe = " << player1->getCompteurBombe() << std::endl;
        if (canPlant)
            player1->decrementeCompteurBombe();
        break;
    case 2:
        canPlant = player2->getCompteurBombe() != 0;
        if (canPlant)
            player2->decrementeCompteurBombe();
        break;
    case 3:
        canPlant = player3->getCompteurBombe() != 0;
        if (canPlant)
            player3->decrementeCompteurBombe();
        break;
    case 4:
        canPlant = player4->getCompteurBombe() != 0;
        if (canPlant)
            player4->decrementeCompteurBombe();
        break;
    default:
         break;
    }

    if(canPlant)
        this->plantNewBombe();

    return canPlant;
}

void GameController::plantNewBombe()
{
    this->bombes.append(new Bombe());
}
