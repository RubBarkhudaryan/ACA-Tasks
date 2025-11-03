#include <iostream>
#include <string>

class Engine
{
	private:
		std::string	model;
		std::string	shape;
		std::string	fuel_type;
		int			piston_count;
		int			liter;

	public:
		Engine()
		{
			std::cout << "Engine default ctor called.\n";
			this->model = "";
			this->shape = "";
			this->fuel_type = "";
			this->piston_count = 0;
			this->liter = 0;
		}

		Engine(std::string model, std::string shape, std::string fuel_type, int piston_count, int liter)
		{
			std::cout << "Engine parameterized ctor called.\n";
			this->model = model;
			this->shape = shape;
			this->fuel_type = fuel_type;
			this->piston_count = piston_count;
			this->liter = liter;
		}

		~Engine()
		{
			std::cout << "Engine dtor called.\n";
		}

		void	print()
		{
			std::cout << std::endl;
			std::cout << "Engine data" << std::endl;
			std::cout << "\t|-- Model: " << this->model << std::endl;
			std::cout << "\t|-- Shape: " << this->shape << std::endl;
			std::cout << "\t|-- Fuel type: " << this->fuel_type << std::endl;
			std::cout << "\t|-- Pistons count: " << this->piston_count << std::endl;
			std::cout << "\t|-- Volume: " << this->liter << " liters" << std::endl;
			std::cout << std::endl;
		}
};


class Car
{
	private:
		std::string	brand;
		std::string	model;
		std::string	colour;
		std::string	type;
		std::string	vin;
		Engine		engine;
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
			std::cout << "Car default ctor called.\n";
			this->brand = "Unknown";
			this->model = "Unknown";
			this->colour = "Unknown";
			this->engine;
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

		Car(std::string brand, std::string model, std::string colour, Engine engine,
			std::string type, std::string vin, double price, int year,
			int kilometrage, int seats_count, int fuel_capacity)
		{
			std::cout << "Car parameterized ctor called.\n";
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

		Car(const Car& car)
		{
			std::cout << "Car copy ctor called.\n";
			this->brand = car.brand;
			this->model = car.model;
			this->colour = car.colour;
			this->engine = car.engine;
			this->type = car.type;
			this->vin = car.vin;
			this->price = car.price;
			this->year = car.year;
			this->kilometrage = car.kilometrage;
			this->seats_count = car.seats_count;
			this->fuel_capacity = car.fuel_capacity;
			this->current_fuel = car.current_fuel;
			this->engine_on = car.engine_on;
		}

		Car& operator=(const Car& car)
		{
			std::cout << "Assignment opertor called.\n";
			if (this != &car)
			{
				this->brand = car.brand;
				this->model = car.model;
				this->colour = car.colour;
				this->engine = car.engine;
				this->type = car.type;
				this->vin = car.vin;
				this->price = car.price;
				this->year = car.year;
				this->kilometrage = car.kilometrage;
				this->seats_count = car.seats_count;
				this->fuel_capacity = car.fuel_capacity;
				this->current_fuel = car.current_fuel;
				this->engine_on = car.engine_on;
			}
			return *this;
		}

		~Car()
		{
			std::cout << "Car dtor called.\n";
		}

		void	printInfo()
		{
			std::cout << "Brand: " << this->brand << std::endl;
			std::cout << "Model: " << this->model << std::endl;
			std::cout << "Colour: " << this->colour << std::endl;
			this->engine.print();
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

class Driver
{
	private:
		std::string	name;
		std::string	surname;
		bool		gender;
		int			age;
		Car			car;

	public:
		Driver()
		{
			std::cout << "Driver default ctor called.\n";
			this->name = "John";
			this->surname = "Doe";
			this->gender = true;
			this->age = 20;
			this->car;
		}

		Driver(std::string name, std::string surname, bool gender, int age, Car car)
		{
			std::cout << "Driver parameterized ctor called.\n";
			this->name = name;
			this->surname = surname;
			this->gender = gender;
			this->age = age;
			this->car = car;
		}

		~Driver()
		{
			std::cout << "Driver dtor called.\n";
		}

		void	printInfo()
		{
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Surname: " << this->surname << std::endl;
			std::cout << "Gender: " << (this->gender ? "male" : "female") << std::endl;
			std::cout << "Age: " << this->age << std::endl;

		}

		Car	getCar()
		{
			return this->car;
		}
};

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

int	main()
{
	Engine	engine("M119", "V-shape", "fuel", 8, 5);
	Car		Mercedes("Mercedes", "E-Class W124 500", "Black Metalic", engine, "Sedan", "WDDGF4HB8JR123456", 20000, 1995, 30000, 5, 70);
	Driver	me("Ruben", "Barkhudaryan", true, 20, Mercedes);

	routine(me);
	return (0);
}
