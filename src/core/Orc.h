#pragma once

#include "core/Enemy.h"

class Orc : public Enemy
{
public:
    const char* getName() const override;
    int getHp() const override;
};
