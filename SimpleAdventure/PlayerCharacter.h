#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "Entity.h"

class PlayerCharacter : public Entity
{
private:
	int experience;
	int level;
	const double levelScaling = 1.2;
	// character class
public:
	PlayerCharacter();
	~PlayerCharacter() override;

	int getExperience() const;
	int getLevel() const;

	void gainExperience(int exp);
	void loseExperience(int exp);
	void levelUp();

	int takeDamage(int damage) override;
	void dealDamage(int damage, Entity* target) override;
	void heal(int amount) override;

	void inflict(Effect* effect) override;
	void cure(EFFECT_NAME effectName) override;
	void cleanse() override;
	void dispel() override;
	void clear() override;

	void die() override;
};

#endif