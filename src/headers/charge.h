#include <ncurses.h>
#include "object.h"

#ifndef CHARGE_H
#define CHARHE_H

//TODO remove this class and switch the charge:bullet to object:bullet
class charge : public object
{
    private:

    public:
        charge() : object() {}
        charge(int iX, int iY) : object(iX, iY) {}
        charge(int iX, int iY, char cSprite, int iColor)
            : object(iX, iY, cSprite, iColor) {}
        //TODO collision_handle()
};

#endif
