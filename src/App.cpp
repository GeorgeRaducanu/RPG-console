#include "App.h"

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
            break;
        case PlayerClass::Mage:
            className = "Mage";
            break;
        case PlayerClass::Archer:
            className = "Archer";
            break;
        }

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
    switch (playerClass_)
    {
    case PlayerClass::Warrior:
        ui_.showStatus("Warrior", 120, 120, 10, 10, 15, 8, 0, 50);
        break;
    case PlayerClass::Mage:
        ui_.showStatus("Mage", 80, 80, 50, 50, 8, 3, 0, 50);
        break;
    case PlayerClass::Archer:
        ui_.showStatus("Archer", 95, 95, 20, 20, 12, 5, 0, 50);
        break;
    }
}
