#include "player.h"

player::player() : bullet(my_place.x, my_place.y, '^', 7)
{
    my_place.y = my_place.x = 0;
    my_place_old.y = my_place_old.x = 0;
    condition = good;
    isFired = false;
    counterDelay = 0;
}

player::player(int iX, int iY) : bullet(my_place.x, my_place.y, '^', 7)
{
    my_place.y = my_place_old.y = iY;
    my_place.x = my_place_old.x = iX;
    condition = good;
    isFired = false;
    counterDelay = 0;
}

player::player(int iX, int iY, char cSprite, int iColor)
    : bullet(my_place.x, my_place.y, '^', 7)
{
    my_place.y = my_place_old.y = iY;
    my_place.x = my_place_old.x = iX;
    symbSprite = cSprite;
    sprite = symbSprite | COLOR_PAIR(iColor);
    condition = good;
    isFired = false;
    counterDelay = 0;
}

void player::shot()
{
    if (!isFired)
    {
        isFired = true;
        bullet.set_place_x(my_place.x);
        bullet.set_place_y(my_place.y - 1);
        bullet.draw();
        bullet.set_place_old_x(bullet.get_place_x());
        bullet.set_place_old_y(bullet.get_place_y());
    }
}

void player::bullet_handler()
{
    //TODO add collision handler
    if (isFired && bullet.get_place_y() > 0)
    {
        if (counterDelay == counterBorder)
        {
            bullet.set_place_old_y(bullet.get_place_y());
            bullet.set_place_y(bullet.get_place_y() - 1);
            bullet.draw();
            counterDelay = 0;
        }
        else
        {
            ++counterDelay;
        }
    }
    else if (bullet.get_place_y() == 0)
    {
        isFired = false;
        move(bullet.get_place_y(), bullet.get_place_x());
        addch(' ');
        bullet.set_place_x(-2);
        bullet.set_place_y(-2);
    }
}

int player::get_bullet_place_x()
{
    return bullet.get_place_x();
}

int player::get_bullet_place_y()
{
    return bullet.get_place_y();
}

int player::check_condition()
{
    return condition;
}

void player::change_condition(int i)
{
    condition += i;
    switch (condition)
    {
    case good:
        sprite = symbSprite | COLOR_PAIR(2);
        break;
    case average:
        sprite = symbSprite | COLOR_PAIR(3);
        break;
    case bad:
        sprite = symbSprite | COLOR_PAIR(4);
        break;
    }
}
