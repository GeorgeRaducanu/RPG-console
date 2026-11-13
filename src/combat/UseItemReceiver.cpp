#include "combat/UseItemReceiver.h"

#include <algorithm>

#include "ui/ConsoleUI.h"

UseItemReceiver::UseItemReceiver(
    Inventory& inventory,
    int& hp,
    int& maxHp,
    bool& defeated,
    ConsoleUI& ui)
    : inventory_(inventory),
      hp_(hp),
      maxHp_(maxHp),
      defeated_(defeated),
      ui_(ui)
{
}

void UseItemReceiver::usePotion()
{
    if (defeated_)
    {
        ui_.showPlayerDefeated();
        return;
    }
    if (!inventory_.contains("Potion"))
    {
        ui_.showNoItem("Potion");
        return;
    }
    if (hp_ == maxHp_)
    {
        ui_.showItemAtFullHealth();
        return;
    }

    const int oldHp = hp_;
    hp_ = std::min(maxHp_, hp_ + 30);
    inventory_.removeFirst("Potion");
    ui_.showItemUsed("Potion", hp_ - oldHp, hp_);
}
