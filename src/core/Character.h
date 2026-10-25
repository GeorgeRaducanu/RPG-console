#pragma once

#include "core/Stats.h"

class Character
{
public:
    enum class Class
    {
        Warrior,
        Mage,
        Archer
    };

    Character();

    void setClass(Class characterClass);
    Class getClass() const;
    const Stats& getStats() const;
    const char* getClassName() const;

private:
    Class class_ = Class::Warrior;
    Stats stats_{120, 120, 10, 10, 15, 8};
};
