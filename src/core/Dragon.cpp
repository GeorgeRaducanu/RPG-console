#include "core/Dragon.h"

const char* Dragon::getName() const
{
    return "Dragon";
}

int Dragon::getHp() const
{
    return hp_;
}

void Dragon::takeDamage(const int damage)
{
    hp_ -= damage;
    if (hp_ < 0)
    {
        hp_ = 0;
    }
}

bool Dragon::isAlive() const
{
    return hp_ > 0;
}
