#include <ncurses.h>
#include <iostream>
#include <string>

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
        void gameloop();
        void mainloop();    
};

#endif
