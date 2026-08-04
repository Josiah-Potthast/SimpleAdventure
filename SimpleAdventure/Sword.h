#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"

// a subclass of Weapon
class Sword : public Weapon
{
private:
public:
	// default constructor
	Sword();

	// calls Weapon::attack()
	int attack(Entity* target) override;
	// returns 0 (HP type damage)
	int getStatType() const override;
};

#endif