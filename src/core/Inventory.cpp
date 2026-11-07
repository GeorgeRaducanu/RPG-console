#include "core/Inventory.h"

void Inventory::add(std::unique_ptr<Item> item)
{
    items_.push_back(std::move(item));
}

void Inventory::clear()
{
    items_.clear();
}

std::vector<std::string> Inventory::getNames() const
{
    std::vector<std::string> names;
    names.reserve(items_.size());

    for (const std::unique_ptr<Item>& item : items_)
    {
        names.emplace_back(item->getName());
    }

    return names;
}
