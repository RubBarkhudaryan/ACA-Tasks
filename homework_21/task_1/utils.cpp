
void	print_options()
{
	std::cout << "Choose an action:\n";
	std::cout << "1. Print car info\n";
	std::cout << "2. Print driver info\n";
	std::cout << "3. Start engine\n";
	std::cout << "4. Drive\n";
	std::cout << "5. Stop engine\n";
	std::cout << "6. Repaint car\n";
	std::cout << "7. Refuel car\n";
	std::cout << "8. Exit\n\n";
}

void	routine(Driver& driver)
{
	Car	car;

	car = driver.getCar();
	while (true)
	{
		print_options();
		int	choice;
		std::cin >> choice;

		if (choice == 1)
			car.printInfo();
		if (choice == 2)
			driver.printInfo();
		else if (choice == 3)
			car.startEngine();
		else if (choice == 4)
		{
			std::cout << "Enter distance to drive (km): ";
			int	distance;
			std::cin >> distance;
			car.drive(distance);
		}
		else if (choice == 5)
			car.stopEngine();
		else if (choice == 6)
		{
			std::cout << "Enter new colour: ";
			std::string	new_colour;
			std::cin >> new_colour;
			car.repaint(new_colour);
		}
		else if (choice == 7)
		{
			std::cout << "Enter amount of fuel to refuel (liters): ";
			int	amount;
			std::cin >> amount;
			car.refuel(amount);
		}
		else if (choice == 8)
			break;
		else
			std::cout << "Invalid choice. Try again.\n";
		std::cout << "Press Enter to continue...\n";
		std::cin.ignore();
		std::cin.get();
	}
}
