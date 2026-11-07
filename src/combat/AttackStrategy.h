#pragma once

#include "core/Stats.h"

class AttackStrategy
{
public:
    virtual ~AttackStrategy() = default;
    virtual int calculateDamage(const Stats& stats) const = 0;
};
