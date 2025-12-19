#ifndef CAR_H

# define CAR_H

class	Car
{
	private:
		std::string	brand;
		std::string	model;
		std::size_t	year;

	public:
		Car();
		Car(const std::string& brand, const std::string& model, std::size_t year);
		virtual ~Car();
};

class	BMW : public Car
{
	public:
		BMW();
		BMW(const std::string& model, std::size_t year);
		~BMW() override;
};

#endif