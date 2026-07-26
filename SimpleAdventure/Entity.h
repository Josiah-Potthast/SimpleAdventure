#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <vector>
#include "Effect.h"
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
	// inventory
public:
	Entity();
	Entity(int maxHP, int maxMP, int maxSP);
	virtual ~Entity();

	int getMaxHP() const;
	int getMaxMP() const;
	int getMaxSP() const;
	int getHP() const;
	int getMP() const;
	int getSP() const;

	void setMaxHP(int maxHP);
	void setMaxMP(int maxMP);
	void setMaxSP(int maxSP);
	void setHP(int HP);
	void setMP(int MP);
	void setSP(int SP);

	void takeDamage(int damage);
	void dealDamage(int damage, Entity* target);
	void heal(int amount);
	void useItem(/*Item*/);

	void inflict(Effect* effect);
	void cure(EFFECT_NAME effectName);
	void cleanse();
	void dispel();
	void clear();

	virtual void die() = 0;

	class NegativeStat {};
	class StatOverMax {};
	class NegativeDamage {};
};

enum EFFECT_NAME
{
	POISON,
	BURN,
	SHOCK,
	FREEZE,
};

#endif