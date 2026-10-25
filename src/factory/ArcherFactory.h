#pragma once

#include "factory/CharacterFactory.h"

class ArcherFactory : public CharacterFactory
{
public:
    std::unique_ptr<Character> create() const override;
};
