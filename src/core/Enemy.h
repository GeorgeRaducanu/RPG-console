#pragma once

class Enemy
{
public:
    virtual ~Enemy() = default;
    virtual const char* getName() const = 0;
    virtual int getHp() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual bool isAlive() const = 0;
};
