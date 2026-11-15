#include "App.h"

#include <algorithm>

namespace
{
int calculateDamage(const int attack, const int defense)
{
    return std::max(1, attack - defense);
}
}

int App::run()
{
    ui_.showTitle();

    while (true)
    {
        ui_.showMainMenu();

        int choice = 0;
        const ConsoleUI::InputResult result = ui_.readChoice(choice);
        if (result == ConsoleUI::InputResult::EndOfInput)
        {
            ui_.showInputEnded();
            return 0;
        }
        if (result == ConsoleUI::InputResult::Invalid)
        {
            ui_.showInvalidChoice();
            continue;
        }

        if (choice == 1)
        {
            if (!chooseClass())
            {
                return 0;
            }
            if (!runExploration())
            {
                return 0;
            }
        }
        else if (choice == 2)
        {
            return 0;
        }
        else
        {
            ui_.showInvalidChoice();
        }
    }
}

bool App::chooseClass()
{
    while (true)
    {
        ui_.showClassMenu();

        int choice = 0;
        const ConsoleUI::InputResult result = ui_.readChoice(choice);
        if (result == ConsoleUI::InputResult::EndOfInput)
        {
            ui_.showInputEnded();
            return false;
        }

        if (result == ConsoleUI::InputResult::Invalid ||
            choice < 1 || choice > 3)
        {
            ui_.showInvalidChoice();
            continue;
        }

        switch (choice)
        {
        case 1:
            playerClass_ = PlayerClass::Warrior;
            hp_ = maxHp_ = 120;
            mp_ = maxMp_ = 10;
            atk_ = 15;
            def_ = 8;
            break;
        case 2:
            playerClass_ = PlayerClass::Mage;
            hp_ = maxHp_ = 80;
            mp_ = maxMp_ = 50;
            atk_ = 8;
            def_ = 3;
            break;
        case 3:
            playerClass_ = PlayerClass::Archer;
            hp_ = maxHp_ = 95;
            mp_ = maxMp_ = 20;
            atk_ = 12;
            def_ = 5;
            break;
        }

        state_ = GameState::Playing;
        room_ = 0;
        level_ = 1;
        xp_ = 0;
        elixirTurns_ = 0;
        inventory_.clear();
        clearEnemy();
        ui_.showClassSelected(className());
        return true;
    }
}

bool App::runExploration()
{
    while (true)
    {
        if (state_ == GameState::Won)
        {
            ui_.showVictory();
            return true;
        }
        if (state_ == GameState::Lost)
        {
            ui_.showGameOver();
            return true;
        }

        ui_.showExplorationMenu();

        int choice = 0;
        const ConsoleUI::InputResult result = ui_.readChoice(choice);
        if (result == ConsoleUI::InputResult::EndOfInput)
        {
            ui_.showInputEnded();
            return false;
        }

        if (result == ConsoleUI::InputResult::Invalid)
        {
            ui_.showInvalidChoice();
            continue;
        }

        switch (choice)
        {
        case 1:
            advanceRoom();
            break;
        case 2:
            showInventory();
            break;
        case 3:
            showStatus();
            break;
        case 4:
            return true;
        case 5:
            attackEnemy();
            break;
        case 6:
            if (!useItem())
            {
                ui_.showInputEnded();
                return false;
            }
            break;
        case 7:
            fleeEnemy();
            break;
        default:
            ui_.showInvalidChoice();
            break;
        }
    }
}

void App::advanceRoom()
{
    if (enemyName_ != nullptr && enemyHp_ > 0)
    {
        ui_.showEnemyBlocksPath(enemyName_);
        return;
    }

    if (room_ >= totalRooms_)
    {
        return;
    }

    ++room_;
    clearEnemy();
    ui_.showRoom(room_);

    switch (room_)
    {
    case 1:
        spawnEnemy("Goblin", 40, 5, 1, 20);
        break;
    case 2:
        ui_.showEmptyRoom();
        break;
    case 3:
        inventory_.push_back("Potion");
        ui_.showItemFound("Potion");
        break;
    case 4:
        spawnEnemy("Orc", 80, 8, 2, 35);
        break;
    case 5:
        inventory_.push_back("Sword");
        ui_.showItemFound("Sword");
        break;
    case 6:
        spawnEnemy("Goblin", 40, 5, 1, 20);
        break;
    case 7:
        inventory_.push_back("Elixir");
        ui_.showItemFound("Elixir");
        break;
    case 8:
        spawnEnemy("Dragon", 120, 12, 3, 60);
        break;
    }
}

void App::spawnEnemy(
    const char* name,
    const int hp,
    const int attack,
    const int defense,
    const int xp)
{
    enemyName_ = name;
    enemyHp_ = hp;
    enemyAttack_ = attack;
    enemyDefense_ = defense;
    enemyXp_ = xp;
    ui_.showEnemyAppeared(name, hp);
}

