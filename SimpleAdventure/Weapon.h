#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item
{
private:
	int baseDamage;
public:
	Weapon(ITEM_NAME item, int weight);

	int getBaseDamage() const;
	void setBaseDamage(int newBase);
	int calcDamage() const;

	virtual int attack(Entity* target) = 0;

	int use(Entity* target) override;
};

#endif