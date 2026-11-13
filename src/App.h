#pragma once

#include <string>
#include <vector>

#include "ui/ConsoleUI.h"

class App
{
public:
    int run();

private:
    static constexpr int totalRooms_ = 8;

    enum class PlayerClass
    {
        Warrior,
        Mage,
        Archer
    };

    bool chooseClass();
    bool runExploration();
    void showStatus() const;
    void showInventory() const;
    void attackEnemy();
    void useItem();
    void advanceRoom();

    PlayerClass playerClass_ = PlayerClass::Warrior;
    int room_ = 0;
    std::vector<std::string> inventory_;
    const char* enemyName_ = nullptr;
    int enemyHp_ = 0;
    int enemyAttack_ = 0;
    int hp_ = 0;
    int maxHp_ = 0;
    bool defeated_ = false;
    ConsoleUI ui_;
};
