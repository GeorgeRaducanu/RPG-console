#include "combat/AttackCommand.h"

#include "combat/AttackReceiver.h"

AttackCommand::AttackCommand(AttackReceiver& receiver)
    : receiver_(receiver)
{
}

void AttackCommand::execute()
{
    receiver_.attack();
}
