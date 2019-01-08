#include <ncurses.h>
#include <cstdlib>
#include "object.h"

#ifndef ENEMY_H
#define ENEMY_H

class enemy : public object
{
    private:
        bool isAlive;
        short int direction;
        int delayCounter;
        static const int delayBorder = 1500; //TODO random

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
};

#endif
