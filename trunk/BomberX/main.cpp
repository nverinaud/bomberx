#include <QtGui/QApplication>

#include "gamecontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new GameController();

    return a.exec();
}
