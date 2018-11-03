#include <ncurses.h>

#ifndef PLAYER_H
#define PLAYER_H

struct coordinates
{
    int y, x;
};

enum state
{
    dead, bad, average, good
};

class player
{
    private:
        coordinates my_place;
        state my_state;
        chtype sprite = 'A' | COLOR_PAIR(2);
    public:
        player();
        player(int iX, int iY);
        ~player();
        void set_place_x(int iX);
        void set_place_y(int iY);
        int get_place_x();
        int get_place_y();
        void draw();
        //collision
};

#endif
