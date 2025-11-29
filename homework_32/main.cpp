#include <iostream>
#include "animal.h"

int main()
{

	Lion lion("Simba", "African Lion", "Golden", 5, 420.0, 1.2);
	lion.sound();

	Tiger tiger("Shere Khan", "Bengal Tiger", "Orange with black stripes", 4, 420.0, 1.1);
	tiger.sound();

	std::cout << "\nComparing animals based on weight:" << std::endl;
	if (lion > tiger)
		std::cout << lion.getname() << " is heavier than " << tiger.getname() << std::endl;
	else if (lion < tiger)
		std::cout << tiger.getname() << " is heavier than " << lion.getname() << std::endl;
	else
		std::cout << tiger.getname() << " is as heavy as " << lion.getname() << std::endl;

	return 0;
}