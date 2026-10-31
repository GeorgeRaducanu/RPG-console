#pragma once

#include "core/Enemy.h"

class Goblin : public Enemy
{
public:
    const char* getName() const override;
    int getHp() const override;
};
