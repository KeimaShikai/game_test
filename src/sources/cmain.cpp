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
    init_pair(8, COLOR_WHITE, COLOR_WHITE); //for healthbar
    init_pair(9, COLOR_RED, COLOR_RED); //for healthbar
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

    chtype ch;
    ch = '=' | COLOR_PAIR(6) | A_BOLD;
    for (int i = 0; i < columns; ++i)
    {
        move(rows - 2, i);
        addch(ch);
    }

    healthbar health(12, rows - 1);
    scorebar score(columns - 25, rows - 1);

    while(checker)
    {
        //for debug
        // mvprintw(2, 70, "%d", main_character.get_place_x());     //
        // mvprintw(3, 70, "%d", main_character.get_place_y());     //
        // mvprintw(5, 70, "%d", main_character.get_place_old_x()); //
        // mvprintw(6, 70, "%d", main_character.get_place_old_y()); //

        if(enemies.group_collision_chech(main_character.get_place_x(),
                                      main_character.get_place_y()))
        {
            main_character.change_condition(-1);
            health.update(main_character.check_condition());
        }
        if(enemies.group_collision_chech(main_character.get_bullet_place_x(),
                                      main_character.get_bullet_place_y()))
        {
            score.update(1);
        }
        enemies.group_handler();
        main_character.draw();
        main_character.bullet_handler();

        //********************//
        //a 97 //s 115 //d 100 //w 119 //space 32
        //********************//
        //1 360 //2 258 //3 338 //4 260 //5 350
        //6 261 //7 262 //8 259 //9 339
        button_check = getch();
        if(button_check == 97 || button_check == 132 || button_check == 260)
            button_check = left;
        if(button_check == 113 || button_check == 185 || button_check == 262)
            button_check = left_up;
        if(button_check == 119 || button_check == 134 || button_check == 259)
            button_check = up;
        if(button_check == 101 || button_check == 131 || button_check == 339)
            button_check = right_up;
        if(button_check == 100 || button_check == 178 || button_check == 261)
            button_check = right;
        if(button_check == 338)
            button_check = right_down;
        if(button_check == 115 || button_check == 139 || button_check == 258)
            button_check = down;
        if(button_check == 360)
            button_check = left_down;
        if(button_check == 32 || button_check == 350)
            button_check = fire;
        if(button_check == 102 || button_check == 176 || button_check == 331)
            button_check = pause;

        switch(button_check)
        {
        case left_down:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() - 1);
            main_character.set_place_y(main_character.get_place_y() + 1);
            break;
        case down:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_y(main_character.get_place_y() + 1);
            break;
        case right_down:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() + 1);
            main_character.set_place_y(main_character.get_place_y() + 1);
            break;
        case left:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() - 1);
            break;
        case right:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() + 1);
            break;
        case left_up:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() - 1);
            main_character.set_place_y(main_character.get_place_y() - 1);
            break;
        case up:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_y(main_character.get_place_y() - 1);
            break;
        case right_up:
            main_character.set_place_old_x(main_character.get_place_x());
            main_character.set_place_old_y(main_character.get_place_y());
            main_character.set_place_x(main_character.get_place_x() + 1);
            main_character.set_place_y(main_character.get_place_y() - 1);
            break;
        case fire:
            main_character.shot();
            break;
        case pause:
            mvprintw(rows - 1, columns / 2 - 2, "pause");
            while(true)
            {
                button_check = getch();
                if (button_check == 102 || button_check == 176 || button_check == 331) break;
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

        if(main_character.check_condition() == dead)
        {
            mvprintw(rows / 2 - 2, columns / 2 - 4, "GAME OVER");
            mvprintw(rows / 2 + 2, columns / 2 - 8, "To exit press '4'");
            while(true)
            {
                button_check = getch();
                if (button_check == 52) break;
            }
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
    mvprintw(rows / 2 - 1, 10, "There are two types of control setting, that you can use to play this game");
    mvprintw(rows / 2,     10, "You can play using QWEASD to move your spaceship");
    mvprintw(rows / 2 + 1, 10, "Use 'space' to shoot and F to pause the game");
    mvprintw(rows / 2 + 2, 10, "Also you can use numpad to play the game (turn it on with NumLock first!)");
    mvprintw(rows / 2 + 3, 10, "In this case use 1,2,3,4,6,7,8,9 to move spaceship");
    mvprintw(rows / 2 + 4, 10, "Use 5 to shoot and 0 to pause the game");
    mvprintw(rows / 2 + 6, 10, "To return to the menu press any key");

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

        //for button test
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
