#include "gameview.h"
#include "gamecontroller.h"

#include <iostream>

/*
 * Constructeur
 */
GameView::GameView(GameController& gc)
{
    gameController = &gc;

    bomber1isAlive = true;
    bomber4isAlive = true;

    explosionRemoving = new QTimer(this);
    connect(explosionRemoving, SIGNAL(timeout()), this, SLOT(removeExplosionAtOffset()));

    this->generateGameAreaView();
}

/*
 * Actions
 */
void GameView::generateGameAreaView()
{
    scene = new QGraphicsScene();
    
    // Génération de l'affichage de la map
    QPixmap caseIndestructible(_IMG_CASE_INDESTRUCTIBLE_);
    QPixmap caseDestructible(_IMG_CASE_DESTRUCTIBLE_);
    QPixmap caseDecor(_IMG_VIDE_);

    for(int i = 0 ; i < 15 ; i++){
        for(int j = 0 ; j < 15 ; j++){
            switch(gameController->gameArea.at(i).at(j)->getTypeDeCase()){
            case INDESTRUCTIBLE:
                scene->addPixmap(caseIndestructible)->setOffset(j*caseIndestructible.width(), i*caseIndestructible.height());
                break;

            case DESTRUCTIBLE:
                scene->addPixmap(caseDestructible)->setOffset(j*caseIndestructible.width(), i*caseIndestructible.height());
                break;

            case DECOR:
                scene->addPixmap(caseDecor)->setOffset(j*caseIndestructible.width(), i*caseIndestructible.height());
                break;

            default:

                break;
            }
        }
    }

    QPixmap terrain(_TERRAIN_);
    QBrush myBrush(terrain);
    scene->setBackgroundBrush(myBrush);

    // Génération de l'affichage des personnages
    QPixmap bomber(_IMG_BOMBER_);

    bomber1 = new QGraphicsPixmapItem(bomber, NULL, scene);
    bomber1->setOffset(SPEED+5, SPEED);

    //bomber2 = new QGraphicsPixmapItem(bomber, NULL, scene);

    //bomber3 = new QGraphicsPixmapItem(bomber, NULL, scene);

    bomber4 = new QGraphicsPixmapItem(bomber, NULL, scene);
    bomber4->setOffset(scene->width()-SPEED*2+5, scene->height()-SPEED*2);

    // Appel à la méthode d'affichage générale
    this->displayGameView();
}

