#include <ncurses.h>

#ifndef OBJECT_H
#define OBJECT_H

struct coordinates
{
    int y, x;
};

class object
{
    protected:
        coordinates my_place;
        chtype sprite;

    public:
        object();
        object(int iX, int iY);
        object(int iX, int iY, char cSprite, int iColor);
        ~object();
        void set_place_x(int iX);
        void set_place_y(int iY);
        int get_place_x();
        int get_place_y();
        void draw();
};

#endif
