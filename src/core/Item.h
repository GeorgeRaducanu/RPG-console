#pragma once

class Item
{
public:
    virtual ~Item() = default;
    virtual const char* getName() const = 0;
};
