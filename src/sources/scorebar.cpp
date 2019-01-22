#include "scorebar.h"

scorebar::scorebar(int iX, int iY)
{
    my_place.x = iX;
    my_place.y = iY;
    score = 0;
    mvprintw(my_place.y, my_place.x, "Score: %d", score);
}

scorebar::~scorebar()
{

}

void scorebar::update(int i)
{
    score = score + i;
    mvprintw(my_place.y, my_place.x + 7, "%d00", score);
}
