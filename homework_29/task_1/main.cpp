#include <iostream>
#include "animal.h"

int main()
{

	Frog	frog1("Freddy", "Tree Frog", "Green", 2, 0.5, 4.0);

	frog1.sound();
	frog1.run();
	frog1.jump();
	frog1.swim();
	frog1.dive();
	frog1.crawl();

	return (0);
}