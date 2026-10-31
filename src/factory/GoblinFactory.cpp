#include "factory/GoblinFactory.h"

#include "core/Goblin.h"

std::unique_ptr<Enemy> GoblinFactory::create() const
{
    return std::make_unique<Goblin>();
}
