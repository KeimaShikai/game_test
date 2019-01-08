#include "factory_enemy.h"

factory_enemy::factory_enemy()
{
    for (int i = 0; i < 5; ++i)
    {
        enemy sample(0, 0, 'T', 5);
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