void GameView::displayGameView()
{
    // Génération de l'affichage général
    quitButton = new QPushButton("Quitter");

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(quitButton);

    view = new QGraphicsView(scene, this);
    view->setFixedSize(scene->width()+10, scene->height()+10);

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

/*
 * Gestion des entrées clavier
 */
void GameView::keyPressEvent(QKeyEvent* e)
{
    if(Debug::isOn())
        std::cout << "Offset X: " << bomber1->offset().x() << " Offset Y: " << bomber1->offset().y() << std::endl;

    switch(e->key()){
        /*GESTION DU PLAYER 1*/

    case Qt::Key_Z:
            if (gameController->bomberWantMoveToPosition(1, TOP) && bomber1isAlive)
               bomber1->setOffset(bomber1->offset().x(), bomber1->offset().y()-SPEED);
        break;

    case Qt::Key_S:
            if (gameController->bomberWantMoveToPosition(1, BOTTOM) && bomber1isAlive)
                bomber1->setOffset(bomber1->offset().x(), bomber1->offset().y()+SPEED);
        break;

    case Qt::Key_D:
            if (gameController->bomberWantMoveToPosition(1, RIGHT) && bomber1isAlive)
                bomber1->setOffset(bomber1->offset().x()+SPEED, bomber1->offset().y());
        break;

    case Qt::Key_Q:
            if (gameController->bomberWantMoveToPosition(1, LEFT) && bomber1isAlive)
                bomber1->setOffset(bomber1->offset().x()-SPEED, bomber1->offset().y());
        break;

    case Qt::Key_A:
            if(gameController->canPlantBombe(1, bomber1->offset().x(), bomber1->offset().y()-10) && bomber1isAlive) {
                QPixmap imgBombe(_IMG_BOMBE_);
                QGraphicsPixmapItem *bombe = new QGraphicsPixmapItem(imgBombe, NULL, scene);
                bombe->setOffset(bomber1->offset().x(), bomber1->offset().y()-10);
            }
        break;

   /*GESTION DU PLAYER 4*/

    case Qt::Key_Up:
            if (gameController->bomberWantMoveToPosition(4, TOP) && bomber4isAlive)
                 bomber4->setOffset(bomber4->offset().x(), bomber4->offset().y()-SPEED);
        break;

    case Qt::Key_Down:
            if (gameController->bomberWantMoveToPosition(4, BOTTOM) && bomber4isAlive)
                 bomber4->setOffset(bomber4->offset().x(), bomber4->offset().y()+SPEED);
        break;

    case Qt::Key_Right:
            if (gameController->bomberWantMoveToPosition(4, RIGHT) && bomber4isAlive)
           bomber4->setOffset(bomber4->offset().x()+SPEED, bomber4->offset().y());
        break;

    case Qt::Key_Left:
            if (gameController->bomberWantMoveToPosition(4, LEFT) && bomber4isAlive)
              bomber4->setOffset(bomber4->offset().x()-SPEED, bomber4->offset().y());
        break;

    case Qt::Key_Shift:
            if(gameController->canPlantBombe(4, bomber4->offset().x(), bomber4->offset().y()-10) && bomber4isAlive) {
                QPixmap imgBombe(_IMG_BOMBE_);
                QGraphicsPixmapItem *bombe = new QGraphicsPixmapItem(imgBombe, NULL, scene);
                bombe->setOffset(bomber4->offset().x(), bomber4->offset().y()-10);
            }
        break;

    default:
        break;
    }
}

void GameView::removeBombeAtOffset(int _x, int _y)
{
    scene->removeItem(scene->itemAt(_x+20, _y+20));
}

void GameView::removeCaseAtOffset(int _y, int _x, TypeDeCase caseType)
{
    if(Debug::isOn())
        std::cout << "Case at Offset Y=" << _y*SPEED+10 << " X=" << _x*SPEED+10 << std::endl;

    if(caseType != VIDE)
        scene->removeItem(scene->itemAt(_x*SPEED+20, _y*SPEED+20));

    this->displayExplosionAtOffset(_y*SPEED, _x*SPEED);
}

void GameView::displayExplosionAtOffset(int _y, int _x)
{
    QPixmap explosion(_IMG_EXPLOSION_);
    scene->addPixmap(explosion)->setOffset(_x, _y);
    currentExplosionX = _x;
    currentExplosionY = _y;

//    this->explosionRemoving->start();
    this->removeExplosionAtOffset();
}

// Slot
void GameView::removeExplosionAtOffset()
{
    scene->removeItem(scene->itemAt(currentExplosionX, currentExplosionY));
//    this->explosionRemoving->stop();
}

void GameView::killBomberman(int bomberId){
    switch(bomberId){
    case 1:
        this->bomber1isAlive = false;
        this->scene->removeItem(scene->itemAt(bomber1->offset().x(), bomber1->offset().y()));
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        this->bomber4isAlive = false;
        this->scene->removeItem(scene->itemAt(bomber4->offset().x(), bomber4->offset().y()));
        break;
    default:
        break;
    }

    this->endOfTheGame();
}

void GameView::endOfTheGame()
{
    if(bomber1isAlive)
        QMessageBox::information(this, "Fin de la partie", "Le gagnant est le joueur 1");

    if(bomber4isAlive)
        QMessageBox::information(this, "Fin de la partie", "Le gagnant est le joueur 2");

    qApp->quit();
}

