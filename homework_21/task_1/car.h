#ifndef CAR_H

# define CAR_H

#include "./parking.h"
#include "./engine.h"

class Car
{
	private:
		std::string	brand;
		std::string	model;
		std::string	colour;
		std::string	type;
		std::string	vin;
		Parking		*lot;
		Engine		engine;
		double		price;
		int			year;
		int			kilometrage;
		int			seats_count;
		int			fuel_capacity;
		int			current_fuel;
		bool		engine_on;
		bool		is_parked;

	public:
		/*Car ctor/dtor*/
		Car();
		Car(std::string brand, std::string model, std::string colour, Parking *lot, Engine engine,
			std::string type, std::string vin, double price, int year,
			int kilometrage, int seats_count, int fuel_capacity, bool is_parked);
		Car(const Car& car);
		~Car();

		/*Car operators*/
		Car&		operator=(const Car& car);

		/*Car methods*/
		void		printInfo();
		void		startEngine();
		void		drive(int distance);
		void		stopEngine();
		void		repaint(const std::string& new_colour);
		void		refuel(int amount);
		void		park(bool status);
		void		retrieve(bool status);
		Parking*	getLot();
		void		setParking(Parking* lot);
		bool		isParked();
};

#endif