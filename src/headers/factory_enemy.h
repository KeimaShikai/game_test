#include <ncurses.h>
#include <vector>
#include "enemy.h"

#ifndef FACTORYENEMY_H
#define FACTORYENEMY_H

class factory_enemy
{
    private:
        std::vector<enemy> factoryOfEnemies;

    public:
        factory_enemy();
        ~factory_enemy();
        void group_spawn();
        void group_handler();
};

#endif
