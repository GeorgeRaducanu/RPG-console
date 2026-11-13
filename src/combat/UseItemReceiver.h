#pragma once

#include "core/Inventory.h"

class ConsoleUI;

class UseItemReceiver
{
public:
    UseItemReceiver(Inventory& inventory, int& hp, int& maxHp, bool& defeated, ConsoleUI& ui);
    void usePotion();

private:
    Inventory& inventory_;
    int& hp_;
    int& maxHp_;
    bool& defeated_;
    ConsoleUI& ui_;
};
