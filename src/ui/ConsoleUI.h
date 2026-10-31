#pragma once

#include <iosfwd>

class ConsoleUI
{
public:
    ConsoleUI(std::istream& input, std::ostream& output);

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
    void showRoom(int room) const;
    void showEnemyAppeared(const char* enemy, int hp) const;
    void showEmptyRoom() const;
    void showItemFound(const char* item) const;
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

private:
    std::istream& input_;
    std::ostream& output_;
};
