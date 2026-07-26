#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <vector>
#include "Console.h"
#include "Effect.h"
#include "Item.h"
using namespace std;

enum EFFECT_NAME;
class Effect;

class Entity
{
private:
	int maxHP; // maximum hit points/health points
	int maxMP; // maximum mana points
	int maxSP; // maximum stamina points
	int HP; // current hit points/health points
	int MP; // current mana points
	int SP; // current stamina points
	vector<Effect*> effects;
	vector<Item*> inventory;
protected:
	Entity();
	Entity(int maxHP, int maxMP, int maxSP);
	virtual ~Entity();

	void setMaxHP(int maxHP);
	void setMaxMP(int maxMP);
	void setMaxSP(int maxSP);
	void setHP(int HP);
	void setMP(int MP);
	void setSP(int SP);
public:
	int getMaxHP() const;
	int getMaxMP() const;
	int getMaxSP() const;
	int getHP() const;
	int getMP() const;
	int getSP() const;

	virtual int takeDamage(int damage);
	virtual void dealDamage(int damage, Entity* target);
	virtual void heal(int amount);

	void inflict(Effect* effect);
	void cure(EFFECT_NAME effectName);
	void cleanse();
	void dispel();
	void clear();

	void gainItem(Item* item);

	virtual void die() = 0;

	class NegativeStat {};
	class StatOverMax {};
	class NegativeDamage {};
};

#endif