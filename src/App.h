#pragma once

#include <iosfwd>

#include "core/Character.h"
#include "ui/ConsoleUI.h"

class App
{
public:
    App(std::istream& input, std::ostream& output);
    int run();

private:
    bool chooseClass();
    bool runExploration();
    void showStatus() const;

    Character character_;
    ConsoleUI ui_;
};
