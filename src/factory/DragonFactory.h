#pragma once

#include "factory/EnemyFactory.h"

class DragonFactory : public EnemyFactory
{
public:
    std::unique_ptr<Enemy> create() const override;
};
