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
	double expNeeded = 100;
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
	Console::print("Level Up! You are now level " + to_string(level) + "\n");
	checkStatus();

	int choice = Console::displayMenu(vector<string> 
	{"Increase Max HP", "Increase Max MP", "Increase Max SP"});
	switch (choice)
	{
	case 1:
		setMaxHP(getMaxHP() + STAT_INCREASE);
		break;
	case 2:
		setMaxMP(getMaxMP() + STAT_INCREASE);
		break;
	case 3:
		setMaxSP(getMaxSP() + STAT_INCREASE);
		break;
	default:
		throw LevelUpException();
	}

	// Full heal
	setHP(getMaxHP());
	setMP(getMaxMP());
	setSP(getMaxSP());
}

void PlayerCharacter::checkStatus()
{
	Console::print("HP: " + to_string(getHP()) + "/" + to_string(getMaxHP()) + "\t");
	Console::print("MP: " + to_string(getMP()) + "/" + to_string(getMaxMP()) + "\t");
	Console::print("SP: " + to_string(getSP()) + "/" + to_string(getMaxSP()) + "\n");
}

int PlayerCharacter::takeDamage(int damage, STAT_TYPE type)
{
	int realDamage = this->Entity::takeDamage(damage, type);
	if (type == HEALTH)
		Console::print("You take " + to_string(realDamage) + " damage\n");
	if (damage >= 0 && type == HEALTH)
		gainExperience(realDamage);
	if (getHP() <= 0)
		die();
	return realDamage;
}

void PlayerCharacter::act(Entity* target)
{
	int realDamage = 0;
	if (getHolding() == nullptr)
		realDamage = target->takeDamage(1);
	else
		realDamage = getHolding()->use(target);
	if (realDamage >= 0)
		gainExperience(realDamage);
}

void PlayerCharacter::dealDamage(int damage, Entity* target, STAT_TYPE type)
{
	int realDamage = target->takeDamage(damage);
	if (damage >= 0)
		gainExperience(realDamage);
}

void PlayerCharacter::heal(int amount, STAT_TYPE type)
{
	Entity::heal(amount, type);
}

void PlayerCharacter::die()
{
	Entity::die();
	Console::print("You have died\n");
	throw GameOver();
}