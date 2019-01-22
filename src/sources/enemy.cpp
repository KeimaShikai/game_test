#include "enemy.h"

void enemy::spawn()
{
    delaySpawn = rand() % 10000 + 25000;
    delayCounter = 0;
    delayBorder = rand() % 1500 + 2000;
    direction = rand() % 3 - 1;
    my_place_old.y = my_place.y;
    my_place_old.x = my_place.x;
    my_place.y = 0;
    my_place.x = rand() % 90;
    isAlive = true;
}

void enemy::shift()
{
    if (delaySpawn)
    {
        --delaySpawn;
        goto end;
    }
    if (isAlive)
        if (my_place.x >= 1 && my_place.x < 89
                && my_place.y >= 0 && my_place.y < 23)
        {
            if (delayCounter == delayBorder)
            {
                my_place_old.y = my_place.y;
                my_place_old.x = my_place.x;
                my_place.y += 1;
                my_place.x += direction;
                move(my_place_old.y, my_place_old.x);
                addch(' ');
                delayCounter = 0;
            }
            move(my_place.y, my_place.x);
            addch(sprite);
            refresh();
        }
        else //TODO refactoring
        {
            isAlive = false;
        }
    else
    {
        move(my_place.y, my_place.x);
        addch(' ');
        spawn();
    }

    ++delayCounter;
    end:;
}

bool enemy::isCollide(int iX, int iY)
{
    if (my_place.x == iX && my_place.y == iY)
    {
        isAlive = false;
        return true;
    }
    else return false;
}
