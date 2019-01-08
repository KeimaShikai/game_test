#include <ncurses.h>
#include <iostream>
#include <string>
#include "player.h"
#include "factory_enemy.h"

#ifndef CMAIN_H
#define CMAIN_H

class cmain
{
    private:
        int x, y;
        static const int columns = 90, rows = 25;
        int button;
    public:
        cmain();
        ~cmain();
        void menu();
        void game();
        void help();
        void mainloop();    
};

#endif
