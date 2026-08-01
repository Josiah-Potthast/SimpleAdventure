#include "Effect.h"

Effect::Effect()
{

}

int& Effect::getEffect(EFFECT_NAME effect)
{
	switch (effect)
	{
	case POISON:
		return poison;
	case BURN:
		return burn;
	case SHOCK:
		return shock;
	case STUN:
		return stun;
	case FREEZE:
		return freeze;
	default:
		throw EffectNotFound();
	}
}

int Effect::getStacks(EFFECT_NAME effect)
{
	int stacks = getEffect(effect);
	return stacks;
}

bool Effect::isPositive(EFFECT_NAME effect) const
{
	switch (effect)
	{
	case POISON:
	case BURN:
	case SHOCK:
	case STUN:
	case FREEZE:
		return false;
	default:
		throw EffectNotFound();
	}
}

void Effect::inflict(EFFECT_NAME effect, int stacks)
{
	getEffect(effect) += stacks;
}

void Effect::cure(EFFECT_NAME effect, int stacks)
{
	if (getEffect(effect) >= stacks)
		getEffect(effect) -= stacks;
	else
		getEffect(effect) = 0;
}

void Effect::cleanse()
{
	for (int i = POISON; i < FREEZE; i++)
		if (!isPositive(static_cast<EFFECT_NAME>(i)))
			cure(static_cast<EFFECT_NAME>(i));
}

void Effect::dispel()
{
	for (int i = POISON; i < FREEZE; i++)
		if (isPositive(static_cast<EFFECT_NAME>(i)))
			cure(static_cast<EFFECT_NAME>(i));
}

void Effect::clear()
{
	for (int i = POISON; i < FREEZE; i++)
		cure(static_cast<EFFECT_NAME>(i));
			
}

string Effect::getName(EFFECT_NAME effect)
{
	switch (effect)
	{
	case POISON:
		return "poison";
	case BURN:
		return "burn";
	case SHOCK:
		return "shock";
	case STUN:
		return "stun";
	case FREEZE:
		return "freeze";
	default:
		throw EffectNotFound();
	}
}