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

int PlayerCharacter::takeDamage(int damage)
{
	int realDamage = this->Entity::takeDamage(damage);
	if (damage >= 0)
		experience += realDamage;
	return realDamage;
}

void PlayerCharacter::dealDamage(int damage, Entity* target)
{
	int realDamage = target->takeDamage(damage);
	if (damage >= 0)
		experience += realDamage;
}

void PlayerCharacter::heal(int amount)
{
	Entity::heal(amount);
}

void PlayerCharacter::inflict(Effect* effect)
{
	Entity::inflict(effect);
}

void PlayerCharacter::cure(EFFECT_NAME effectName)
{
	Entity::cure(effectName);
}

void PlayerCharacter::cleanse()
{
	Entity::cleanse();
}

void PlayerCharacter::dispel()
{
	Entity::dispel();
}

void PlayerCharacter::clear()
{
	Entity::clear();
}

void PlayerCharacter::die()
{
	cout << "game over";
}