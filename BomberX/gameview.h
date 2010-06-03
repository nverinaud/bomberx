#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#pragma once
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QLayout>
#include <QKeyEvent>
#include <QMessageBox>

#include "base.h"

class GameController;

class GameView : public QWidget
{
Q_OBJECT
public:
    GameView(GameController&);

    void generateGameAreaView();
    void displayGameView();
    void removeBombeAtOffset(int, int);
    void removeCaseAtOffset(int, int, TypeDeCase);
    void displayExplosionAtOffset(int, int);

    void killBomberman(int);

    void endOfTheGame();

    QGraphicsPixmapItem* bomber1, *bomber2, *bomber3, *bomber4;
    GameController* gameController;

public slots:
    void removeExplosionAtOffset();

protected:
    void keyPressEvent(QKeyEvent* e);

private:
    QPushButton *quitButton;
    QGraphicsScene *scene;
    QGraphicsView *view;

    int currentExplosionX;
    int currentExplosionY;

    QTimer* explosionRemoving;

    bool bomber1isAlive;
    bool bomber4isAlive;
};

#endif // GAMEVIEW_H
