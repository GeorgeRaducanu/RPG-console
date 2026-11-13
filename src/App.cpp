#include "App.h"

#include "factory/character/ArcherFactory.h"
#include "factory/enemy/DragonFactory.h"
#include "factory/enemy/GoblinFactory.h"
#include "factory/character/MageFactory.h"
#include "factory/enemy/OrcFactory.h"
#include "factory/character/WarriorFactory.h"
#include "factory/item/ElixirFactory.h"
#include "factory/item/PotionFactory.h"
#include "factory/item/SwordFactory.h"
#include "combat/MagicAttackStrategy.h"
#include "combat/MeleeAttackStrategy.h"
#include "combat/RangedAttackStrategy.h"
#include "combat/AttackCommand.h"
#include "combat/UseItemCommand.h"

App::App(std::istream& input, std::ostream& output)
    : ui_(input, output),
      attackReceiver_(enemy_, character_, attackStrategy_, hp_, defeated_, ui_),
      attackCommand_(std::make_unique<AttackCommand>(attackReceiver_)),
      useItemReceiver_(inventory_, hp_, maxHp_, defeated_, ui_),
      useItemCommand_(std::make_unique<UseItemCommand>(useItemReceiver_))
{
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
            characterFactory_ = std::make_unique<WarriorFactory>();
            attackStrategy_ = std::make_unique<MeleeAttackStrategy>();
            maxHp_ = hp_ = 120;
            break;
        case 2:
            characterFactory_ = std::make_unique<MageFactory>();
            attackStrategy_ = std::make_unique<MagicAttackStrategy>();
            maxHp_ = hp_ = 80;
            break;
        case 3:
            characterFactory_ = std::make_unique<ArcherFactory>();
            attackStrategy_ = std::make_unique<RangedAttackStrategy>();
            maxHp_ = hp_ = 95;
            break;
        }

        room_ = 0;
        enemy_.reset();
        inventory_.clear();
        defeated_ = false;
        character_ = characterFactory_->create();
        ui_.showClassSelected(character_->getClassName());
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
            attackCommand_->execute();
            continue;
        }

        if (choice == 6)
        {
            useItemCommand_->execute();
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
    enemy_.reset();
    ui_.showRoom(room_);

    switch (room_)
    {
    case 1:
    {
        GoblinFactory factory;
        enemy_ = factory.create();
        break;
    }
    case 2:
        ui_.showEmptyRoom();
        return;
    case 3:
    {
        PotionFactory factory;
        inventory_.add(factory.create());
        ui_.showItemFound("Potion");
        return;
    }
    case 4:
    {
        OrcFactory factory;
        enemy_ = factory.create();
        break;
    }
    case 5:
    {
        SwordFactory factory;
        inventory_.add(factory.create());
        ui_.showItemFound("Sword");
        return;
    }
    case 6:
        ui_.showEmptyRoom();
        return;
    case 7:
    {
        ElixirFactory factory;
        inventory_.add(factory.create());
        ui_.showItemFound("Elixir");
        return;
    }
    case 8:
    {
        DragonFactory factory;
        enemy_ = factory.create();
        break;
    }
    }

    ui_.showEnemyAppeared(enemy_->getName(), enemy_->getHp());
}

void App::showInventory() const
{
    ui_.showInventory(inventory_.getNames());
}

void App::showStatus() const
{
    const Stats& stats = character_->getStats();
    ui_.showStatus(
        character_->getClassName(),
        hp_,
        stats.maxHp,
        stats.mp,
        stats.maxMp,
        stats.attack,
        stats.defense,
        0,
        50);
}
