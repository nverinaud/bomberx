#ifndef BASE_H
#define BASE_H

enum TypeDeCase {
    VIDE,
    DESTRUCTIBLE,
    INDESTRUCTIBLE,
    DECOR,
    BOMBER1,
    BOMBER2
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

#define _IMG_CASE_DESTRUCTIBLE_ "/img/case_destructible.png"
#define _IMG_CASE_INDESTRUCTIBLE_ "/img/case_indestructible.png"
#define _IMG_BOMBER_ "/img/face3.png"
#define _IMG_BOMBE_ "/img/bombe2.png"
#define _TERRAIN_ "/img/terrain.png"
#define _IMG_VIDE_ "/img/vide.png"
#define SPEED 30

#endif // BASE_H
