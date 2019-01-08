#include "enemy.h"

void enemy::spawn()
{
    //TODO random delay with use of counter
    delayCounter = 0;
    direction = rand() % 3 - 1;
    my_place_old.y = my_place.y;
    my_place_old.x = my_place.x;
    my_place.y = 0;
    my_place.x = rand() % 90;
    isAlive = true;
    draw();
}

void enemy::shift()
{
    if (isAlive)
        if (my_place.x >= 1 && my_place.x < 89
                && my_place.y >= 0 && my_place.y < 24)
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
        spawn();
    }

    ++delayCounter;
}
