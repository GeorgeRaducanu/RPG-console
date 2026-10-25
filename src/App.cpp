#include "App.h"

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
            character_.setClass(Character::Class::Warrior);
            break;
        case 2:
            character_.setClass(Character::Class::Mage);
            break;
        case 3:
            character_.setClass(Character::Class::Archer);
            break;
        }

        ui_.showClassSelected(character_.getClassName());
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

        if (choice == 1 || choice == 2)
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

void App::showStatus() const
{
    const Stats& stats = character_.getStats();
    ui_.showStatus(
        character_.getClassName(),
        stats.hp,
        stats.maxHp,
        stats.mp,
        stats.maxMp,
        stats.attack,
        stats.defense,
        0,
        50);
}
