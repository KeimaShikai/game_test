#include <ncurses.h>
#include "object.h"
#include "player.h"

#ifndef HEALTHBAR_H
#define HEALTHBAR_H

class healthbar
{
    private:
        coordinates my_place;
        short int health;
        chtype bar;

    public:
        healthbar(int iX, int iY);
        ~healthbar();
        void update(int condition);
};

#endif