void App::clearEnemy()
{
    enemyName_ = nullptr;
    enemyHp_ = 0;
    enemyAttack_ = 0;
    enemyDefense_ = 0;
    enemyXp_ = 0;
}

void App::showInventory() const
{
    ui_.showInventory(inventory_);
}

int App::currentAttack() const
{
    return elixirTurns_ > 0 ? atk_ + elixirAttackBonus_ : atk_;
}

void App::attackEnemy()
{
    if (enemyName_ == nullptr || enemyHp_ <= 0)
    {
        ui_.showNoEnemy();
        return;
    }

    const int damage = calculateDamage(currentAttack(), enemyDefense_);

    enemyHp_ -= damage;
    if (enemyHp_ < 0)
    {
        enemyHp_ = 0;
    }
    ui_.showAttack(enemyName_, damage, enemyHp_);

    if (elixirTurns_ > 0)
    {
        --elixirTurns_;
        if (elixirTurns_ == 0)
        {
            ui_.showElixirExpired();
        }
    }

    if (enemyHp_ <= 0)
    {
        ui_.showEnemyDefeated(enemyName_);
        const bool wasFinalBoss = room_ == totalRooms_;
        gainXp(enemyXp_);
        clearEnemy();
        if (wasFinalBoss)
        {
            state_ = GameState::Won;
        }
        return;
    }

    const int enemyDamage = calculateDamage(enemyAttack_, def_);
    hp_ -= enemyDamage;
    if (hp_ < 0)
    {
        hp_ = 0;
    }
    ui_.showEnemyAttack(enemyName_, enemyDamage, hp_);
    if (hp_ == 0)
    {
        state_ = GameState::Lost;
    }
}

void App::fleeEnemy()
{
    if (enemyName_ == nullptr || enemyHp_ <= 0)
    {
        ui_.showNoEnemy();
        return;
    }

    if (room_ == totalRooms_)
    {
        ui_.showCannotFlee(enemyName_);
        return;
    }

    ui_.showFled(enemyName_);
    clearEnemy();
}

void App::gainXp(const int amount)
{
    xp_ += amount;
    ui_.showXpGained(amount, xp_, xpNeeded());

    while (xp_ >= xpNeeded())
    {
        xp_ -= xpNeeded();
        ++level_;
        maxHp_ += 10;
        hp_ = std::min(maxHp_, hp_ + 10);
        atk_ += 2;
        def_ += 1;
        ui_.showLevelUp(level_, maxHp_, atk_, def_);
    }
}

int App::xpNeeded() const
{
    return baseXpNeeded_ * level_;
}

bool App::useItem()
{
    if (inventory_.empty())
    {
        ui_.showInventory(inventory_);
        return true;
    }

    ui_.showItemMenu(inventory_);

    int choice = 0;
    const ConsoleUI::InputResult result = ui_.readChoice(choice);
    if (result == ConsoleUI::InputResult::EndOfInput)
    {
        return false;
    }

    if (result == ConsoleUI::InputResult::Invalid ||
        choice < 0 || choice > static_cast<int>(inventory_.size()))
    {
        ui_.showInvalidChoice();
        return true;
    }

    if (choice == 0)
    {
        return true;
    }

    const std::string item = inventory_[static_cast<std::size_t>(choice - 1)];
    useItemByName(item);
    return true;
}

void App::useItemByName(const std::string& item)
{
    const auto it = std::find(inventory_.begin(), inventory_.end(), item);
    if (it == inventory_.end())
    {
        ui_.showNoItem(item.c_str());
        return;
    }

    if (item == "Potion")
    {
        if (hp_ == maxHp_)
        {
            ui_.showItemAtFullHealth();
            return;
        }
        const int oldHp = hp_;
        hp_ = std::min(maxHp_, hp_ + potionHeal_);
        inventory_.erase(it);
        ui_.showItemUsed("Potion", hp_ - oldHp, hp_);
        return;
    }

    if (item == "Sword")
    {
        atk_ += swordAttackBonus_;
        inventory_.erase(it);
        ui_.showSwordEquipped(swordAttackBonus_, atk_);
        return;
    }

    if (item == "Elixir")
    {
        if (elixirTurns_ > 0)
        {
            ui_.showElixirAlreadyActive();
            return;
        }
        elixirTurns_ = elixirDuration_;
        inventory_.erase(it);
        ui_.showElixirUsed(elixirAttackBonus_, elixirDuration_);
        return;
    }

    ui_.showUnknownItem(item.c_str());
}

const char* App::className() const
{
    switch (playerClass_)
    {
    case PlayerClass::Warrior:
        return "Warrior";
    case PlayerClass::Mage:
        return "Mage";
    case PlayerClass::Archer:
        return "Archer";
    }
    return "";
}

void App::showStatus() const
{
    ui_.showStatus(
        className(),
        level_,
        hp_,
        maxHp_,
        mp_,
        maxMp_,
        currentAttack(),
        def_,
        xp_,
        xpNeeded(),
        elixirTurns_);
}
