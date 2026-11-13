#include "combat/UseItemCommand.h"

#include "combat/UseItemReceiver.h"

UseItemCommand::UseItemCommand(UseItemReceiver& receiver)
    : receiver_(receiver)
{
}

void UseItemCommand::execute()
{
    receiver_.usePotion();
}
