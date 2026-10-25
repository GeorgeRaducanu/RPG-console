#pragma once

#include <iosfwd>

class ConsoleUI
{
public:
    ConsoleUI(std::istream& input, std::ostream& output);

    enum class InputResult
    {
        Valid,
        Invalid,
        EndOfInput
    };

    void showTitle() const;
    void showMainMenu() const;
    void showClassMenu() const;
    void showClassSelected(const char* className) const;
    void showExplorationMenu() const;
    void showInvalidChoice() const;
    void showInputEnded() const;
    InputResult readChoice(int& choice) const;

private:
    std::istream& input_;
    std::ostream& output_;
};
