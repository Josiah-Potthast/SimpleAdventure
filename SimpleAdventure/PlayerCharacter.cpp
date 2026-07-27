#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() : Entity()
{
	experience = 0;
	level = 1;
}

PlayerCharacter::~PlayerCharacter()
{

}

int PlayerCharacter::getExperience() const
{
	return experience;
}

int PlayerCharacter::getLevel() const
{
	return level;
}

void PlayerCharacter::gainExperience(int exp)
{
	double expNeeded = 10;
	for (int i = 1; i < level; i++)
		expNeeded *= EXP_SCALING;

	experience += exp;
	if (experience >= expNeeded)
	{
		loseExperience(expNeeded);
		levelUp();
	}
}

void PlayerCharacter::loseExperience(int exp)
{
	if (exp <= experience)
		experience -= exp;
	else
		experience = 0;
}

void PlayerCharacter::levelUp()
{
	level++;
	// display a menu to get choice of increasing hp, mp, or sp
	// gain class level

	// Full heal
	setHP(getMaxHP());
	setMP(getMaxMP());
	setSP(getMaxSP());
}

int PlayerCharacter::takeDamage(int damage)
{
	int realDamage = this->Entity::takeDamage(damage);
	Console::print("You take " + to_string(realDamage) + " damage\n");
	if (damage >= 0 && getHP() > 0)
		gainExperience(realDamage);
	return realDamage;
}

void PlayerCharacter::dealDamage(int damage, Entity* target)
{
	int realDamage = target->takeDamage(damage);
	Console::print("You deal " + to_string(realDamage) + " damage\n");
	if (damage >= 0)
		gainExperience(realDamage);
}

void PlayerCharacter::heal(int amount)
{
	Entity::heal(amount);
}

void PlayerCharacter::die()
{
	Console::print("You have died\n");
}