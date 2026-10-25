#pragma once

#include "core/Character.h"

class Mage : public Character
{
public:
    Class getClass() const override;
    const Stats& getStats() const override;
    const char* getClassName() const override;

private:
    Stats stats_{80, 80, 50, 50, 8, 3};
};
