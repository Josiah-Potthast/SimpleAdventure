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
	holding = nullptr;
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

int& Entity::getStat(STAT_TYPE type)
{
	switch (type)
	{
	case HEALTH:
		return HP;
	case MANA:
		return MP;
	case STAMINA:
		return SP;
	}
}

int& Entity::getMaxStat(STAT_TYPE type)
{
	switch (type)
	{
	case HEALTH:
		return maxHP;
	case MANA:
		return maxMP;
	case STAMINA:
		return maxSP;
	}
}

void Entity::attack(Entity* target)
{
	dealDamage(holding->use(), target, static_cast<STAT_TYPE>(holding->getStatType()));
	this->takeDamage(holding->getWeight(), STAMINA);
}

int Entity::takeDamage(int damage, STAT_TYPE type)
{
	int& stat = getStat(type);
	if (damage > 0)
	{
		if (damage > stat && stat > 0)
		{
			damage = stat;
			stat -= damage;
		}
		else if (stat == 0 && &stat != &HP)
			damage = takeDamage(damage / 2, HEALTH);
		else
			stat -= damage;
		return damage;
	}
	return 0;
}

void Entity::dealDamage(int damage, Entity* target, STAT_TYPE type)
{
	target->takeDamage(damage, type);
}

void Entity::heal(int amount, STAT_TYPE type)
{
	int& stat = getStat(type);
	if (amount + stat <= getMaxStat(type))
		stat += amount;
	else
		stat = getMaxStat(type);
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
	
}