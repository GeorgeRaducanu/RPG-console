#pragma once

#include "combat/Command.h"

class UseItemReceiver;

class UseItemCommand : public Command
{
public:
    explicit UseItemCommand(UseItemReceiver& receiver);
    void execute() override;

private:
    UseItemReceiver& receiver_;
};
