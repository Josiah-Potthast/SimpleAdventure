#include "Sword.h"

Sword::Sword() : Weapon(SWORD, 2)
{

}

int Sword::attack(Entity* target)
{
	return Weapon::attack(target);
}

int Sword::getStatType() const
{
	return 0; // HP
}