#include <iostream>
#include "car.h"
#include "animal.h"

int	main()
{
	Animal	*lion;
	Car		car("Audi", "A6", 2010);
	Tiger	tiger("Shere Khan", "Bengal", "Orange", 5, 220.5, 3.1);

	lion = dynamic_cast<Animal *>(&tiger);
	if (lion)
	{
		std::cout << "Lion name: " << lion->getname() << "\n";
		lion->sound();
	}
	else
		std::cout << "Dynamic cast failed.\n";

	lion = dynamic_cast<Animal *>(&car);
	if (lion)
	{
		std::cout << "Lion name: " << lion->getname() << "\n";
		lion->sound();
	}
	else
		std::cout << "Dynamic cast failed.\n";
	return (0);
}