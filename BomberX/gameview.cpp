#include "gameview.h"
#include "gamecontroller.h"

#include <iostream>

#define _IMG_CASE_DESTRUCTIBLE_ "/img/case_destructible.jpg"
#define _IMG_CASE_VIDE_ "/img/case_vide.jpg"
#define _IMG_CASE_INDESTRUCTIBLE_ "/img/case_pleine.jpg"
#define _IMG_BOMBER_ "/img/bomber.png"
#define _IMG_BOMBE_ "/img/bombe.png"
#define SPEED 27

/*
 * Constructeur
 */
GameView::GameView(GameController& gc)
{
    scene = new QGraphicsScene();
    gameController = &gc;

    this->generateGameAreaView();
}

/*
 * Actions
 */
void GameView::generateGameAreaView()
{
    // Génération de l'affichage de la map
    QPixmap caseIndestructible(_IMG_CASE_INDESTRUCTIBLE_);
    QPixmap caseVide(_IMG_CASE_VIDE_);
    QPixmap caseDestructible(_IMG_CASE_DESTRUCTIBLE_);

    for(int i = 0 ; i < 15 ; i++){
        for(int j = 0 ; j < 15 ; j++){
            switch(gameController->gameArea.at(i).at(j)->getTypeDeCase()){
            case INDESTRUCTIBLE:
                scene->addPixmap(caseIndestructible)->setOffset(j*caseIndestructible.width(), i*caseIndestructible.height());
                break;

            case DESTRUCTIBLE:
                scene->addPixmap(caseDestructible)->setOffset(j*caseIndestructible.width(), i*caseIndestructible.height());
                break;

            default:
                scene->addPixmap(caseVide)->setOffset(j*caseIndestructible.width(), i*caseIndestructible.height());
            }
        }
    }

    // Génération de l'affichage des personnages
    QPixmap bomber(_IMG_BOMBER_);

    bomber1 = new QGraphicsPixmapItem(bomber, NULL, scene);
    bomber1->setOffset(35, 25);

    //bomber2 = new QGraphicsPixmapItem(bomber, NULL, scene);

    //bomber3 = new QGraphicsPixmapItem(bomber, NULL, scene);

    bomber4 = new QGraphicsPixmapItem(bomber, NULL, scene);
    bomber4->setOffset(390, 350);

    // Appel à la méthode d'affichage générale
    this->displayGameView();
}

void GameView::displayGameView()
{
    // Génération de l'affichage général
    playButton = new QPushButton("Play !");
    quitButton = new QPushButton("Quitter");

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(playButton);
    vlayout->addWidget(quitButton);

    view = new QGraphicsView(scene, this);
    view->setFixedSize(640, 480);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addLayout(vlayout);
    hLayout->addWidget(view);

    this->setLayout(hLayout);
    this->setWindowTitle("Bomber X");
    this->show();

    this->setFocus();

    // Connexions
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void GameView::actionPlay()
{

}

/*
 * Gestion des entrées clavier
 */
void GameView::keyPressEvent(QKeyEvent* e)
{
    switch(e->key()){
        /*GESTION DU PLAYER 1*/

    case Qt::Key_Z:
            if (gameController->bomberWantMoveToPosition(1, TOP))
               bomber1->setOffset(bomber1->offset().x(), bomber1->offset().y()-SPEED);
    break;

    case Qt::Key_S:
            if (gameController->bomberWantMoveToPosition(1, BOTTOM))
                bomber1->setOffset(bomber1->offset().x(), bomber1->offset().y()+SPEED);
    break;

    case Qt::Key_D:
            if (gameController->bomberWantMoveToPosition(1, RIGHT))
                bomber1->setOffset(bomber1->offset().x()+SPEED, bomber1->offset().y());
    break;

    case Qt::Key_Q:
            if (gameController->bomberWantMoveToPosition(1, LEFT))
                bomber1->setOffset(bomber1->offset().x()-SPEED, bomber1->offset().y());
    break;

    case Qt::Key_A:
            if(gameController->canPlantBombe(1)) {
                QPixmap imgBombe(_IMG_BOMBE_);
                QGraphicsPixmapItem *bombe = new QGraphicsPixmapItem(imgBombe, NULL, scene);
                bombe->setOffset(bomber1->offset().x(), bomber1->offset().y());
            }
    break;

   /*GESTION DU PLAYER 4*/

    case Qt::Key_Up:
            if (gameController->bomberWantMoveToPosition(4, TOP))
                 bomber4->setOffset(bomber4->offset().x(), bomber4->offset().y()-SPEED);
    break;

    case Qt::Key_Down:
            if (gameController->bomberWantMoveToPosition(4, BOTTOM))
                 bomber4->setOffset(bomber4->offset().x(), bomber4->offset().y()+SPEED);
    break;

    case Qt::Key_Right:
            if (gameController->bomberWantMoveToPosition(4, RIGHT))
           bomber4->setOffset(bomber4->offset().x()+SPEED, bomber4->offset().y());
    break;

    case Qt::Key_Left:
            if (gameController->bomberWantMoveToPosition(4, LEFT))
              bomber4->setOffset(bomber4->offset().x()-SPEED, bomber4->offset().y());
    break;

    case Qt::Key_Shift:
            if(gameController->canPlantBombe(4)) {
                QPixmap imgBombe(_IMG_BOMBE_);
                QGraphicsPixmapItem *bombe = new QGraphicsPixmapItem(imgBombe, NULL, scene);
                bombe->setOffset(bomber4->offset().x(), bomber4->offset().y());
            }
    break;

    case Qt::Key_Space:
            std::cout << "Check braw !" << std::endl;
    break;

    default:
    break;
    }
}
