#pragma once

#include "combat/Command.h"

class AttackReceiver;

class AttackCommand : public Command
{
public:
    explicit AttackCommand(AttackReceiver& receiver);
    void execute() override;

private:
    AttackReceiver& receiver_;
};
