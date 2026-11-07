#include "combat/MagicAttackStrategy.h"

int MagicAttackStrategy::calculateDamage(const Stats& stats) const
{
    return stats.attack + 2;
}
