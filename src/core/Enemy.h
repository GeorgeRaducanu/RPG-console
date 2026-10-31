#pragma once

class Enemy
{
public:
    virtual ~Enemy() = default;
    virtual const char* getName() const = 0;
    virtual int getHp() const = 0;
};
