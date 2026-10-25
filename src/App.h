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
    bool runExploration();
    void showStatus() const;

    PlayerClass playerClass_ = PlayerClass::Warrior;
    ConsoleUI ui_;
};
