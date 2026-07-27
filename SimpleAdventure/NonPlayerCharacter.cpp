#include "NonPlayerCharacter.h"

NonPlayerCharacter::NonPlayerCharacter() : Entity()
{

}

NonPlayerCharacter::NonPlayerCharacter(int maxHP, int maxMP, int maxSP) : Entity(maxHP, maxMP, maxSP)
{

}

NPC_NAME NonPlayerCharacter::getNameEnum() const
{
	return name;
}

string NonPlayerCharacter::getName(NPC_NAME npc)
{
	switch (npc)
	{
	default:
		throw NonPlayerCharacterNotFound();
	}
}