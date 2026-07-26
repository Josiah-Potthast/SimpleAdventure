#include "Effect.h"

Effect::Effect() : Effect(1)
{

}

Effect::Effect(int stacks)
{
	this->stacks = stacks;
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

EFFECT_NAME Effect::getName()
{
	return name;
}