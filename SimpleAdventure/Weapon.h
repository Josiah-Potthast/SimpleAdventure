#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

// a subclass of Item, used mostly for direct attacks
class Weapon : public Item
{
private:
	int baseDamage;
public:
	// parameterized constructor
	Weapon(ITEM_NAME item, int weight);

	// returns baseDamage
	int getBaseDamage() const;
	// sets baseDamage to newBase
	void setBaseDamage(int newBase);
	// returns base damage, plus or minus 20%
	int calcDamage() const;

	// rolls a figurative d20
	// deals double damage on 20, zero damage on 1,
	// and normal damage otherwise
	virtual int attack(Entity* target) = 0;

	// calls attack() and returns the result
	int use(Entity* target) override;
};

#endif