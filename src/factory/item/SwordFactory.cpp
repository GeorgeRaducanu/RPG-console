#include "factory/item/SwordFactory.h"

#include "core/Sword.h"

std::unique_ptr<Item> SwordFactory::create() const
{
    return std::make_unique<Sword>();
}
