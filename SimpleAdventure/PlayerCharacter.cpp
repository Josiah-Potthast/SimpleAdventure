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
		expNeeded *= levelScaling;

	experience += exp;
	if (experience >= expNeeded)
	{
		experience -= expNeeded;
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
	// display a menu to get choice of increasing hp, mp, or sp
	// gain class level

	// Full heal
	setHP(getMaxHP());
	setMP(getMaxMP());
	setSP(getMaxSP());
}

void PlayerCharacter::die()
{
	cout << "game over";
}