#include <QtGui/QApplication>

#include "gamecontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new GameController();

    // Test

    return a.exec();
}
