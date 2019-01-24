#include "factory_enemy.h"

factory_enemy::factory_enemy()
{
    for (int i = 0; i < 7; ++i)
    {
        enemy sample(0, 0, 'o', 5);
        factoryOfEnemies.push_back(sample);
    }
}

factory_enemy::~factory_enemy()
{

}

void factory_enemy::group_spawn()
{
    for (std::vector<enemy>::iterator i = factoryOfEnemies.begin(); i != factoryOfEnemies.end(); ++i)
        i->spawn();
}

void factory_enemy::group_handler()
{
    for (std::vector<enemy>::iterator i = factoryOfEnemies.begin(); i != factoryOfEnemies.end(); ++i)
        i->shift();
}

bool factory_enemy::group_collision_chech(int iX, int iY)
{
    for (std::vector<enemy>::iterator i = factoryOfEnemies.begin(); i != factoryOfEnemies.end(); ++i)
        if(i->isCollide(iX, iY))
            return true;
    return false;
}
