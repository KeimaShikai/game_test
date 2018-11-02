#include <ncurses.h>
#include <iostream>
#include <string>

#ifndef CMAIN_H
#define CMAIN_H

class cmain
{
    private:
        int columns, rows;
        int button;
    public:
        cmain();
        ~cmain();
        void menu();
        void gameloop();
        void mainloop();    
};

#endif
