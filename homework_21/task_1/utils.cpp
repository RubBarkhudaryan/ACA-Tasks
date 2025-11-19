#include <iostream>
#include "car.h"
#include "driver.h"
#include "main.h"

void	print_options()
{
	std::cout << "Choose an action:\n";
	std::cout << "1. Get parking lot\n";
	std::cout << "2. Print car info\n";
	std::cout << "3. Print driver info\n";
	std::cout << "4. Start engine\n";
	std::cout << "5. Drive\n";
	std::cout << "6. Stop engine\n";
	std::cout << "7. Repaint car\n";
	std::cout << "8. Refuel car\n";
	std::cout << "9. Park car\n";
	std::cout << "10. Retrieve car\n";
	std::cout << "11. Exit\n\n";
}

void	routine(Driver& driver)
{
	Car			*car = nullptr;
	Parking		*lot = nullptr;
	int			choice;
	int			distance;
	int			amount;
	int			spot;
	std::string	new_colour;

	car = driver.getCar();
	if (car == nullptr)
	{
		std::cout << "Driver has no car. Please buy a car first.\n";
		driver.setCar(new Car());
		car = driver.getCar();
	}
	while (true)
	{
		print_options();
		std::cin >> choice;

		if (choice == 1)
		{
			lot = new Parking("456 Elm St", 100);
			car->setParking(lot);
		}
		else if (choice == 2)
			car->printInfo();
		else if (choice == 3)
			driver.printInfo();
		else if (choice == 4)
			car->startEngine();
		else if (choice == 5)
		{
			std::cout << "Enter distance to drive (km): ";
			std::cin >> distance;
			car->drive(distance);
		}
		else if (choice == 6)
			car->stopEngine();
		else if (choice == 7)
		{
			std::cout << "Enter new colour: ";
			std::cin >> new_colour;
			car->repaint(new_colour);
		}
		else if (choice == 8)
		{
			std::cout << "Enter amount of fuel to refuel (liters): ";
			std::cin >> amount;
			car->refuel(amount);
		}
		else if (choice == 9)
		{
			if (car->getLot() == nullptr)
			{
				std::cout << "This car has no parking lot assigned.\n";
				continue;
			}
			else if (car->isParked())
			{
				std::cout << "Car is already parked.\n";
				continue;
			}
			std::cout << "Enter parking spot number to park: ";
			std::cin >> spot;
			if (car->getLot()->park(spot))
				car->park(true);
			else
				car->park(false);
		}
		else if (choice == 10)
		{
			if (car->getLot() == nullptr)
			{
				std::cout << "This car has no parking lot assigned.\n";
				continue;
			}
			else if (!car->isParked())
			{
				std::cout << "Car is not parked.\n";
				continue;
			}
			std::cout << "Enter parking spot number to retrieve: ";
			std::cin >> spot;
			if (car->getLot()->retrieve(spot))
				car->retrieve(true);
			else
				car->retrieve(false);
		}
		else if (choice == 11)
			break ;
		else
		{
			std::cout << "Invalid choice. Try again.\n";
			continue ;
		}
		std::cout << "Press Enter to continue...\n";
		std::cin.ignore();
		std::cin.get();
	}
	delete car;
	delete lot;
}
