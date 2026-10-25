#include "core/Archer.h"

Character::Class Archer::getClass() const
{
    return Class::Archer;
}

const Stats& Archer::getStats() const
{
    return stats_;
}

const char* Archer::getClassName() const
{
    return "Archer";
}
