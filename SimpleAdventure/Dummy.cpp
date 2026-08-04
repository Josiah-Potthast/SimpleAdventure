#include "Dummy.h"

Dummy::Dummy() : NonPlayerCharacter(1000, 1000, 1000)
{

}

void Dummy::act(Entity* target)
{
	Console::print("The dummy is incapable of action\n");
}

void Dummy::die()
{
	Console::print("The dummy is immortal!\n");
	heal(1000);
}