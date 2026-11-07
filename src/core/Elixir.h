#pragma once

#include "core/Item.h"

class Elixir : public Item
{
public:
    const char* getName() const override;
};
