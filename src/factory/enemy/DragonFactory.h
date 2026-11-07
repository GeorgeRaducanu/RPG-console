#pragma once

#include "factory/enemy/EnemyFactory.h"

class DragonFactory : public EnemyFactory
{
public:
    std::unique_ptr<Enemy> create() const override;
};
