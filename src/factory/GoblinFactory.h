#pragma once

#include "factory/EnemyFactory.h"

class GoblinFactory : public EnemyFactory
{
public:
    std::unique_ptr<Enemy> create() const override;
};
