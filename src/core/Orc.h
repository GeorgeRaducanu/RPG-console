#pragma once

#include "core/Enemy.h"

class Orc : public Enemy
{
public:
    const char* getName() const override;
    int getHp() const override;
    void takeDamage(int damage) override;
    bool isAlive() const override;

private:
    int hp_ = 80;
};
