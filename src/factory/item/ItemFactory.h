#pragma once

#include <memory>

#include "core/Item.h"

class ItemFactory
{
public:
    virtual ~ItemFactory() = default;
    virtual std::unique_ptr<Item> create() const = 0;
};
