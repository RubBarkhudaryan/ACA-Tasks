#include <iostream>
#include "./car.h"

Car::Car()
{
	std::cout << "Car default ctor called.\n";
	this->brand = "";
	this->model = "";
	this->colour = "";
	this->year = 0;
}

Car::Car(std::string brand, std::string model, std::string colour, int year)
{
	std::cout << "Car parameterized ctor called.\n";
	this->brand = brand;
	this->model = model;
	this->colour = colour;
	this->year = year;
}

Car::Car(const Car &car)
{
	std::cout << "Car copy ctor called.\n";
	this->brand = car.brand;
	this->model = car.model;
	this->colour = car.colour;
	this->year = car.year;
}

Car&	Car::operator=(const Car &car)
{
	std::cout << "Assignment opertor called.\n";
	if (this != &car)
	{
		this->brand = car.brand;
		this->model = car.model;
		this->colour = car.colour;
		this->year = car.year;
	}
	return *this;
}

Car::~Car()
{
	std::cout << "Car dtor called.\n";
}

std::ostream&	operator<<(std::ostream& os, const Car& car)
{
	os << "Brand: " << car.brand << std::endl;
	os << "Model: " << car.model << std::endl;
	os << "Colour: " << car.colour << std::endl;
	os << "Year: " << car.year << std::endl;
	os << std::endl;

	return os;
}


void	Car::repaint(std::string new_colour)
{
	this->colour = new_colour;
	std::cout << "Car repainted to " << new_colour << ".\n";
	std::cout << std::endl;
}
