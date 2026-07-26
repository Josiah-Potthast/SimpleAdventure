#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item
{
private:
	int baseDamage;
public:
	Weapon();

	int getBaseDamage() const;
	void setBaseDamage(int newBase);
	int calcDamage();

	int attack();
};

#endif