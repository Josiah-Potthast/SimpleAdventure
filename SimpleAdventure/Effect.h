#ifndef EFFECT_H
#define EFFECT_H
#include <iostream>
using namespace std;

enum EFFECT_NAME;

class Effect
{
private:
	int stacks; // used to track multiple instances/stronger effects for a given target
	bool positive; // true for buffs (good effects), false for debuffs (bad effects)
	EFFECT_NAME name;
public:
	Effect();
	Effect(int stacks);

	int getStacks() const;
	void setStacks(int stacks);
	bool isPositive() const;
	EFFECT_NAME getNameEnum();

	static string getName(EFFECT_NAME effect);

	virtual void trigger() = 0;

	class EffectNotFound {};
};

enum EFFECT_NAME
{
	EFFECT,
	POISON,
	BURN,
	SHOCK,
	FREEZE,
};

#endif