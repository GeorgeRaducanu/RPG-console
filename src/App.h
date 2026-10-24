#pragma once

#include "ui/ConsoleUI.h"

class App
{
public:
    int run();

private:
    enum class PlayerClass
    {
        Warrior,
        Mage,
        Archer
    };

    bool chooseClass();

    PlayerClass playerClass_ = PlayerClass::Warrior;
    ConsoleUI ui_;
};
