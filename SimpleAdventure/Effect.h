#ifndef EFFECT_H
#define EFFECT_H
#include <iostream>
using namespace std;

enum EFFECT_NAME;

class Effect
{
private:
	int poison;
	int burn;
	int shock;
	int freeze;
	// returns a reference to the relevant variable
	int& getEffect(EFFECT_NAME effect);
public:
	Effect();

	// returns the non-reference value of an effect
	int getStacks(EFFECT_NAME effect);
	bool isPositive(EFFECT_NAME effect) const;
	
	void inflict(EFFECT_NAME effect, int stacks = 1);
	void cure(EFFECT_NAME effect);
	void cleanse();
	void dispel();
	void clear();

	static string getName(EFFECT_NAME effect);

	class EffectNotFound {};
};

enum EFFECT_NAME
{
	POISON,
	BURN,
	SHOCK,
	FREEZE,
};

#endif