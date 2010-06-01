#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

// Qt Elements
#include <QVector>
#include <QWidget>
#include <QEvent>
#include <QTimer>

// Model
#include "bomberman.h"
#include "case.h"
#include "bombe.h"

// View
#include "gameview.h"

class GameController : public QWidget
{
Q_OBJECT
public:
    GameController(QWidget *parent = 0);

    // Objects
    Bomberman *player1, *player2, *player3, *player4;
    QVector< QVector< Case* > > gameArea;
    QVector< Bombe* > bombes;
    GameView *gameView;

    // Actions
    void generateGameArea();
    bool bomberWantMoveToPosition(int, Movement);
    bool isCaseEmptyAtPosition(int, int);

    bool canPlantBombe(int, int, int);
    void plantNewBombe(int, int, int);
    void bombeExplosed(Bombe*);

public slots:
    void someBombesShouldMaybeExplose();

};

#endif // GAMECONTROLLER_H
