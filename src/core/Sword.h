#pragma once

#include "core/Item.h"

class Sword : public Item
{
public:
    const char* getName() const override;
};
