#include "factory/OrcFactory.h"

#include "core/Orc.h"

std::unique_ptr<Enemy> OrcFactory::create() const
{
    return std::make_unique<Orc>();
}
