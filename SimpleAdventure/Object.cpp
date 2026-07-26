#include "Object.h"

Object::Object()
{
	type = STONE;
}

MATERIAL Object::getMaterial() const
{
	return type;
}

int Object::takeDamage(int damage)
{
	return Entity::takeDamage(damage);
}

void Object::dealDamage(int damage, Entity* target)
{
	Entity::dealDamage(damage, target);
}

void Object::heal(int amount)
{
	Entity::heal(amount);
}

void Object::die()
{
	Entity::die();
}