#include "combat/MeleeAttackStrategy.h"

int MeleeAttackStrategy::calculateDamage(const Stats& stats) const
{
    return stats.attack;
}
