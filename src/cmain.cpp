#include "cmain.h"

cmain::cmain()
{
    printf("\e[8;25;90t");
    initscr();
    noecho();
    keypad(stdscr, true);
    raw();
    curs_set(0);
    clear() && refresh();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
}

cmain::~cmain()
{
    keypad(stdscr, false);
    endwin();
}

void cmain::menu()
{
    getmaxyx(stdscr, rows, columns);

    mvprintw(rows / 2 - 1, columns / 2, "Press '1' to start the game.");
    mvprintw(rows / 2 + 1, columns / 2, "Press '2' to close the game.");

    chtype ch;
    ch = 'a' | COLOR_PAIR(1);

    for (int i = 0; i < rows - 1; ++i)
    {
        move(i, 0);
        addch(ch);
        move(i, columns - 1);
        addch(ch);
    }
    for (int i = 0; i < columns; ++i)
    {
        move(0, i);
        addch(ch);
        move(rows - 1, i);
        addch(ch);
    }
    refresh();
}

void cmain::gameloop()
{
    nodelay(stdscr, true);
    while(1)
    {
        clear();
        mvprintw(3,3,"smth");
        refresh();
    }
    nodelay(stdscr, false);
}

void cmain::mainloop()
{
    menu();

    bool checker = true;
    while(checker)
    {
        //mvprintw(3,3,"%d\t%c", button, button);
        switch(button = getch())
        {
            case 49:
                //gameloop();
                break;
            case 50:
                checker = false;
                break;
        }
    }
}
