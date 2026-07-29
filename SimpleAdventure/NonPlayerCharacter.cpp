#include "NonPlayerCharacter.h"

NonPlayerCharacter::NonPlayerCharacter() : Entity()
{

}

NonPlayerCharacter::NonPlayerCharacter(int maxHP, int maxMP, int maxSP) : Entity(maxHP, maxMP, maxSP)
{

}

int NonPlayerCharacter::takeDamage(int damage, STAT_TYPE type)
{
	int realDamage = this->Entity::takeDamage(damage);
	Console::print("The " 
		+ getName(getNameEnum()) 
		+ " takes " + to_string(realDamage) + " damage\n");
	if (getHP() <= 0)
		die();
	return realDamage;
}

void NonPlayerCharacter::dealDamage(int damage, Entity* target, STAT_TYPE type)
{
	Console::print("The " + getName(getNameEnum()) + " attacks ");
	if (NonPlayerCharacter* temp = dynamic_cast<NonPlayerCharacter*>(target))
		Console::print("the " + temp->getName(getNameEnum()));
	else if (PlayerCharacter* temp = dynamic_cast<PlayerCharacter*>(target))
		Console::print("you");
	target->takeDamage(damage, type);
}

NPC_NAME NonPlayerCharacter::getNameEnum() const
{
	return name;
}

string NonPlayerCharacter::getName(NPC_NAME npc)
{
	switch (npc)
	{
	case DUMMY:
		return "dummy";
	default:
		throw NonPlayerCharacterNotFound();
	}
}