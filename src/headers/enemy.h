#include <ncurses.h>
#include <cstdlib>
#include "object.h"

#ifndef ENEMY_H
#define ENEMY_H

enum button_click
{
    left,
    left_up,
    up,
    right_up,
    right,
    right_down,
    down,
    left_down,
    fire,
    pause
};

class enemy : public object
{
    private:
        bool isAlive;
        short int direction;
        int delaySpawn;
        int delayCounter;
        int delayBorder;

    public:
        enemy() : object()
        {
            isAlive = false;
        }
        enemy(int iX, int iY) : object(iX, iY)
        {
            isAlive = false;
        }
        enemy(int iX, int iY, char cSprite, int iColor) //TODO switch input parameters
            : object(iX, iY, cSprite, iColor)
        {
            isAlive = false;
        }
        void spawn();
        void shift();
        bool isCollide(int iX, int iY);
};

#endif
