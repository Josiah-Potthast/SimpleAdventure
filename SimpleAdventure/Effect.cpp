#include "Effect.h"

Effect::Effect() : Effect(1)
{

}

Effect::Effect(int stacks)
{
	this->stacks = stacks;
	positive = true;
	name = EFFECT;
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

EFFECT_NAME Effect::getName()
{
	return name;
}