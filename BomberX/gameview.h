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

    QGraphicsPixmapItem* bomber1, *bomber2, *bomber3, *bomber4;
    GameController* gameController;

public slots:
    void actionPlay();

protected:
    void keyPressEvent(QKeyEvent* e);

private:
    QPushButton *playButton, *quitButton;
    QGraphicsScene *scene;
    QGraphicsView *view;

};

#endif // GAMEVIEW_H
