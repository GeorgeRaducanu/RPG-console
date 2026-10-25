#pragma once

#include <iosfwd>

#include "ui/ConsoleUI.h"

class App
{
public:
    App(std::istream& input, std::ostream& output);
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

    PlayerClass playerClass_ = PlayerClass::Warrior;
    ConsoleUI ui_;
};
