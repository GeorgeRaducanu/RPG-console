#include "core/Character.h"

Character::Character() = default;

void Character::setClass(const Class characterClass)
{
    class_ = characterClass;

    switch (class_)
    {
    case Class::Warrior:
        stats_ = {120, 120, 10, 10, 15, 8};
        break;
    case Class::Mage:
        stats_ = {80, 80, 50, 50, 8, 3};
        break;
    case Class::Archer:
        stats_ = {95, 95, 20, 20, 12, 5};
        break;
    }
}

Character::Class Character::getClass() const
{
    return class_;
}

const Stats& Character::getStats() const
{
    return stats_;
}

const char* Character::getClassName() const
{
    switch (class_)
    {
    case Class::Warrior:
        return "Warrior";
    case Class::Mage:
        return "Mage";
    case Class::Archer:
        return "Archer";
    }

    return "";
}
