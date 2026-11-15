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
    static constexpr int potionHeal_ = 30;
    static constexpr int swordAttackBonus_ = 5;
    static constexpr int elixirAttackBonus_ = 5;
    static constexpr int elixirDuration_ = 3;
    static constexpr int baseXpNeeded_ = 50;

    enum class PlayerClass
    {
        Warrior,
        Mage,
        Archer
    };

    enum class GameState
    {
        Playing,
        Won,
        Lost
    };

    bool chooseClass();
    bool runExploration();
    void showStatus() const;
    void showInventory() const;
    void attackEnemy();
    void fleeEnemy();
    bool useItem();
    void useItemByName(const std::string& item);
    void advanceRoom();
    void spawnEnemy(const char* name, int hp, int attack, int defense, int xp);
    void clearEnemy();
    void gainXp(int amount);
    int currentAttack() const;
    int xpNeeded() const;
    const char* className() const;

    PlayerClass playerClass_ = PlayerClass::Warrior;
    GameState state_ = GameState::Playing;
    int room_ = 0;
    std::vector<std::string> inventory_;
    const char* enemyName_ = nullptr;
    int enemyHp_ = 0;
    int enemyAttack_ = 0;
    int enemyDefense_ = 0;
    int enemyXp_ = 0;
    int hp_ = 0;
    int maxHp_ = 0;
    int mp_ = 0;
    int maxMp_ = 0;
    int atk_ = 0;
    int def_ = 0;
    int level_ = 1;
    int xp_ = 0;
    int elixirTurns_ = 0;
    ConsoleUI ui_;
};
