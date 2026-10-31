#include "App.h"

#include "factory/ArcherFactory.h"
#include "factory/DragonFactory.h"
#include "factory/GoblinFactory.h"
#include "factory/MageFactory.h"
#include "factory/OrcFactory.h"
#include "factory/WarriorFactory.h"

App::App(std::istream& input, std::ostream& output)
    : ui_(input, output)
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
            break;
        case 2:
            characterFactory_ = std::make_unique<MageFactory>();
            break;
        case 3:
            characterFactory_ = std::make_unique<ArcherFactory>();
            break;
        }

        room_ = 0;
        enemy_.reset();
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
            continue;
        }

        if (choice == 3)
        {
            showStatus();
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
        ui_.showItemFound("Potion");
        return;
    case 4:
    {
        OrcFactory factory;
        enemy_ = factory.create();
        break;
    }
    case 5:
        ui_.showItemFound("Sword");
        return;
    case 6:
        ui_.showEmptyRoom();
        return;
    case 7:
        ui_.showItemFound("Elixir");
        return;
    case 8:
    {
        DragonFactory factory;
        enemy_ = factory.create();
        break;
    }
    }

    ui_.showEnemyAppeared(enemy_->getName(), enemy_->getHp());
}

void App::showStatus() const
{
    const Stats& stats = character_->getStats();
    ui_.showStatus(
        character_->getClassName(),
        stats.hp,
        stats.maxHp,
        stats.mp,
        stats.maxMp,
        stats.attack,
        stats.defense,
        0,
        50);
}
