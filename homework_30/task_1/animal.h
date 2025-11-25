#ifndef ANIMAL_H

# define ANIMAL_H

class	Animal
{
	protected:
		std::string	_name;
		std::string	_breed;
		std::string	_color;
		int			_age;
		double		_weight;
		double		_height;
	public:

		/*Animal ctor/dtor*/
		Animal();
		Animal(const Animal &other);
		Animal(Animal &&other) noexcept;
		Animal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		virtual ~Animal();

		/*Animal operators*/
		Animal			&operator=(const Animal &other);
		Animal			&operator=(Animal &&other) noexcept;

		/*Animal methods*/
		virtual void	sound() const = 0;
};

class	Lion : public Animal
{
	public:
		/*Lion ctor/dtor*/
		Lion();
		Lion(const Lion &other);
		Lion(Lion &&other) noexcept;
		Lion(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		~Lion() override;

		/*Lion operators*/
		Lion	&operator=(const Lion &other);
		Lion	&operator=(Lion &&other) noexcept;

		/*Lion methods*/
		void	sound() const override;
		void	run() const;
		void	jump() const;
};

#endif