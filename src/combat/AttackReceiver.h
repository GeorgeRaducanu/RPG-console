#pragma once

#include <memory>

class AttackStrategy;
class Character;
class ConsoleUI;
class Enemy;

class AttackReceiver
{
public:
    AttackReceiver(
        std::unique_ptr<Enemy>& enemy,
        std::unique_ptr<Character>& character,
        std::unique_ptr<AttackStrategy>& strategy,
        int& hp,
        bool& defeated,
        ConsoleUI& ui);

    void attack();

private:
    std::unique_ptr<Enemy>& enemy_;
    std::unique_ptr<Character>& character_;
    std::unique_ptr<AttackStrategy>& strategy_;
    int& hp_;
    bool& defeated_;
    ConsoleUI& ui_;
};
