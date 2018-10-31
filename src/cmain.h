#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>

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

cmain::cmain()
{
    initscr();
    noecho();
    raw();
    curs_set(0); //do not forget to hide it back after moving
    clear() && refresh();
}

cmain::~cmain()
{
    endwin();
}

void cmain::mainloop()
{
    //while((button = getch()) != 27) //ВТОРОЙ ПОТОК?
    while(1)
    {
        clear();
        getmaxyx(stdscr, cur_rows, cur_columns);
        if (cur_rows < min_rows) cur_rows = min_rows;
        if (cur_columns < min_colomns) cur_columns = min_colomns;
        printf("\e[8;%d;%d;t", cur_rows, cur_columns);
        refresh();
    }
}
