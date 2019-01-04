#include "object.h"

object::object()
{
    my_place.y = my_place.x = 0;
}

object::object(int iX, int iY)
{
    my_place.y = iY;
    my_place.x = iX;
}

object::object(int iX, int iY, char cSprite, int iColor)
{
    my_place.y = iY;
    my_place.x = iX;
    sprite = cSprite | COLOR_PAIR(iColor);
}

object::~object()
{

}

void object::draw()
{
    move(my_place.y, my_place.x);
    addch(sprite);
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
