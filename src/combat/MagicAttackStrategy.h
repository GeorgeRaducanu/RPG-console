#pragma once

#include "combat/AttackStrategy.h"

class MagicAttackStrategy : public AttackStrategy
{
public:
    int calculateDamage(const Stats& stats) const override;
};
