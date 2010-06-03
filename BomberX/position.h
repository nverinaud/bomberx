#ifndef POSITION_H
#define POSITION_H

#include <QObject>

class Position : public QObject
{
public:
    Position();

    int getX();
    int getY();
    void setX(int _x);
    void setY(int _y);

private:
    int x,y;

};

#endif // POSITION_H
