#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"

class Sword : public Weapon
{
private:
public:
	Sword();

	int attack(Entity* target) override;
	int getStatType() const override;
};

#endif