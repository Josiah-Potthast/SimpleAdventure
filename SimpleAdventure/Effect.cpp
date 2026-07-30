#include "Effect.h"

Effect::Effect() : Effect(1)
{

}

Effect::Effect(int stacks)
{
	this->stacks = stacks;
	positive = true;
}

int Effect::getStacks() const
{
	return stacks;
}

void Effect::setStacks(int stacks)
{
	if (stacks >= 0)
		this->stacks = stacks;
}

bool Effect::isPositive() const
{
	return positive;
}

EFFECT_NAME Effect::getNameEnum()
{
	return name;
}

string Effect::getName(EFFECT_NAME effect)
{
	switch (effect)
	{
	default:
		throw EffectNotFound();
	}
}