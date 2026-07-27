#include "Dummy.h"

Dummy::Dummy() : NonPlayerCharacter(1000, 1000, 1000)
{

}

void Dummy::die()
{
	Console::print("Dummy is immortal!\n");
	heal(1000);
}