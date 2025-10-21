#include <iostream>
#include <string>

class Car
{
	private:
		std::string	brand;
		std::string	model;
		std::string	colour;
		std::string	engine;
		std::string	type;
		std::string	vin;
		double		price;
		int			year;
		int			kilometrage;
		int			seats_count;
		int			fuel_capacity;
		int			current_fuel;
		bool		engine_on;

	public:
		Car()
		{
			std::cout << "Default ctor called.\n";
			this->brand = "Unknown";
			this->model = "Unknown";
			this->colour = "Unknown";
			this->engine = "Unknown";
			this->type = "Unknown";
			this->vin = "Unknown";
			this->price = 0.0;
			this->year = 0;
			this->kilometrage = 0;
			this->seats_count = 0;
			this->fuel_capacity = 0;
			this->current_fuel = 0;
			this->engine_on = false;
		}

		Car(std::string brand, std::string model, std::string colour, std::string engine,
			std::string type, std::string vin, double price, int year,
			int kilometrage, int seats_count, int fuel_capacity)
		{
			std::cout << "Parameterized ctor called.\n";
			this->brand = brand;
			this->model = model;
			this->colour = colour;
			this->engine = engine;
			this->type = type;
			this->vin = vin;
			this->price = price;
			this->year = year;
			this->kilometrage = kilometrage;
			this->seats_count = seats_count;
			this->fuel_capacity = fuel_capacity;
			this->current_fuel = 0;
			this->engine_on = false;
		}

		~Car()
		{
			std::cout << "Dtor called.\n";
		}

		void	printInfo()
		{
			std::cout << "Brand: " << this->brand << std::endl;
			std::cout << "Model: " << this->model << std::endl;
			std::cout << "Colour: " << this->colour << std::endl;
			std::cout << "Engine: " << this->engine << std::endl;
			std::cout << "Type: " << this->type << std::endl;
			std::cout << "VIN: " << this->vin << std::endl;
			std::cout << "Price: " << this->price << std::endl;
			std::cout << "Year: " << this->year << std::endl;
			std::cout << "Kilometrage: " << this->kilometrage << std::endl;
			std::cout << "Seats count: " << this->seats_count << std::endl;
			std::cout << "Fuel capacity: " << this->fuel_capacity << std::endl;
			std::cout << "Current fuel: " << this->current_fuel << std::endl;
			std::cout << std::endl;
		}

		void	startEngine()
		{
			if (this->current_fuel <= 0)
			{
				std::cout << "Can't start engine. Refuel the car first.\n";
				std::cout << std::endl;
				return;
			}
			if (this->engine_on)
				std::cout << "Engine is already on.\n";
			else
			{
				this->engine_on = true;
				std::cout << "Starting engine...\n";
			}
		}

		void	drive(int distance)
		{
			int initial_distance = distance;
			if (!this->engine_on)
			{
				std::cout << "Can't drive. Start the engine first.\n";
				std::cout << std::endl;
				return;
			}
			if (this->current_fuel <= 0)
			{
				std::cout << "Can't drive. Refuel the car first.\n";
				std::cout << std::endl;
				return;
			}
			while (distance)
			{
				if (this->current_fuel <= 0)
					break;
				this->kilometrage += 1;
				this->current_fuel -= 0.1;
				distance -= 1;
			}
			this->kilometrage += distance;
			this->current_fuel -= distance / 10;
			if (this->current_fuel < 0)
			{
				this->current_fuel = 0;
				std::cout << "Ran out of fuel after driving" << initial_distance - distance << " km.\n";
			}
			std::cout << "Driving " << initial_distance << " km...\n";
			std::cout << std::endl;
		}

		void	stopEngine()
		{
			if (!this->engine_on)
			{
				std::cout << "Engine is already off.\n";
				std::cout << std::endl;
			}
			else
			{
				this->engine_on = false;
				std::cout << "Stopping engine...\n";
				std::cout << std::endl;
			}
		}

		void	repaint(std::string new_colour)
		{
			this->colour = new_colour;
			std::cout << "Car repainted to " << new_colour << ".\n";
			std::cout << std::endl;
		}

		void	refuel(int amount)
		{
			if (this->current_fuel + amount > this->fuel_capacity)
			{
				std::cout << "Can't refuel " << amount << " liters. Fuel tank will overflow.\n";
				std::cout << std::endl;
			}
			else
			{
				this->current_fuel += amount;
				std::cout << "Refueled " << amount << " liters.\n";
				std::cout << std::endl;
			}
		}
};

int main()
{
	Car	Mercedes("Mercedes", "E-Class W124 500", "Silver Metalic", "5.0L V8", "Sedan", "WDDGF4HB8JR123456", 20000, 1995, 30000, 5, 70);

	while (true)
	{
		std::cout << "Choose an action:\n";
		std::cout << "1. Print car info\n";
		std::cout << "2. Start engine\n";
		std::cout << "3. Drive\n";
		std::cout << "4. Stop engine\n";
		std::cout << "5. Repaint car\n";
		std::cout << "6. Refuel car\n";
		std::cout << "7. Exit\n\n";
		int	choice;
		std::cin >> choice;

		if (choice == 1)
			Mercedes.printInfo();
		else if (choice == 2)
			Mercedes.startEngine();
		else if (choice == 3)
		{
			std::cout << "Enter distance to drive (km): ";
			int	distance;
			std::cin >> distance;
			Mercedes.drive(distance);
		}
		else if (choice == 4)
			Mercedes.stopEngine();
		else if (choice == 5)
		{
			std::cout << "Enter new colour: ";
			std::string	new_colour;
			std::cin >> new_colour;
			Mercedes.repaint(new_colour);
		}
		else if (choice == 6)
		{
			std::cout << "Enter amount of fuel to refuel (liters): ";
			int	amount;
			std::cin >> amount;
			Mercedes.refuel(amount);
		}
		else if (choice == 7)
			break;
		else
			std::cout << "Invalid choice. Try again.\n";
		std::cout << "Press Enter to continue...\n";
		std::cin.ignore();
		std::cin.get();
	}
	return (0);
}