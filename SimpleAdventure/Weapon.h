#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item
{
private:
	int baseDamage;
public:
	Weapon(ITEM_NAME item);

	int getBaseDamage() const;
	void setBaseDamage(int newBase);
	int calcDamage();

	virtual int attack() = 0;

	int use() override;
};

#endif