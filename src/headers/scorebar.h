#include <ncurses.h>
#include "object.h"

#ifndef SCOREBAR_H
#define SCOREBAR_H

class scorebar
{
private:
    coordinates my_place;
    long int score;

public:
    scorebar(int iX, int iY);
    ~scorebar();
    void update(int i);
};

#endif
