#include "core/Warrior.h"

Character::Class Warrior::getClass() const
{
    return Class::Warrior;
}

const Stats& Warrior::getStats() const
{
    return stats_;
}

const char* Warrior::getClassName() const
{
    return "Warrior";
}
