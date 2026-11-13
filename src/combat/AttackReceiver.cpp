#include "combat/AttackReceiver.h"

#include "combat/AttackStrategy.h"
#include "core/Character.h"
#include "core/Enemy.h"
#include "ui/ConsoleUI.h"

AttackReceiver::AttackReceiver(
    std::unique_ptr<Enemy>& enemy,
    std::unique_ptr<Character>& character,
    std::unique_ptr<AttackStrategy>& strategy,
    int& hp,
    bool& defeated,
    ConsoleUI& ui)
    : enemy_(enemy),
      character_(character),
      strategy_(strategy),
      hp_(hp),
      defeated_(defeated),
      ui_(ui)
{
}

void AttackReceiver::attack()
{
    if (defeated_)
    {
        ui_.showPlayerDefeated();
        return;
    }

    if (!enemy_ || !enemy_->isAlive())
    {
        ui_.showNoEnemy();
        return;
    }

    const int damage = strategy_->calculateDamage(character_->getStats());
    enemy_->takeDamage(damage);
    ui_.showAttack(enemy_->getName(), damage, enemy_->getHp());
    if (!enemy_->isAlive())
    {
        ui_.showEnemyDefeated(enemy_->getName());
        enemy_.reset();
        return;
    }

    hp_ -= enemy_->getAttack();
    if (hp_ < 0)
    {
        hp_ = 0;
    }
    ui_.showEnemyAttack(enemy_->getName(), enemy_->getAttack(), hp_);
    if (hp_ == 0)
    {
        defeated_ = true;
        ui_.showPlayerDefeated();
    }
}
