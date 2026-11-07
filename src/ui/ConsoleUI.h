#pragma once

#include <string>
#include <vector>

class ConsoleUI
{
public:
    enum class InputResult
    {
        Valid,
        Invalid,
        EndOfInput
    };

    void showTitle() const;
    void showMainMenu() const;
    void showClassMenu() const;
    void showClassSelected(const char* className) const;
    void showExplorationMenu() const;
    void showNoEnemy() const;
    void showAttack(const char* enemy, int damage, int remainingHp) const;
    void showEnemyDefeated(const char* enemy) const;
    void showRoom(int room) const;
    void showEnemyAppeared(const char* enemy, int hp) const;
    void showEmptyRoom() const;
    void showItemFound(const char* item) const;
    void showInventory(const std::vector<std::string>& items) const;
    void showStatus(
        const char* playerClass,
        int hp,
        int maxHp,
        int mp,
        int maxMp,
        int attack,
        int defense,
        int xp,
        int xpNeeded) const;
    void showInvalidChoice() const;
    void showInputEnded() const;
    InputResult readChoice(int& choice) const;
};
