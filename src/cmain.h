#pragma once
#include <sys/ioctl.h>
#include <ncurses.h>
#include <iostream>
#include <string>

class cmain
{
    private:
        struct winsize window;
        int cur_columns, cur_rows;
        static const int min_colomns = 60, min_rows = 20;
    public:
        cmain();
        ~cmain();
        void mainloop();
};

cmain::cmain()
{
    initscr();
    clear() && refresh();
}

cmain::~cmain()
{
    endwin();
}

void cmain::mainloop()
{
    while(1)
    {
        clear();
        ioctl(0, TIOCGWINSZ, &window);
        cur_rows = window.ws_row, cur_columns = window.ws_col;
        if (cur_rows < min_rows) cur_rows = min_rows;
        if (cur_columns < min_colomns) cur_columns = min_colomns;
        printw("x: %d, y: %d", cur_columns, cur_rows);
        printf("\e[8;%d;%d;t", cur_rows, cur_columns);
        refresh();
        //TODO выход из петли по нажатию клавиши
    }
}
