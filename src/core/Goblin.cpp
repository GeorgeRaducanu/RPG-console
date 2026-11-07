#include "core/Goblin.h"

const char* Goblin::getName() const
{
    return "Goblin";
}

int Goblin::getHp() const
{
    return hp_;
}

void Goblin::takeDamage(const int damage)
{
    hp_ -= damage;
    if (hp_ < 0)
    {
        hp_ = 0;
    }
}

bool Goblin::isAlive() const
{
    return hp_ > 0;
}
