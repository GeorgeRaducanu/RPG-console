#include "factory/item/PotionFactory.h"

#include "core/Potion.h"

std::unique_ptr<Item> PotionFactory::create() const
{
    return std::make_unique<Potion>();
}
