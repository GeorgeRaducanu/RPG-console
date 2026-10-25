#pragma once

#include <memory>
#include <iosfwd>

#include "core/Character.h"
#include "factory/CharacterFactory.h"
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

    std::unique_ptr<CharacterFactory> characterFactory_;
    std::unique_ptr<Character> character_;
    ConsoleUI ui_;
};
