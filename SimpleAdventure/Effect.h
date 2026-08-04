#ifndef EFFECT_H
#define EFFECT_H
#include <iostream>
using namespace std;

enum EFFECT_NAME;

// governs status effects for an Entity object
class Effect
{
private:
	int poison = 0;
	int burn = 0;
	int shock = 0;
	int stun = 0;
	int freeze = 0;
	// returns a reference to the relevant variable
	int& getEffect(EFFECT_NAME effect);
public:
	// default constructor
	Effect();

	// returns the non-reference value of an effect
	int getStacks(EFFECT_NAME effect);
	// returns true for buffs, false for debuffs
	bool isPositive(EFFECT_NAME effect) const;
	
	// adds a number of stacks of a particular effect,
	// defaulting to one stack
	void inflict(EFFECT_NAME effect, int stacks = 1);
	// removes a number of stacks of a particular effect,
	// defaulting to one stack
	void cure(EFFECT_NAME effect, int stacks = 1);
	// removes all stacks of all negative effects (debuffs)
	void cleanse();
	// removes all stacks of all positive effects (buffs)
	void dispel();
	// removes all stacks of all effects
	void clear();

	// returns the name of an effect as a string
	static string getName(EFFECT_NAME effect);

	// thrown when a switch statement does not have a case
	// matching the effect
	class EffectNotFound {};
};

// used with switch statements to differentiate between effects
enum EFFECT_NAME
{
	POISON,
	BURN,
	SHOCK,
	STUN,
	FREEZE,
};

#endif