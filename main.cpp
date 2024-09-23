#include "Engine.h"

Engine engine;

int main()
{

	// loop
	while (engine.getWindowIsOpen())
	{
		engine.update();

		engine.render();
	}

	return 0;

}