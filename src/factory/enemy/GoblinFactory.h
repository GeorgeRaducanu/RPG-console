#pragma once

#include "factory/enemy/EnemyFactory.h"

class GoblinFactory : public EnemyFactory
{
public:
    std::unique_ptr<Enemy> create() const override;
};
