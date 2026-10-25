#pragma once

#include <memory>

#include "core/Character.h"

class CharacterFactory
{
public:
    virtual ~CharacterFactory() = default;
    virtual std::unique_ptr<Character> create() const = 0;
};
