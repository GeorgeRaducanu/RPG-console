#include "factory/item/ElixirFactory.h"

#include "core/Elixir.h"

std::unique_ptr<Item> ElixirFactory::create() const
{
    return std::make_unique<Elixir>();
}
