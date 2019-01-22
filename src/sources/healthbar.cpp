#include "healthbar.h"

healthbar::healthbar(int iX, int iY)
{
    my_place.x = iX;
    my_place.y = iY;
    mvprintw(my_place.y, my_place.x, "Health: ");
    bar = ' ' | COLOR_PAIR(8);
    move(my_place.y, my_place.x + 8);
    addch(bar);
    move(my_place.y, my_place.x + 10);
    addch(bar);
    move(my_place.y, my_place.x + 12);
    addch(bar);
}

healthbar::~healthbar()
{

}

void healthbar::update(int condition)
{
    switch (condition)
    {
    case good:
        bar = ' ' | COLOR_PAIR(8);
        move(my_place.y, my_place.x + 8);
        addch(bar);
        move(my_place.y, my_place.x + 10);
        addch(bar);
        move(my_place.y, my_place.x + 12);
        addch(bar);
        break;
    case average:
        bar = ' ' | COLOR_PAIR(8);
        move(my_place.y, my_place.x + 8);
        addch(bar);
        move(my_place.y, my_place.x + 10);
        addch(bar);
        bar = ' ' | COLOR_PAIR(9);
        move(my_place.y, my_place.x + 12);
        addch(bar);
        break;
    case bad:
        bar = ' ' | COLOR_PAIR(8);
        move(my_place.y, my_place.x + 8);
        addch(bar);
        bar = ' ' | COLOR_PAIR(9);
        move(my_place.y, my_place.x + 10);
        addch(bar);
        move(my_place.y, my_place.x + 12);
        addch(bar);
        break;
    case dead:
        bar = ' ' | COLOR_PAIR(9);
        move(my_place.y, my_place.x + 8);
        addch(bar);
        move(my_place.y, my_place.x + 10);
        addch(bar);
        move(my_place.y, my_place.x + 12);
        addch(bar);
        break;
        break;
    }
}
