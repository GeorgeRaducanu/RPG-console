#include "combat/RangedAttackStrategy.h"

int RangedAttackStrategy::calculateDamage(const Stats& stats) const
{
    return stats.attack + 1;
}
