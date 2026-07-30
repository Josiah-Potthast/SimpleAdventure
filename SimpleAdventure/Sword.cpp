#include "Sword.h"

Sword::Sword() : Weapon(SWORD)
{

}

int Sword::attack()
{
	return Weapon::attack();
}