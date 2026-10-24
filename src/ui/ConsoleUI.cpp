#include "ui/ConsoleUI.h"

#include <iostream>
#include <string>
#include <sstream>

void ConsoleUI::showTitle() const
{
    std::cout << "=== Dungeon of Echoes ===" << '\n';
}

void ConsoleUI::showMainMenu() const
{
    std::cout << "1) New Game" << '\n'
              << "2) Quit" << '\n'
              << "Choose:" << '\n';
}

void ConsoleUI::showNotImplemented() const
{
    std::cout << "New Game is not implemented yet." << '\n';
}

void ConsoleUI::showInvalidChoice() const
{
    std::cout << "Invalid choice." << '\n';
}

void ConsoleUI::showInputEnded() const
{
    std::cout << "Input ended." << '\n';
}

ConsoleUI::InputResult ConsoleUI::readChoice(int& choice) const
{
    std::string line;
    if (!std::getline(std::cin, line))
    {
        return InputResult::EndOfInput;
    }

    std::istringstream input(line);
    char extra = '\0';

    const bool parsedInteger = static_cast<bool>(input >> choice);
    if (!parsedInteger)
    {
        return InputResult::Invalid;
    }

    const bool hasExtraInput = static_cast<bool>(input >> extra);
    if (hasExtraInput)
    {
        return InputResult::Invalid;
    }

    return InputResult::Valid;
}
