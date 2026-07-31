#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "Entity.h"

class PlayerCharacter : public Entity
{
private:
	int experience;
	int level;
	const double EXP_SCALING = 2; // multiplier for required xp per level
	const int STAT_INCREASE = 5; // how much a stat increases upon level up
	// character class
public:
	PlayerCharacter();
	~PlayerCharacter() override;

	int getExperience() const;
	int getLevel() const;

	void gainExperience(int exp);
	void loseExperience(int exp);
	void levelUp();
	void checkStatus();

	void attack(Entity* target) override;
	int takeDamage(int damage, STAT_TYPE type = HEALTH) override;
	void dealDamage(int damage, Entity* target, STAT_TYPE type = HEALTH) override;
	void heal(int amount, STAT_TYPE type = HEALTH) override;

	void die() override;

	class LevelUpException {};
	class GameOver {};
};

#endif