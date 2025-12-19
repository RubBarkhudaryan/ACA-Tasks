#include <iostream>
#include "parking.h"

Parking::Parking() : capacity(100), occupied(0),  slots(new int[capacity])
{
	for (int i = 0; i < capacity; ++i)
		slots[i] = 1;
	std::cout << "Parking created with capacity: " << capacity << std::endl;
}

Parking::~Parking()
{
	std::cout << "Parking destroyed." << std::endl;
	delete[] slots;
}

Parking&	Parking::getInstance()
{
	static Parking	instance;
	return (instance);
}

bool	Parking::parkCar(int slot)
{
	if ((slot - 1) >= capacity || (slot - 1) < 0 || slots[slot - 1] == 0)
		return (false);
	slots[slot - 1] = 0;
	++occupied;
	return (true);
}

bool	Parking::removeCar(int slot)
{
	if ((slot - 1) >= capacity || (slot - 1) < 0 || slots[slot - 1] == 1)
		return (false);
	slots[slot - 1] = 1;
	--occupied;
	return (true);
}

int	Parking::getAvailableSlots() const
{
	return (capacity - occupied);
}
