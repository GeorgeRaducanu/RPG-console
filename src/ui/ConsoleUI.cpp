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

void ConsoleUI::showClassMenu() const
{
    std::cout << "Choose your class:" << '\n'
              << "1) Warrior (HP 120, ATK 15, DEF 8, MP 10)" << '\n'
              << "2) Mage (HP 80, ATK 8, DEF 3, MP 50)" << '\n'
              << "3) Archer (HP 95, ATK 12, DEF 5, MP 20)" << '\n'
              << "Choose:" << '\n';
}

void ConsoleUI::showClassSelected(const char* className) const
{
    std::cout << "You chose " << className << "." << '\n';
}

void ConsoleUI::showExplorationMenu() const
{
    std::cout << "1) Advance" << '\n'
              << "2) Inventory" << '\n'
              << "3) Status" << '\n'
              << "4) Quit" << '\n'
              << "Choose:" << '\n';
}

void ConsoleUI::showRoom(const int room) const
{
    std::cout << "--- Room " << room << "/8 ---" << '\n';
}

void ConsoleUI::showEnemyAppeared(const char* enemy, const int hp) const
{
    std::cout << "A " << enemy << " appears! (HP " << hp << ")" << '\n';
}

void ConsoleUI::showEmptyRoom() const
{
    std::cout << "The room is empty." << '\n';
}

void ConsoleUI::showItemFound(const char* item) const
{
    std::cout << "You found a " << item << "." << '\n';
}

void ConsoleUI::showStatus(
    const char* playerClass,
    const int hp,
    const int maxHp,
    const int mp,
    const int maxMp,
    const int attack,
    const int defense,
    const int xp,
    const int xpNeeded) const
{
    std::cout << "Hero (" << playerClass << ") Lv 1 | HP " << hp << '/'
              << maxHp << " | MP " << mp << '/' << maxMp << " | ATK "
              << attack << " | DEF " << defense << " | XP " << xp << '/'
              << xpNeeded << '\n'
              << "Effects: none" << '\n';
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
