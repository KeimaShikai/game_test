#include <ncurses.h>
#include "object.h"

#ifndef PLAYER_H
#define PLAYER_H

enum state
{
    dead, bad, average, good
};

class player :  public object
{
    private:

    public:
        player() : object() {}
        player(int iX, int iY) : object(iX, iY) {}
        player(int iX, int iY, char cSprite, int iColor)
            : object(iX, iY, cSprite, iColor) {}
        void shot();
        //collision_check();
};

#endif
