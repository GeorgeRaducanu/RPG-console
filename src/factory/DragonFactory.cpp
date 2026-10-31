#include "factory/DragonFactory.h"

#include "core/Dragon.h"

std::unique_ptr<Enemy> DragonFactory::create() const
{
    return std::make_unique<Dragon>();
}
