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

	void die() override;
};

#endif