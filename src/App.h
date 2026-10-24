#pragma once

#include "ui/ConsoleUI.h"

class App
{
public:
    int run();

private:
    bool chooseClass();

    ConsoleUI ui_;
};
