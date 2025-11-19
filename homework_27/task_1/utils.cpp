#include <iostream>
#include "car.h"
#include "main.h"

void	print_options()
{
	std::cout << "Choose an action:\n";
	std::cout << "1. Print car info\n";
	std::cout << "2. Start engine\n";
	std::cout << "3. Drive\n";
	std::cout << "4. Stop engine\n";
	std::cout << "5. Repaint car\n";
	std::cout << "6. Refuel car\n";
	std::cout << "7. Exit\n\n";
}

void	routine(Car *car)
{
	int			choice;
	int			distance;
	int			amount;
	bool		created_car;
	std::string	new_colour;

	created_car = false;
	if (car == nullptr)
	{
		std::cout << "Because of you don't have a car this program will create a new one for you.\n";
		car = new Car();
		created_car = true;
	}
	while (true)
	{
		print_options();
		std::cin >> choice;

		if (choice == 1)
			car->printInfo();
		else if (choice == 2)
			car->startEngine();
		else if (choice == 3)
		{
			std::cout << "Enter distance to drive (km): ";
			std::cin >> distance;
			car->drive(distance);
		}
		else if (choice == 4)
			car->stopEngine();
		else if (choice == 5)
		{
			std::cout << "Enter new colour: ";
			std::cin >> new_colour;
			car->repaint(new_colour);
		}
		else if (choice == 6)
		{
			std::cout << "Enter amount of fuel to refuel (liters): ";
			std::cin >> amount;
			car->refuel(amount);
		}
		else if (choice == 7)
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
	if (created_car)
		delete car;
}
