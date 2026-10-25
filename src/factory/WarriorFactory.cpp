#include "factory/WarriorFactory.h"

#include "core/Warrior.h"

std::unique_ptr<Character> WarriorFactory::create() const
{
    return std::make_unique<Warrior>();
}
