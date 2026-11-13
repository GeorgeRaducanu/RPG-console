#include "core/Inventory.h"

#include <algorithm>
#include <cstring>

void Inventory::add(std::unique_ptr<Item> item)
{
    items_.push_back(std::move(item));
}

void Inventory::clear()
{
    items_.clear();
}

bool Inventory::removeFirst(const char* itemName)
{
    const auto item = std::find_if(
        items_.begin(),
        items_.end(),
        [itemName](const std::unique_ptr<Item>& value)
        {
            return std::strcmp(value->getName(), itemName) == 0;
        });
    if (item == items_.end())
    {
        return false;
    }

    items_.erase(item);
    return true;
}

bool Inventory::contains(const char* itemName) const
{
    return std::any_of(
        items_.begin(),
        items_.end(),
        [itemName](const std::unique_ptr<Item>& value)
        {
            return std::strcmp(value->getName(), itemName) == 0;
        });
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
