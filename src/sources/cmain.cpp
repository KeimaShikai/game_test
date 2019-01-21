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
    //TODO enum for colors
    init_pair(1, COLOR_GREEN, COLOR_GREEN); //for a menu interface
    init_pair(2, COLOR_GREEN, COLOR_BLACK); //for a spaceship in a 'good' condition
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); //for a spaceship in a 'moderate' condition
    init_pair(4, COLOR_RED, COLOR_BLACK); //for a spaceship in a 'bad' condition
    init_pair(5, COLOR_BLUE, COLOR_BLACK); //for enemies
    init_pair(6, COLOR_WHITE, COLOR_BLACK); //for stars
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK); //for shooting
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
    //TODO stars and background
    factory_enemy enemies;
    enemies.group_spawn();
    player main_character(columns / 2, rows - 5, 'A', 2);

    bool checker = true;
    int button_check;
    nodelay(stdscr, true);
    clear();

    while(checker)
    {
        //for debug
        // mvprintw(2, 70, "%d", main_character.get_place_x()); //
        // mvprintw(3, 70, "%d", main_character.get_place_y()); //
        // mvprintw(5, 70, "%d", main_character.get_place_old_x()); //
        // mvprintw(6, 70, "%d", main_character.get_place_old_y()); //

        if(enemies.group_collision_chech(main_character.get_place_x(),
                                      main_character.get_place_y()))
        {
            main_character.change_condition(-1);
        }
        if(enemies.group_collision_chech(main_character.get_bullet_place_x(),
                                      main_character.get_bullet_place_y()));
            //TODO bullet reaction
        enemies.group_handler();
        main_character.draw();
        main_character.bullet_handler();

        //********************//
        //a 97 //s 115 //d 100 //w 119 //space 32
        //********************//
        //1 360 //2 258 //3 338 //4 260 //5 350
        //6 261 //7 262 //8 259 //9 339
        switch(button_check = getch())
        {
        case 360:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() - 1);
            main_character.set_place_y(main_character.get_place_y() + 1);
            break;
        case 258:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_y(main_character.get_place_y() + 1);
            break;
        case 338:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() + 1);
            main_character.set_place_y(main_character.get_place_y() + 1);
            break;
        case 260:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() - 1);
            break;
        case 261:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() + 1);
            break;
        case 262:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() - 1);
            main_character.set_place_y(main_character.get_place_y() - 1);
            break;
        case 259:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_y(main_character.get_place_y() - 1);
            break;
        case 339:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() + 1);
            main_character.set_place_y(main_character.get_place_y() - 1);
            break;
        case 350: 
            main_character.shot();
            break;
        case 331:
            mvprintw(rows - 1, columns / 2 - 2, "pause");
            while(true)
            {
                button_check = getch();
                if (button_check == 331) break;
            }
            mvprintw(rows - 1, columns / 2 - 2, "     ");
            break;
        case 52:
            checker = false;
            break;
        }
        if(main_character.get_place_x() < 1) main_character.set_place_x(1);
        if(main_character.get_place_y() < 1) main_character.set_place_y(1);
        if(main_character.get_place_x() > columns - 2) main_character.set_place_x(columns - 2);
        if(main_character.get_place_y() > rows - 3) main_character.set_place_y(rows - 3);

        if(!main_character.check_condition())
        {
            break;
            //TODO game over
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
    mvprintw(rows / 2 - 1, 10, "Use numpad to play the game (turn it on!)");
    mvprintw(rows / 2,     10, "Use 1,2,3,4,6,7,8,9 to move your spaceship");
    mvprintw(rows / 2 + 1, 10, "Use 5 to shoot");
    mvprintw(rows / 2 + 2, 10, "Use 0 to pause the game");
    mvprintw(rows / 2 + 4, 10, "To return to the menu press '4'");

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

        //button test
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
