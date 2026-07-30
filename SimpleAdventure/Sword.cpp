#include "Sword.h"

Sword::Sword() : Weapon(SWORD, 2)
{

}

int Sword::attack()
{
	return Weapon::attack();
}

int Sword::getStatType() const
{
	return 0; // HP
}