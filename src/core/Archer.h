#pragma once

#include "core/Character.h"

class Archer : public Character
{
public:
    Class getClass() const override;
    const Stats& getStats() const override;
    const char* getClassName() const override;

private:
    Stats stats_{95, 95, 20, 20, 12, 5};
};
