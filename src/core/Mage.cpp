#include "core/Mage.h"

Character::Class Mage::getClass() const
{
    return Class::Mage;
}

const Stats& Mage::getStats() const
{
    return stats_;
}

const char* Mage::getClassName() const
{
    return "Mage";
}
