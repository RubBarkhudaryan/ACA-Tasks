#include <iostream>
#include "./car.h"

Audi::Audi()
	: Car()
{
	std::cout << "Audi default ctor called.\n";
	this->brand = "Audi";
}

Audi::Audi(const std::string& model, const std::string& colour, Engine engine,
		const std::string& type, const std::string& vin, double price, int year,
		int kilometrage, int seats_count, int fuel_capacity)
	: Car("Audi", model, colour, engine, type, vin, price, year,
			kilometrage, seats_count, fuel_capacity)
{
	std::cout << "Audi parameterized ctor called.\n";
}

Audi::Audi(const Audi& audi)
	: Car(audi)
{
	std::cout << "Audi copy ctor called.\n";
}

Audi&	Audi::operator=(const Audi& audi)
{
	if (this != &audi)
		Car::operator=(audi);
	return *this;
}

Audi::~Audi()
{
	std::cout << "Audi dtor called.\n";
}

void	Audi::printInfo()
{
	std::cout << "Audi Info:\n";

	std::cout << "---------------------\n";
	std::cout << std::endl;

	std::cout << "Audi stands out as a symbol of innovation, performance, and cutting-edge technology in the automotive world.\n";

	std::cout << "Known for their sleek designs, advanced engineering, and exhilarating driving experiences,\n";
	std::cout << "Audi vehicles seamlessly blend luxury with sportiness, making them a favorite among car enthusiasts.\n";
	std::cout << "With a rich heritage of motorsport success and a commitment to pushing the boundaries of automotive technology,\n";
	std::cout << "Audi continues to captivate drivers worldwide with their dynamic performance and sophisticated styles.\n";

	std::cout << "Experience the thrill of the road with Audi, where precision engineering meets unparalleled luxury.\n";

	std::cout << std::endl;
	std::cout << "---------------------\n";

	std::cout << std::endl;
	Car::printInfo();
}