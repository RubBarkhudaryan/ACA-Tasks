#include <iostream>
#include <string>
#include "car.h"
#include "engine.h"
#include "main.h"

int	main()
{
	Car	*car = new Mercedes("E 500", "Black", Engine("M119", "V-shape", "fuel", 8, 5),
		"Sedan", "WDDUG8FB7JA123456", 110000.0, 1995, 15000, 5, 80);

	car->printInfo();

	delete car;
	return (0);
}
