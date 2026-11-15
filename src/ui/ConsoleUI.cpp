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
              << "5) Attack" << '\n'
              << "6) Use Item" << '\n'
              << "7) Flee" << '\n'
              << "Choose:" << '\n';
}

void ConsoleUI::showNoEnemy() const
{
    std::cout << "There is no enemy here." << '\n';
}

void ConsoleUI::showEnemyBlocksPath(const char* enemy) const
{
    std::cout << "The " << enemy << " blocks your way. Defeat it first." << '\n';
}

void ConsoleUI::showAttack(
    const char* enemy,
    const int damage,
    const int remainingHp) const
{
    std::cout << "You attack the " << enemy << " for " << damage
              << " damage. (HP " << remainingHp << ")" << '\n';
}

void ConsoleUI::showEnemyDefeated(const char* enemy) const
{
    std::cout << enemy << " defeated!" << '\n';
}

void ConsoleUI::showEnemyAttack(const char* enemy, const int damage, const int remainingHp) const
{
    std::cout << "The " << enemy << " hits you for " << damage
              << " damage. (HP " << remainingHp << ")" << '\n';
}

void ConsoleUI::showPlayerDefeated() const
{
    std::cout << "You were defeated." << '\n';
}

void ConsoleUI::showFled(const char* enemy) const
{
    std::cout << "You flee from the " << enemy << "." << '\n';
}

void ConsoleUI::showCannotFlee(const char* enemy) const
{
    std::cout << "You cannot flee from the " << enemy << "!" << '\n';
}

void ConsoleUI::showXpGained(const int amount, const int xp, const int xpNeeded) const
{
    std::cout << "You gained " << amount << " XP. (XP " << xp << '/'
              << xpNeeded << ")" << '\n';
}

void ConsoleUI::showLevelUp(
    const int level,
    const int maxHp,
    const int attack,
    const int defense) const
{
    std::cout << "Level up! You are now Lv " << level << ". (Max HP "
              << maxHp << " | ATK " << attack << " | DEF " << defense << ")"
              << '\n';
}

void ConsoleUI::showVictory() const
{
    std::cout << "=== VICTORY ===" << '\n'
              << "The Dragon is slain. You escape the Dungeon of Echoes!"
              << '\n';
}

void ConsoleUI::showGameOver() const
{
    std::cout << "=== GAME OVER ===" << '\n'
              << "You were defeated. The dungeon claims another hero."
              << '\n';
}

void ConsoleUI::showItemMenu(const std::vector<std::string>& items) const
{
    std::cout << "Use which item?" << '\n';
    for (std::size_t i = 0; i < items.size(); ++i)
    {
        std::cout << i + 1 << ") " << items[i] << '\n';
    }
    std::cout << "0) Cancel" << '\n'
              << "Choose:" << '\n';
}

void ConsoleUI::showNoItem(const char* item) const
{
    std::cout << "You have no " << item << "." << '\n';
}

void ConsoleUI::showUnknownItem(const char* item) const
{
    std::cout << "You don't know how to use the " << item << "." << '\n';
}

void ConsoleUI::showItemAtFullHealth() const
{
    std::cout << "You are already at full HP." << '\n';
}

void ConsoleUI::showItemUsed(const char* item, const int healed, const int hp) const
{
    std::cout << "You used a " << item << " and restored " << healed
              << " HP. (HP " << hp << ")" << '\n';
}

void ConsoleUI::showSwordEquipped(const int bonus, const int attack) const
{
    std::cout << "You equip the Sword. ATK +" << bonus << " permanently. (ATK "
              << attack << ")" << '\n';
}

void ConsoleUI::showElixirUsed(const int bonus, const int turns) const
{
    std::cout << "You drink the Elixir. ATK +" << bonus << " for the next "
              << turns << " attacks." << '\n';
}

void ConsoleUI::showElixirAlreadyActive() const
{
    std::cout << "An Elixir is already active." << '\n';
}

void ConsoleUI::showElixirExpired() const
{
    std::cout << "The Elixir's effect fades." << '\n';
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

void ConsoleUI::showInventory(const std::vector<std::string>& items) const
{
    std::cout << "Inventory:" << '\n';
    if (items.empty())
    {
        std::cout << "  (empty)" << '\n';
        return;
    }

    for (const std::string& item : items)
    {
        std::cout << "- " << item << '\n';
    }
}

void ConsoleUI::showStatus(
    const char* playerClass,
    const int level,
    const int hp,
    const int maxHp,
    const int mp,
    const int maxMp,
    const int attack,
    const int defense,
    const int xp,
    const int xpNeeded,
    const int elixirTurns) const
{
    std::cout << "Hero (" << playerClass << ") Lv " << level << " | HP " << hp
              << '/' << maxHp << " | MP " << mp << '/' << maxMp << " | ATK "
              << attack << " | DEF " << defense << " | XP " << xp << '/'
              << xpNeeded << '\n';

    if (elixirTurns > 0)
    {
        std::cout << "Effects: Elixir (" << elixirTurns << " attacks left)"
                  << '\n';
    }
    else
    {
        std::cout << "Effects: none" << '\n';
    }
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
