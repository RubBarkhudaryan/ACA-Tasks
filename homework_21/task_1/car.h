#ifndef CAR_H

# define CAR_H

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
		/*Car ctor/dtor*/
		Car();
		Car(std::string brand, std::string model, std::string colour, Engine engine,
			std::string type, std::string vin, double price, int year,
			int kilometrage, int seats_count, int fuel_capacity);
		Car(const Car& car);
		~Car();

		/*Car operators*/
		Car&	operator=(const Car& car);

		/*Car methods*/
		void	printInfo();
		void	startEngine();
		void	drive(int distance);
		void	stopEngine();
		void	repaint(const std::string& new_colour);
		void	refuel(int amount);
};

#endif