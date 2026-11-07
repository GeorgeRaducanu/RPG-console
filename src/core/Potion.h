#pragma once

#include "core/Item.h"

class Potion : public Item
{
public:
    const char* getName() const override;
};
