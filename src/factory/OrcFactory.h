#pragma once

#include "factory/EnemyFactory.h"

class OrcFactory : public EnemyFactory
{
public:
    std::unique_ptr<Enemy> create() const override;
};
