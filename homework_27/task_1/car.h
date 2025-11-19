#ifndef CAR_H

# define CAR_H

#include "./engine.h"

class Car
{
	protected:
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
		Car(const std::string& brand, const std::string& model, const std::string& colour, Engine engine,
			const std::string& type, const std::string& vin, double price, int year,
			int kilometrage, int seats_count, int fuel_capacity);
		Car(const Car& car);
		virtual			~Car();

		/*Car operators*/
		Car&			operator=(const Car& car);

		/*Car methods*/
		virtual void	printInfo();
		void			startEngine();
		void			drive(int distance);
		void			stopEngine();
		void			repaint(const std::string& new_colour);
		void			refuel(int amount);
};

class Mercedes : public Car
{
	public:
		/*Mercedes ctor/dtor*/
		Mercedes();
		Mercedes(const std::string& model, const std::string& colour, Engine engine,
				const std::string& type, const std::string& vin, double price, int year,
				int kilometrage, int seats_count, int fuel_capacity);
		Mercedes(const Mercedes& mercedes);
		~Mercedes() override;

		/*Mercedes operators*/
		Mercedes&	operator=(const Mercedes& mercedes);

		/*Mercedes methods*/
		void	printInfo();
};

class BMW : public Car
{
	public:
		/*BMW ctor/dtor*/
		BMW();
		BMW(const std::string& model, const std::string& colour, Engine engine,
			const std::string& type, const std::string& vin, double price, int year,
			int kilometrage, int seats_count, int fuel_capacity);
		BMW(const BMW& bmw);
		~BMW() override;

		/*BMW operators*/
		BMW&	operator=(const BMW& bmw);

		/*BMW methods*/
		void	printInfo();
};

class Audi : public Car
{
	public:
		/*Audi ctor/dtor*/
		Audi();
		Audi(const std::string& model, const std::string& colour, Engine engine,
			const std::string& type, const std::string& vin, double price, int year,
			int kilometrage, int seats_count, int fuel_capacity);
		Audi(const Audi& audi);
		~Audi() override;

		/*Audi operators*/
		Audi&	operator=(const Audi& audi);

		/*Audi methods*/
		void	printInfo();
};

#endif	// CAR_H