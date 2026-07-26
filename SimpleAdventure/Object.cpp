#include "Object.h"

Object::Object()
{

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

void Object::inflict(Effect* effect)
{
	Entity::inflict(effect);
}

void Object::cure(EFFECT_NAME effectName)
{
	Entity::cure(effectName);
}

void Object::cleanse()
{
	Entity::cleanse();
}

void Object::dispel()
{
	Entity::dispel();
}

void Object::clear()
{
	Entity::clear();
}

void Object::die()
{
	Entity::die();
}