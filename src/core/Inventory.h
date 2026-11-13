#pragma once

#include <memory>
#include <string>
#include <vector>

#include "core/Item.h"

class Inventory
{
public:
    void add(std::unique_ptr<Item> item);
    void clear();
    bool contains(const char* itemName) const;
    bool removeFirst(const char* itemName);
    std::vector<std::string> getNames() const;

private:
    std::vector<std::unique_ptr<Item>> items_;
};
