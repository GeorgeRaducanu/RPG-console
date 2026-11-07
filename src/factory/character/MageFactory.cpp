#include "factory/character/MageFactory.h"

#include "core/Mage.h"

std::unique_ptr<Character> MageFactory::create() const
{
    return std::make_unique<Mage>();
}
