#include "cmain.h"

cmain::cmain()
{
    initscr();
    noecho();
    raw();
    curs_set(0);
    clear() && refresh();
}

cmain::~cmain()
{
    endwin();
}

//put the-size-of-the-window check to the outer function
// and clear'n'refresh the window after each change in a size
// do I need new variables to store last size of the window

void cmain::mainloop()
{
    //while((button = getch()) != 27) //do I need a second thread for it
    while(1)
    {
        clear(); //I will need to remove it in a future
        getmaxyx(stdscr, cur_rows, cur_columns);
        if (cur_rows < min_rows) cur_rows = min_rows;
        if (cur_columns < min_colomns) cur_columns = min_colomns;
        printf("\e[8;%d;%d;t", cur_rows, cur_columns); //it cause troubles without clear()
        refresh();
    }
}
