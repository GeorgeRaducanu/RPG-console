#pragma once

#include "combat/AttackStrategy.h"

class MeleeAttackStrategy : public AttackStrategy
{
public:
    int calculateDamage(const Stats& stats) const override;
};
