#ifndef DRIVER_H

# define DRIVER_H

class Driver
{
	private:
		std::string	name;
		std::string	surname;
		bool		gender;
		int			age;
		Car			car;

	public:
		/*Driver ctor/dtor*/
		Driver();
		Driver(std::string name, std::string surname, bool gender, int age, Car car);
		~Driver();

		/*Driver methods*/
		void	printInfo();
		Car		getCar();
};
#endif