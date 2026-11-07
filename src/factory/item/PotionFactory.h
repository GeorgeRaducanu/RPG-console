#pragma once

#include "factory/item/ItemFactory.h"

class PotionFactory : public ItemFactory
{
public:
    std::unique_ptr<Item> create() const override;
};
