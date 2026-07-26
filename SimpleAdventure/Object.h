#ifndef OBJECT_H
#define OBJECT_H
#include "Entity.h"

enum MATERIAL;

class Object : public Entity
{
private:
	MATERIAL type;
public:
	Object();

	MATERIAL getMaterial() const;

	int takeDamage(int damage) override;
	void dealDamage(int damage, Entity* target) override;
	void heal(int amount) override;

	void die() override;
};

enum MATERIAL
{
	WOOD,
	METAL,
	STONE,
	CLOTH,
};

#endif