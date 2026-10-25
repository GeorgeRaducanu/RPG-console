#pragma once

#include "factory/CharacterFactory.h"

class MageFactory : public CharacterFactory
{
public:
    std::unique_ptr<Character> create() const override;
};
