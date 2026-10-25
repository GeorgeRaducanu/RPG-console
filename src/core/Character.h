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

    virtual ~Character() = default;
    virtual Class getClass() const = 0;
    virtual const Stats& getStats() const = 0;
    virtual const char* getClassName() const = 0;
};
