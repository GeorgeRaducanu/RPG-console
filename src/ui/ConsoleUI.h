#pragma once

class ConsoleUI
{
public:
    enum class InputResult
    {
        Valid,
        Invalid,
        EndOfInput
    };

    void showTitle() const;
    void showMainMenu() const;
    void showNotImplemented() const;
    void showInvalidChoice() const;
    void showInputEnded() const;
    InputResult readChoice(int& choice) const;
};
