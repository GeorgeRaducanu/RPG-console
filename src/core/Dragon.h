#pragma once

#include "core/Enemy.h"

class Dragon : public Enemy
{
public:
    const char* getName() const override;
    int getHp() const override;
};
