#pragma once

#include "core/Character.h"

class Warrior : public Character
{
public:
    Class getClass() const override;
    const Stats& getStats() const override;
    const char* getClassName() const override;

private:
    Stats stats_{120, 120, 10, 10, 15, 8};
};
