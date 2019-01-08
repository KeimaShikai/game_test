#include "object.h"

object::object()
{
    my_place.y = my_place.x = 0;
    my_place_old.y = my_place_old.x = 0;
}

object::object(int iX, int iY)
{
    my_place.y = my_place_old.y = iY;
    my_place.x = my_place_old.x = iX;
}

object::object(int iX, int iY, char cSprite, int iColor)
{
    my_place.y = my_place_old.y = iY;
    my_place.x = my_place_old.x = iX;
    sprite = cSprite | COLOR_PAIR(iColor);
}

object::~object()
{

}

void object::draw()
{
    move(my_place_old.y, my_place_old.x);
    addch(' ');
    move(my_place.y, my_place.x);
    addch(sprite);
    refresh();
}

void object::set_place_x(int iX)
{
    my_place.x = iX;
}

void object::set_place_y(int iY)
{
    my_place.y = iY;
}

int object::get_place_x()
{
    return my_place.x;
}

int object::get_place_y()
{
    return my_place.y;
}

void object::set_place_old_x(int iX)
{
    my_place_old.x = iX;
}

void object::set_place_old_y(int iY)
{
    my_place_old.y = iY;
}

int object::get_place_old_x()
{
    return my_place_old.x;
}

int object::get_place_old_y()
{
    return my_place_old.y;
}
