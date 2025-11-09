#include <iostream>
#include <string>
#include "./car.h"
#include "./driver.h"

Driver::Driver()
{
	std::cout << "Driver default ctor called.\n";
	this->name = "John";
	this->surname = "Doe";
	this->gender = true;
	this->age = 20;
	this->car;
}

Driver::Driver(std::string name, std::string surname, bool gender, int age, Car car)
{
	std::cout << "Driver parameterized ctor called.\n";
	this->name = name;
	this->surname = surname;
	this->gender = gender;
	this->age = age;
	this->car = car;
}

Driver::~Driver()
{
	std::cout << "Driver dtor called.\n";
}

void	Driver::printInfo()
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Surname: " << this->surname << std::endl;
	std::cout << "Gender: " << (this->gender ? "male" : "female") << std::endl;
	std::cout << "Age: " << this->age << std::endl;

}

Car	Driver::getCar()
{
	return this->car;
}
