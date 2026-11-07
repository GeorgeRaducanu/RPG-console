#pragma once

#include "factory/item/ItemFactory.h"

class ElixirFactory : public ItemFactory
{
public:
    std::unique_ptr<Item> create() const override;
};
