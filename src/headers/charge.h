#include <ncurses.h>
#include "object.h"

#ifndef CHARGE_H
#define CHARHE_H

class charge :  public object
{
    private:

    public:
        charge() : object() {}
        charge(int iX, int iY) : object(iX, iY) {}
        charge(int iX, int iY, char cSprite, int iColor)
            : object(iX, iY, cSprite, iColor) {}
};

#endif
