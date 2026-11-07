#pragma once

#include <memory>

#include "core/Enemy.h"

class EnemyFactory
{
public:
    virtual ~EnemyFactory() = default;
    virtual std::unique_ptr<Enemy> create() const = 0;
};
