#include "cmain.h"

cmain::cmain()
{
    printf("\e[8;%d;%dt", rows, columns);
    initscr();
    noecho();
    keypad(stdscr, true);
    raw();
    curs_set(0);
    clear() && refresh();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN); //for a menu interface
    init_pair(2, COLOR_WHITE, COLOR_BLACK); //for a spaceship in a 'good' state
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); //for a spaceship in a 'good' state
    init_pair(4, COLOR_RED, COLOR_BLACK); //for a spaceship in a 'good' state
    //colors for enemies
}

cmain::~cmain()
{
    keypad(stdscr, false);
    endwin();
}

void cmain::menu()
{
    clear();

    attron(A_BOLD);
    mvprintw(rows / 2 - 3, 10, "Project_X");
    attroff(A_BOLD);
    mvprintw(rows / 2 - 1, 10, "Press '1' to start");
    mvprintw(rows / 2, 10, "Press '2' to learn control");
    mvprintw(rows / 2+1, 10, "Press '3' to see scoreboard //COMING SOON");
    mvprintw(rows / 2+2, 10, "Press '4' to exit");

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

void cmain::game()
{
    //maybe its worth to generate stars or smth like that
    player main_character(columns / 2, rows - 5);
    bool checker = true;
    int button_check;
    nodelay(stdscr, true);
    while(checker)
    {
        clear();
        main_character.draw();

        //a 97 //s 115 //d 100 //w 119 //space 32
        switch(button_check = getch())
        {
        case 97:
            main_character.set_place_x(main_character.get_place_x() - 1);
            break;
        case 115:
            main_character.set_place_y(main_character.get_place_y() + 1);
            break;
        case 100:
            main_character.set_place_x(main_character.get_place_x() + 1);
            break;
        case 119:
            main_character.set_place_y(main_character.get_place_y() - 1);
            break;
        case 32:
            break;
        case 52:
            checker = false;
            break;
        }

        refresh();
    }
    nodelay(stdscr, false);
}

void cmain::help()
{
    clear();

    attron(A_BOLD);
    mvprintw(rows / 2 - 3, 10, "Help");
    attroff(A_BOLD);
    mvprintw(rows / 2 - 1, 10, "Use 'WASD' buttons to move your spaceship");
    mvprintw(rows / 2 + 1, 10, "To return to the menu press '4'");

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
    if ((button = getch()) == 52) menu();
}

void cmain::mainloop()
{
    bool checker = true;
    while(checker)
    {
        menu();

        //button = getch();
        //mvprintw(3,3,"%d\t%c", button, button);

        switch(button = getch())
        {
        case 49:
            game();
            break;
        case 50:
            help();
            break;
        case 51:
            //TODO scoreboard()
            break;
        case 52:
            checker = false;
            break;
        }
    }
}
