#ifndef CAR_H

# define CAR_H

# include <iostream>
# include <string>

class Car
{
	private:
		std::string	brand;
		std::string	model;
		std::string	colour;
		int			year;

	public:
		Car();
		Car(std::string brand, std::string model, std::string colour, int year);
		Car(const Car& car);
		~Car();
		Car&					operator=(const Car& car);
		void					repaint(std::string new_colour);
		friend std::ostream&	operator<<(std::ostream& os, const Car& car);
};

#endif
