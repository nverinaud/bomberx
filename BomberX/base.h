#ifndef BASE_H
#define BASE_H

enum TypeDeCase {
    DESTRUCTIBLE,
    INDESTRUCTIBLE,
    VIDE,
    DECOR
};

enum Movement{
    TOP,
    RIGHT,
    BOTTOM,
    LEFT
};

class Debug{
public:
    static bool isOn(){ return true; };

};

#endif // BASE_H
