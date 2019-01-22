#include <ncurses.h>
#include "object.h"

#ifndef PLAYER_H
#define PLAYER_H

enum state
{
    dead, bad, average, good
};

class player : public object
{
    private:
        int condition;
        bool isFired;
        object bullet;
        char symbSprite; //TODO unify char setting
        int counterDelay;
        static const int counterBorder = 1000;

    public:
        player();
        player(int iX, int iY);
        player(int iX, int iY, char cSprite, int iColor);
        void shot();
        void bullet_handler();
        int get_bullet_place_x();
        int get_bullet_place_y();
        int check_condition();
        void change_condition(int i);
};

#endif
