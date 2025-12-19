#include <iostream>
#include "parking.h"

int	main()
{
	Parking	&parking = Parking::getInstance();

	Parking& parking2 = Parking::getInstance();

	std::cout << "Initial available slots: " << parking.getAvailableSlots() << std::endl;

	if (parking.parkCar(5))
		std::cout << "Car parked successfully." << std::endl;
	else
		std::cout << "Parking is full." << std::endl;

	std::cout << "Available slots after parking a car: " << parking.getAvailableSlots() << std::endl;

	if (parking.removeCar(5))
		std::cout << "Car removed successfully." << std::endl;
	else
		std::cout << "No cars to remove." << std::endl;

	if (&parking == &parking2)
		std::cout << "Both references point to the same Parking instance." << std::endl;

	std::cout << "Available slots after removing a car: " << parking.getAvailableSlots() << std::endl;
	return (0);
}