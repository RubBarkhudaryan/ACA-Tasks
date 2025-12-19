#include <iostream>
#include <string>
#include "car.h"

Car::Car() : brand("BMW"), model("E60"), year(2005)
{
	std::cout << "Car default ctor.\n";
}

Car::Car(const std::string& brand, const std::string& model, std::size_t year) : brand(brand), model(model), year(year)
{
	std::cout << "Car parameterized ctor.\n";
}

Car::~Car()
{
	std::cout << "Car dtor.\n";
}

BMW::BMW() : Car("BMW", "E60", 2005)
{
	std::cout << "BMW default ctor.\n";
}

BMW::BMW(const std::string& model, std::size_t year) : Car("BMW", model, year)
{
	std::cout << "BMW parameterized ctor.\n";
}

BMW::~BMW()
{
	std::cout << "BMW dtor.\n";
}