#include "player.h"

player::player()
{
    my_place.y = my_place.x = 0;
    my_state = good;
}

player::player(int iX, int iY)
{
    my_place.y = iY;
    my_place.x = iX;
    my_state = good;
}

player::~player()
{

}

void player::draw()
{
    move(my_place.y, my_place.x);
    addch(sprite);
}

void player::set_place_x(int iX)
{
    my_place.x = iX;
}

void player::set_place_y(int iY)
{
    my_place.y = iY;
}

int player::get_place_x()
{
    return my_place.x;
}

int player::get_place_y()
{
    return my_place.y;
}


