#include <iostream>

int main(void)
{
	float	celsius;
	float	fahrenheit;
	float	kelvin;

	std::cin >> celsius;

	fahrenheit = (celsius * (9 / 5)) + 32;
	kelvin = celsius + 273.15;

	std::cout << "Celsius to Fahrenheit: " << fahrenheit << "\n";
	std::cout << "Celsius to Kelvin: " << kelvin << "\n";

	return (0);
}