#include "player.h"

player::player() : bullet(my_place.x, my_place.y, '^', 2)
{
    my_place.y = my_place.x = 0;
    condition = good;
    isFired = false;
}

player::player(int iX, int iY) : bullet(my_place.x, my_place.y, '^', 2)
{
    my_place.y = iY;
    my_place.x = iX;
    condition = good;
    isFired = false;
}

player::player(int iX, int iY, char cSprite, int iColor)
    : bullet(my_place.x, my_place.y, '^', 2)
{
    my_place.y = iY;
    my_place.x = iX;
    sprite = cSprite | COLOR_PAIR(iColor);
    condition = good;
    isFired = false;
}

bool player::checkCondition()
{
    return condition;
}

void player::shot()
{
    if (!isFired)
    {
        isFired = true;
        bullet.set_place_x(my_place.x);
        bullet.set_place_y(my_place.y - 1);
        bullet.draw();
    }
}

void player::bullet_handler()
{
    //TODO add collision handler
    if(isFired && bullet.get_place_y() > 0)
    {
        bullet.set_place_y(bullet.get_place_y() - 1);
        bullet.draw();
        usleep(15000);
    }
    else
    {
        isFired = false;
    }
}
