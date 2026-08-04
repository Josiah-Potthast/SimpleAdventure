#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "Entity.h"

// an Entity controlled by the user
class PlayerCharacter : public Entity
{
private:
	int experience;
	int level;
	const double EXP_SCALING = 1.2; // multiplier for required xp per level
	const int STAT_INCREASE = 5; // how much a stat increases upon level up
	// character class not added yet
public:
	// default constructor
	PlayerCharacter();
	// destructor
	~PlayerCharacter() override;

	// returns current experience
	int getExperience() const;
	// returns current level
	int getLevel() const;

	// takes in an int and adds it to experience
	// checks for, and potentially calls, a level up
	void gainExperience(int exp);
	// reduces experience by a given int
	// cannot reduce to below zero, cannot reduce level
	void loseExperience(int exp);
	// increments level, increases a stat max of the user's choice,
	// and fully heals the PlayerCharacter
	void levelUp();
	// in a single line, displays current and max stats
	void checkStatus();

	// attacks target, and calls gainExperience() with actual damage dealt
	void act(Entity* target) override;
	// calls gainExperience() with the result of Entity::takeDamage()
	// calls die() if HP end at 0
	int takeDamage(int damage, STAT_TYPE type = HEALTH) override;
	// calls takeDamage() on the target, then calls gainExperience() with the result
	void dealDamage(int damage, Entity* target, STAT_TYPE type = HEALTH) override;
	// calls Entity::heal()
	void heal(int amount, STAT_TYPE type = HEALTH) override;

	// calls Entity::die(), prints a death message, then throws GameOver
	void die() override;

	// thrown when an error is encountered during the level up process
	class LevelUpException {};
	// thrown when the player dies
	class GameOver {};
};

#endif