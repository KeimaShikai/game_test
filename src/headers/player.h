#include <ncurses.h>
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
        int counterDelay;
        static const int counterBorder = 1000;

    public:
        player();
        player(int iX, int iY);
        player(int iX, int iY, char cSprite, int iColor);
        bool checkCondition();
        void shot();
        void bullet_handler();
        int get_bullet_place_x();
        int get_bullet_place_y();
        //TODO collision_check()
};

#endif
