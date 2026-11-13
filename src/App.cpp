#include "App.h"

#include <algorithm>

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
            break;
        case 2:
            playerClass_ = PlayerClass::Mage;
            break;
        case 3:
            playerClass_ = PlayerClass::Archer;
            break;
        }

        const char* className = "";
        switch (playerClass_)
        {
        case PlayerClass::Warrior:
            className = "Warrior";
            hp_ = maxHp_ = 120;
            break;
        case PlayerClass::Mage:
            className = "Mage";
            hp_ = maxHp_ = 80;
            break;
        case PlayerClass::Archer:
            className = "Archer";
            hp_ = maxHp_ = 95;
            break;
        }

        room_ = 0;
        inventory_.clear();
        enemyName_ = nullptr;
        enemyHp_ = 0;
        enemyAttack_ = 0;
        defeated_ = false;
        ui_.showClassSelected(className);
        return true;
    }
}

bool App::runExploration()
{
    while (true)
    {
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

        if (choice == 4)
        {
            return true;
        }

        if (choice == 1)
        {
            advanceRoom();
            continue;
        }

        if (choice == 2)
        {
            showInventory();
            continue;
        }

        if (choice == 3)
        {
            showStatus();
            continue;
        }

        if (choice == 5)
        {
            attackEnemy();
            continue;
        }

        if (choice == 6)
        {
            useItem();
            continue;
        }

        ui_.showInvalidChoice();
    }
}

void App::advanceRoom()
{
    if (room_ >= totalRooms_)
    {
        return;
    }

    ++room_;
    enemyName_ = nullptr;
    enemyHp_ = 0;
    ui_.showRoom(room_);

    switch (room_)
    {
    case 1:
        enemyName_ = "Goblin";
        enemyHp_ = 40;
        enemyAttack_ = 5;
        ui_.showEnemyAppeared("Goblin", 40);
        break;
    case 2:
        ui_.showEmptyRoom();
        break;
    case 3:
        inventory_.push_back("Potion");
        ui_.showItemFound("Potion");
        break;
    case 4:
        enemyName_ = "Orc";
        enemyHp_ = 80;
        enemyAttack_ = 8;
        ui_.showEnemyAppeared("Orc", 80);
        break;
    case 5:
        inventory_.push_back("Sword");
        ui_.showItemFound("Sword");
        break;
    case 6:
        ui_.showEmptyRoom();
        break;
    case 7:
        inventory_.push_back("Elixir");
        ui_.showItemFound("Elixir");
        break;
    case 8:
        enemyName_ = "Dragon";
        enemyHp_ = 120;
        enemyAttack_ = 12;
        ui_.showEnemyAppeared("Dragon", 120);
        break;
    }
}

void App::showInventory() const
{
    ui_.showInventory(inventory_);
}

void App::attackEnemy()
{
    if (defeated_)
    {
        ui_.showPlayerDefeated();
        return;
    }

    if (enemyName_ == nullptr || enemyHp_ <= 0)
    {
        ui_.showNoEnemy();
        return;
    }

    int damage = 0;
    switch (playerClass_)
    {
    case PlayerClass::Warrior:
        damage = 15;
        break;
    case PlayerClass::Mage:
        damage = 10;
        break;
    case PlayerClass::Archer:
        damage = 13;
        break;
    }

    enemyHp_ -= damage;
    if (enemyHp_ < 0)
    {
        enemyHp_ = 0;
    }
    ui_.showAttack(enemyName_, damage, enemyHp_);
    if (enemyHp_ <= 0)
    {
        ui_.showEnemyDefeated(enemyName_);
        enemyName_ = nullptr;
        enemyAttack_ = 0;
        return;
    }

    hp_ -= enemyAttack_;
    if (hp_ < 0)
    {
        hp_ = 0;
    }
    ui_.showEnemyAttack(enemyName_, enemyAttack_, hp_);
    if (hp_ == 0)
    {
        defeated_ = true;
        ui_.showPlayerDefeated();
    }
}

void App::useItem()
{
    if (defeated_)
    {
        ui_.showPlayerDefeated();
        return;
    }

    auto potion = std::find(inventory_.begin(), inventory_.end(), "Potion");
    if (potion == inventory_.end())
    {
        ui_.showNoItem("Potion");
        return;
    }
    if (hp_ == maxHp_)
    {
        ui_.showItemAtFullHealth();
        return;
    }

    const int oldHp = hp_;
    hp_ = std::min(maxHp_, hp_ + 30);
    inventory_.erase(potion);
    ui_.showItemUsed("Potion", hp_ - oldHp, hp_);
}

void App::showStatus() const
{
    switch (playerClass_)
    {
    case PlayerClass::Warrior:
        ui_.showStatus("Warrior", hp_, 120, 10, 10, 15, 8, 0, 50);
        break;
    case PlayerClass::Mage:
        ui_.showStatus("Mage", hp_, 80, 50, 50, 8, 3, 0, 50);
        break;
    case PlayerClass::Archer:
        ui_.showStatus("Archer", hp_, 95, 20, 20, 12, 5, 0, 50);
        break;
    }
}
