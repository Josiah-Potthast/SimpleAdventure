#include "Entity.h"

Entity::Entity() : Entity(20, 20, 20)
{

}

Entity::Entity(int maxHP, int maxMP, int maxSP)
{
	this->maxHP = maxHP;
	this->maxMP = maxMP;
	this->maxSP = maxSP;
	this->HP = maxHP;
	this->MP = maxMP;
	this->SP = maxSP;
}

Entity::~Entity()
{

}

int Entity::getMaxHP() const
{
	return maxHP;
}

int Entity::getMaxMP() const
{
	return maxMP;
}

int Entity::getMaxSP() const
{
	return maxSP;
}

int Entity::getHP() const
{
	return HP;
}

int Entity::getMP() const
{
	return MP;
}

int Entity::getSP() const
{
	return SP;
}

void Entity::setMaxHP(int maxHP)
{
	if (maxHP > 0)
		this->maxHP = maxHP;
	else
		throw NegativeStat();
}

void Entity::setMaxMP(int maxMP)
{
	if (maxMP > 0)
		this->maxMP = maxMP;
	else
		throw NegativeStat();
}

void Entity::setMaxSP(int maxSP)
{
	if (maxSP > 0)
		this->maxSP = maxSP;
	else
		throw NegativeStat();
}

void Entity::setHP(int HP)
{
	if (HP <= this->maxHP)
		this->HP = HP;
	else
		throw StatOverMax();
}

void Entity::setMP(int MP)
{
	if (MP <= this->maxMP)
		this->MP = MP;
	else
		throw StatOverMax();
}

void Entity::setSP(int SP)
{
	if (SP <= this->maxSP)
		this->SP = SP;
	else
		throw StatOverMax();
}

int Entity::takeDamage(int damage)
{
	if (damage > 0)
	{
		if (damage < HP)
			HP -= damage;
		else
		{
			HP = 0;
			die();
		}
		return damage;
	}
	return 0;
}

void Entity::dealDamage(int damage, Entity* target)
{
	target->takeDamage(damage);
}

void Entity::heal(int amount)
{
	if (amount + HP <= maxHP)
		HP += amount;
	else
		HP = maxHP;
}

void Entity::inflict(Effect* effect)
{
	for (int i = 0; i < effects.size(); i++)
		if (effects[i]->getName() == effect->getName())
		{
			effects[i]->setStacks(effects[i]->getStacks() + effect->getStacks());
			return;
		}
	effects.push_back(effect);
}

void Entity::cure(EFFECT_NAME effectName)
{
	for (int i = 0; i < effects.size(); i++)
		if (effects[i]->getName() == effectName)
		{
			for (int j = i; j < effects.size() - 1; j++)
			{
				Effect* temp = effects[j];
				effects[j] = effects[j + 1];
				effects[j + 1] = temp;
			}
			break;
		}
	if (effects[effects.size()]->getName() == effectName)
		effects.pop_back();
}

void Entity::cleanse()
{
	for (int i = 0; i < effects.size(); i++)
		if (effects[i]->isPositive() == false)
			cure(effects[i]->getName());
}

void Entity::dispel()
{
	for (int i = 0; i < effects.size(); i++)
		if (effects[i]->isPositive() == true)
			cure(effects[i]->getName());
}

void Entity::clear()
{
	for (int i = 0; i < effects.size(); i++)
		cure(effects[i]->getName());
}

void Entity::gainItem(Item* item)
{
	inventory.push_back(item);
}

void Entity::equip(Item* item)
{
	holding = item;
}

vector<Item*> Entity::getInventory() const
{
	return inventory;
}

Item* Entity::getHolding()
{
	return holding;
}

void Entity::die()
{
	clear();
}