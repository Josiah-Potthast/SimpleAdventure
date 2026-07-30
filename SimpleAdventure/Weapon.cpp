#include "Weapon.h"

Weapon::Weapon(ITEM_NAME item, int weight) : Item(item, weight), baseDamage(5)
{

}

int Weapon::getBaseDamage() const
{
	return baseDamage;
}

void Weapon::setBaseDamage(int newBase)
{
	if (newBase >= 0)
		baseDamage = newBase;
}

int Weapon::calcDamage()
{
	int damageSpread = baseDamage / 5;
	int bonus = (rand() % (damageSpread + 1));
	bool positivity = rand() % 2;
	if (positivity == true)
		return baseDamage + bonus;
	else
		return baseDamage - bonus;
}

int Weapon::attack()
{
	int attack = (rand() % 20) + 1;

	if (attack == 20)
	{
		Console::print("Critical Hit! ");
		return calcDamage() * 2;
	}
	else if (attack == 1)
	{
		Console::print("Whiff! ");
		return 0;
	}
	else
		return calcDamage();
}

int Weapon::use()
{
	return attack();
}