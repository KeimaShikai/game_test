#include <ncurses.h>
#include <iostream>
#include <string>

#ifndef CMAIN_H
#define CMAIN_H

class cmain
{
    private:
        int cur_columns, cur_rows;
        int button;
        static const int min_colomns = 60, min_rows = 20;
    public:
        cmain();
        ~cmain();
        void mainloop();
};

#endif
