#include "App.h"

#include <string>

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
            ui_.showNotImplemented();
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
