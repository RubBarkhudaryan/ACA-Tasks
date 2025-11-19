#include <iostream>
#include "./car.h"

BMW::BMW()
	: Car()
{
	std::cout << "BMW default ctor called.\n";
	this->brand = "BMW";
}

BMW::BMW(const std::string& model, const std::string& colour, Engine engine,
		const std::string& type, const std::string& vin, double price, int year,
		int kilometrage, int seats_count, int fuel_capacity)
	: Car("BMW", model, colour, engine, type, vin, price, year,
			kilometrage, seats_count, fuel_capacity)
{
	std::cout << "BMW parameterized ctor called.\n";
}

BMW::BMW(const BMW& bmw)
	: Car(bmw)
{
	std::cout << "BMW copy ctor called.\n";
}

BMW&	BMW::operator=(const BMW& bmw)
{
	if (this != &bmw)
		Car::operator=(bmw);
	return *this;
}

BMW::~BMW()
{
	std::cout << "BMW dtor called.\n";
}

void	BMW::printInfo()
{
	std::cout << "BMW Info:\n";

	std::cout << "---------------------\n";
	std::cout << std::endl;


	std::cout << "Renowned for their blend of performance, luxury, and cutting-edge technology,\n";
	std::cout << "BMW vehicles offer a dynamic driving experience characterized by precision engineering and sporty performance.\n";

	std::cout << "Whether you're behind the wheel of a sleek coupe or a spacious SUV, ";
	std::cout << "you can expect precise handling, powerful engines, and advanced technology features ";
	std::cout << "that enhance both safety and convenience.\n";

	std::cout << "From the iconic kidney grille to the meticulously crafted interiors,\n";
	std::cout << "every BMW is a testament to the brand's commitment to driving pleasure and innovation.\n";

	std::cout << "---------------------\n";
	std::cout << std::endl;

	Car::printInfo();
}