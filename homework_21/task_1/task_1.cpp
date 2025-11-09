#include <iostream>
#include <string>

int	main()
{
	Engine	engine("M119", "V-shape", "fuel", 8, 5);
	Car		Mercedes("Mercedes", "E-Class W124 500", "Black Metalic", engine, "Sedan", "WDDGF4HB8JR123456", 20000, 1995, 30000, 5, 70);
	Driver	me("Ruben", "Barkhudaryan", true, 20, Mercedes);

	routine(me);
	return (0);
}
