#ifndef PARKING_H

# define PARKING_H

class Parking
{
	private:
		std::string	location = "";
		std::size_t	capacity = 0;
		std::size_t	unavailable_count = 0;
		std::size_t	*parking = nullptr;

	public:
		/*Parking ctor/dtor*/
		Parking() = delete;
		Parking(const std::string& location, std::size_t capacity);
		Parking(const Parking& other);
		~Parking();

		/*Parking operator*/
		Parking&	operator=(const Parking& other);

		/*Parking methods*/
		bool		park();
		bool		retrieve();
};

#endif