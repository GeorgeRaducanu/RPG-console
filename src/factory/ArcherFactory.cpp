#include "factory/ArcherFactory.h"

#include "core/Archer.h"

std::unique_ptr<Character> ArcherFactory::create() const
{
    return std::make_unique<Archer>();
}
