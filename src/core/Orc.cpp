#include "core/Orc.h"

const char* Orc::getName() const
{
    return "Orc";
}

int Orc::getHp() const
{
    return hp_;
}

int Orc::getAttack() const
{
    return 8;
}

void Orc::takeDamage(const int damage)
{
    hp_ -= damage;
    if (hp_ < 0)
    {
        hp_ = 0;
    }
}

bool Orc::isAlive() const
{
    return hp_ > 0;
}
