#include <iostream>
#include <string>
#include "car.h"
#include "engine.h"
#include "driver.h"
#include "parking.h"
#include "main.h"

int	main()
{
	Engine	engine("M119", "V-shape", "fuel", 8, 5);
	Parking	lot("123 Main St", 50);
	Car		Mercedes("Mercedes-Benz", "E 500", "Black", &lot, engine, "Sedan", "WDDUG8FB7JA123456", 110000.0, 1995, 15000, 5, 80, false);
	Driver	me("Ruben", "Barkhudaryan", true, 20, &Mercedes);

	routine(me);
	return (0);
}
