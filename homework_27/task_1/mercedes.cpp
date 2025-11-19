#include <iostream>
#include "./car.h"

Mercedes::Mercedes()
	: Car()
{
	std::cout << "Mercedes default ctor called.\n";
	this->brand = "Mercedes-Benz";
}

Mercedes::Mercedes(const std::string& model, const std::string& colour, Engine engine,
		const std::string& type, const std::string& vin, double price, int year,
		int kilometrage, int seats_count, int fuel_capacity)
	: Car("Mercedes-Benz", model, colour, engine, type, vin, price, year,
			kilometrage, seats_count, fuel_capacity)
{
	std::cout << "Mercedes parameterized ctor called.\n";
}

Mercedes::Mercedes(const Mercedes& mercedes)
	: Car(mercedes)
{
	std::cout << "Mercedes copy ctor called.\n";
}

Mercedes&	Mercedes::operator=(const Mercedes& mercedes)
{
	if (this != &mercedes)
		Car::operator=(mercedes);
	return *this;
}

Mercedes::~Mercedes()
{
	std::cout << "Mercedes dtor called.\n";
}

void	Mercedes::printInfo()
{
	std::cout << "Mercedes Info:\n";

	std::cout << "---------------------\n";
	std::cout << std::endl;

	std::cout << "Stylish and luxurious yet still sporty and performance-oriented,\n";
	std::cout << "Mercedes-Benz vehicles offer a driving experience that is both comfortable and exhilarating.\n";

	std::cout << "Whether you're behind the wheel of a sleek coupe or a spacious SUV,\n";
	std::cout << "you can expect precise handling, powerful engines, and advanced technology features\n";
	std::cout << "that enhance both safety and convenience.\n";

	std::cout << "From the iconic three-pointed star emblem to the meticulously crafted interiors,\n";
	std::cout << "every Mercedes-Benz is a testament to the brand's commitment to excellence and innovation.\n";

	std::cout << "---------------------\n";
	std::cout << std::endl;

	Car::printInfo();
}