#include "System.h"

void System::quickStart()
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned>(time(0)));
		seeded = true;
	}
}