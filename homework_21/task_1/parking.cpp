#include <iostream>
#include <string>
#include "parking.h"

Parking::Parking(const std::string& location, std::size_t capacity)
	: location(location), capacity(capacity), unavailable_count(0)
{
	this->parking = new std::size_t[capacity]{0};
	std::cout << "Parking created at " << this->location << " with capacity " << this->capacity << std::endl;
}

Parking::Parking(const Parking& other)
	: location(other.location), capacity(other.capacity), unavailable_count(other.unavailable_count)
{
	delete[] this->parking;
	this->parking = new std::size_t[other.capacity]();
	for (std::size_t i = 0; i < other.capacity; ++i)
		this->parking[i] = other.parking[i];
	std::cout << "Parking copied from " << other.location << std::endl;
}

Parking::~Parking()
{
	delete[] this->parking;
	std::cout << "Parking at " << this->location << " destroyed" << std::endl;
}

Parking&	Parking::operator=(const Parking& other)
{
	if (this != &other)
	{
		this->location = other.location;
		this->capacity = other.capacity;
		this->unavailable_count = other.unavailable_count;

		delete[] this->parking;
		this->parking = new std::size_t[other.capacity]();
		for (std::size_t i = 0; i < other.capacity; ++i)
			this->parking[i] = other.parking[i];
	}
	std::cout << "Parking at " << this->location << " assigned from " << other.location << std::endl;
	return *this;
}

bool	Parking::park(std::size_t spot)
{
	if (this->unavailable_count < this->capacity)
	{
		if (spot >= 1 && spot <= this->capacity)
		{
			if (this->parking[spot - 1])
			{
				this->parking[spot - 1] = 0;
				this->unavailable_count++;
				std::cout << "Parked at spot " << spot << " in " << location << std::endl;
				return (true);
			}
			else
				std::cout << "Spot " << spot << " in " << location << " is already occupied." << std::endl;
		}
	}
	else
		std::cout << "Parking at " << location << " is full. Cannot park." << std::endl;
	return (false);
}

bool	Parking::retrieve(std::size_t spot)
{
	if (spot >= 1 && spot <= this->capacity)
	{
		if (!this->parking[spot - 1])
		{
			this->parking[spot - 1] = 1;
			this->unavailable_count--;
			std::cout << "Retrieved from spot " << spot << " in " << location << std::endl;
			return (true);
		}
		else
			std::cout << "Spot " << spot << " in " << location << " is already free." << std::endl;
	}
	return (false);
}

void	Parking::display()
{
	std::cout << "Parking at " << location << " status:" << std::endl;
	for (std::size_t i = 0; i < capacity; ++i)
	{
		if (this->parking[i] == 0)
			std::cout << "\033[1;31m" << "Spot " << (i + 1) << ": " << "Occupied" << "\033[0m" << std::endl;
		else
			std::cout << "\033[1;32m" << "Spot " << (i + 1) << ": " << "Free" << "\033[0m" << std::endl;
	}
}
