#include <ncurses.h>
#include <unistd.h>
#include "object.h"

#ifndef PLAYER_H
#define PLAYER_H

enum state
{
    dead, bad, average, good
};

class player : public object
{
    private:
        int condition;
        bool isFired;
        object bullet;

    public:
        player();
        player(int iX, int iY);
        player(int iX, int iY, char cSprite, int iColor);
        bool checkCondition();
        void shot();
        void bullet_handler();
        //TODO collision_check()
};

#endif
