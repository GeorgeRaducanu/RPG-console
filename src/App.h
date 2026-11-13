#pragma once

#include <memory>
#include <iosfwd>

#include "core/Character.h"
#include "core/Enemy.h"
#include "core/Inventory.h"
#include "combat/AttackReceiver.h"
#include "combat/Command.h"
#include "combat/AttackStrategy.h"
#include "combat/UseItemReceiver.h"
#include "factory/character/CharacterFactory.h"
#include "ui/ConsoleUI.h"

class App
{
public:
    App(std::istream& input, std::ostream& output);
    int run();

private:
    static constexpr int totalRooms_ = 8;

    bool chooseClass();
    bool runExploration();
    void showStatus() const;
    void showInventory() const;
    void advanceRoom();

    int room_ = 0;
    std::unique_ptr<CharacterFactory> characterFactory_;
    std::unique_ptr<Character> character_;
    std::unique_ptr<Enemy> enemy_;
    std::unique_ptr<AttackStrategy> attackStrategy_;
    Inventory inventory_;
    int hp_ = 0;
    int maxHp_ = 0;
    bool defeated_ = false;
    ConsoleUI ui_;
    AttackReceiver attackReceiver_;
    std::unique_ptr<Command> attackCommand_;
    UseItemReceiver useItemReceiver_;
    std::unique_ptr<Command> useItemCommand_;
};
